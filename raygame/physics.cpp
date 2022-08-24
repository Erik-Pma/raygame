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
	DrawCircleV(position, 2, MAROON);
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