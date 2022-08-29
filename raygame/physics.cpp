#include "physics.h"

physicsObject::physicsObject() 
{
	position = { 0,0 };
	velocity = { 0,0 };

	mass = 1.0f;
	isStatic = false;
	useGravity = true;
}

void physicsObject::draw() 
{
	//this depends on shape
	switch (collider.type)
	{
	case shapeType::CIRCLE:
		DrawCircle(position.x, position.y, collider.circleData.radius, MAROON);
		break;
	}
}
rigidBody::rigidBody() 
{

}

void rigidBody::applyForce(Vector2 gravity, float timeStep)
{
	velocity = {velocity.x+(gravity.x * mass * timeStep),velocity.y+(gravity.y * mass * timeStep)};
}

void rigidBody::applyForce(Vector2 force) 
{
	velocity = {velocity.x + force.x,velocity.y+ force.y};
}