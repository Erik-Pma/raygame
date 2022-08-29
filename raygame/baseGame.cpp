#include "baseGame.h"
#include "raylib.h"
#include <iostream>
#include <unordered_map>
#include "enumUtill.h"
// a  type alias to make this reable
using collisionPair = uint8_t;
// a type alias for a function sig for a collision func
using collisionFunc = bool(*)(const Vector2&, const shape&, const Vector2&, const shape&);
//a type alias for a map <collision pair, collision func>
using collisionMap = std::unordered_map<collisionPair, collisionFunc>;

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
				std::cout << "I did a thing" << std::endl;
				//TODO: DO things
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
