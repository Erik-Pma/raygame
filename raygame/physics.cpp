#include "physics.h"
#include "raymath.h"

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
	}
}

void physicsObject::tickPhys(float delta)
{
}
/*
float physicsObject::resolveCollision(Vector2 posA, Vector2 velA, float massA, Vector2 posB, Vector2 velB, float massB, float elasticity, const Vector2& normal)
{
	Vector2 relativeVelocity = Vector2Subtract(velA, velB);

	float impulsMagnutude = 0;

	return impulsMagnutude;
}

void physicsObject::resolvePhysBodies(physicsObject& lhs, physicsObject& rhs, float elasticity, const Vector2 normal)
{
	float impulseMag = resolveCollision(lhs.position,lhs.velocity,lhs.mass,rhs.position,rhs.velocity,rhs.mass,elasticity,normal);

	Vector2 impulse = Vector2Scale(normal, impulseMag);

	lhs.applyForce(impulse);
}

*/
void physicsObject::applyForce(Vector2 gravity, float timeStep)
{
	switch (collider.type)
	{
	case shapeType::CIRCLE:
		
		break;
	}
	velocity = {velocity.x+(gravity.x * mass * timeStep),velocity.y+(gravity.y * mass * timeStep)};
}

void physicsObject::applyForce(Vector2 force)
{
	velocity = {velocity.x + force.x,velocity.y+ force.y};
}