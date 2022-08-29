#pragma once
#include "raylib.h"
#include "physics.h"
#include <vector>
#include "sphere.h"
class baseGame
{
protected:
	bool useGravity;
	bool usingWrapping;

public:
	baseGame();

	std::vector<physicsObject> physObject;


	float targetFixedStep;
	float accumatedFixedTime;
	/*
	std::list<rigidBody> Objects;
	void addObject(rigidBody object);
	*/
	void init();
	void update();
	void fixedUpdate();
	
	void draw();

	bool shouldFixedUpdate();
};

