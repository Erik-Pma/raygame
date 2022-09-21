#include "baseGame.h"
#include "raylib.h"
#include <iostream>
#include <unordered_map>
#include "enumUtill.h"
#include "raymath.h"
// a  type alias to make this reable
using collisionPair = uint8_t;
// a type alias for a function sig for a collision func
using collisionFunc = bool(*)(const Vector2&, const shape&, const Vector2&, const shape&);
//a type alias for a map <collision pair, collision func>
using collisionMap = std::unordered_map<collisionPair, collisionFunc>;

using depenatrationFunction = Vector2(*)(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB, float& pen);
using depentrationMap = std::unordered_map<collisionPair, depenatrationFunction>;

depentrationMap depenMap;
collisionMap detectionMap;

baseGame::baseGame()
{
	accumatedFixedTime = 0.0f;
	targetFixedStep = 1.0f / 30.0;
	usingWrapping = false;
	useGravity = false;


}/*
void baseGame::addObject(rigidBody object) 
{
	Objects.push_back(object);
}*/

void baseGame::init() 
{
	int screenWidth = 1600;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	detectionMap[static_cast<uint8_t>(shapeType::CIRCLE | shapeType::CIRCLE)] = checkCircleCircle;
	detectionMap[static_cast<uint8_t>(shapeType::AABB | shapeType::AABB)] = checkAabbAabb;
	detectionMap[static_cast<uint8_t>(shapeType::CIRCLE | shapeType::AABB)] = checkCircleAabb;

	depenMap [static_cast<uint8_t>(shapeType::CIRCLE | shapeType::CIRCLE)]= depenatrateCircleCircle;
	depenMap [static_cast<uint8_t>(shapeType::AABB | shapeType::AABB)]= depenatrateAabbAabb;
	SetTargetFPS(60);
	//TODO: add any other things to initalition 
	//Objects.push_back(ball);
	onInit();
}

void baseGame::update() 
{
	//std::cout << "this is update" << std::endl;
	//regular game update
	accumatedFixedTime += GetFrameTime();

	//TODO: all update data goes here
	
	onTick();
}
void baseGame::fixedUpdate() 
{
	accumatedFixedTime -= targetFixedStep;
	//TODO: physics updates in here;
	for (physicsObject& i : physObject) 
	{
		Vector2 dragForce = Vector2Scale( Vector2Multiply(i.velocity,i.velocity), 0.5 * i.drag);

		// totally not fake gravity and drag
		i.applyForce({ 0,1.862f },1);
		i.applyForce(Vector2Negate (dragForce));
		i.position = Vector2Add(i.position,i.velocity);
		// screen wrapping
		if (i.position.x > 1600) {
			std::cout << "0 overlapping right side" << std::endl;
			i.position.x = 0 + i.collider.circleData.radius;
		}
		if (i.position.x < 0) {
			std::cout << "1 overlapping left side" << std::endl;
			i.position.x = 1600 - i.collider.circleData.radius;
		}
		if (i.position.y > 900) {
			std::cout << "2 overlapping top side" << std::endl;
			i.position.y = 0 + i.collider.circleData.radius;
		}
		if (i.position.y < 0) {
			std::cout << "3 overlapping bottom side" << std::endl;
			i.position.y = 900 - i.collider.circleData.radius;
		}
	}
	//intergratephysics

	//test for collision
	for (physicsObject& i : physObject)
	{
		for (physicsObject& j : physObject) 
		{
			if (&i == &j) { continue; }
			physicsObject* lhs = &i;
			physicsObject* rhs = &j;

			if (static_cast<uint8_t>(i.collider.type) > static_cast<uint8_t>(j.collider.type))
			{
				lhs = &j;
				rhs = &i;
			}

			collisionPair pair = static_cast<collisionPair>(lhs->collider.type | rhs->collider.type);
			bool isCollideing = detectionMap[pair](lhs->position, lhs->collider, rhs->position, rhs->collider);

			if (isCollideing) 
			{
				//std::cout << "I did a thing" << std::endl;
				//TODO: DO things
				float pen = 0;
				Vector2 norm = depenMap[pair](lhs->position, lhs->collider, rhs->position, rhs->collider, pen);
				lhs->position = Vector2Add (lhs->getPosition(), Vector2Scale(norm, pen/2));

				rhs->position = Vector2Add(rhs->getPosition(), Vector2Scale(norm,-pen/2));
				
				
			}
		}
	}

	onTickPhys();
}
bool baseGame::shouldFixedUpdate()
{
	return accumatedFixedTime >= targetFixedStep;
}
void baseGame::draw() {
	
	for (physicsObject& obj : physObject)
	{
		obj.draw();
	}
	onDraw();
}
