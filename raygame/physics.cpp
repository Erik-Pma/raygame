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
}
rigidBody::rigidBody() 
{

}

void rigidBody::applyForce(Vector2 gravity, float timeStep) 
{

}

void rigidBody::applyForce(Vector2 force) 
{

}