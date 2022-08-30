#pragma once
#include "raylib.h"

#include "shapes.h";

class physicsObject
{
public:
	physicsObject();
	Vector2 position;
	Vector2 velocity;

	Vector2 force;

	shape collider;

	float mass;
	float drag;

	bool isStatic;
	bool useGravity;

	
	void applyForce(Vector2 gravity, float timeStep);
	void applyForce(Vector2 force);

	Vector2 getPosition() { return position; }
	Vector2 getVelocity() { return velocity; }
	float getMass() { return mass; }
	//TODO: Add shape/collider

	void draw();
	//TODO: add function for applying/getting forces
	void tickPhys(float delta);
	/*
	float resolveCollision(Vector2 posA, Vector2 velA, float massA, Vector2 posB, Vector2 velB, float massB, float elasticity, const Vector2& normal);

	void resolvePhysBodies(physicsObject& lhs, physicsObject& rhs, float elasticity, const Vector2);
	*/
};



