#pragma once
#include "raylib.h"
enum ShapeType {
	PLANE = 0,
	SPHERE,
	BOX
};

class physicsObject
{
public:
	physicsObject();
	Vector2 position;
	Vector2 velocity;

	float mass;
	bool isStatic;
	bool useGravity;
	//TODO: Add shape/collider

	void draw();
	//TODO: add function for applying/getting forces
};
class rigidBody: public physicsObject
{
public:
	rigidBody();
	void applyForce(Vector2 gravity, float timeStep);
	void applyForce(Vector2 force);

	Vector2 getPosition() { return position; }
	Vector2 getVelocity() { return velocity; }
	float getMass() { return mass; }

};


