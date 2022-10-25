#include "physics.h"
#include "raymath.h"
#include<iostream>

physicsObject::physicsObject()
{
	position = { 0,0 };
	velocity = { 0,0 };

	drag = 1.0f;
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
	case shapeType::AABB:
		DrawRectangle(position.x, position.y, collider.aabbData.size,collider.aabbData.size, GREEN);
		break;
	case shapeType::PLANE:
	
	DrawLine(position.x, position.y, position.x + collider.aabbData.size, position.y, BLACK);
	
	}
}

void physicsObject::tickPhys(float delta)
{
}


/// <summary>
/// applys force to a physic object
/// </summary>
/// <param name="gravity">the force of gravity</param>
/// <param name="timeStep"> the time step used in it</param>
void physicsObject::applyForce(Vector2 gravity, float timeStep)
{
	//see if item is static
	if (!isStatic) {
		switch (collider.type)
		{
		case shapeType::CIRCLE:

			break;
		}
		velocity = { velocity.x + (gravity.x * mass * timeStep),velocity.y + (gravity.y * mass * timeStep) };
	}
}
/// <summary>
/// applys fprce to a phys is object
/// </summary>
/// <param name="force">the force you add toa n object</param>
void physicsObject::applyForce(Vector2 force)
{
	if (!isStatic) {
		//std::cout << "force push" << std::endl;
		velocity = { velocity.x + force.x,velocity.y + force.y };
	}
}