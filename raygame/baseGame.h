#pragma once
#include "raylib.h"
#include "physics.h"
#include <list>
class baseGame
{
public:
	baseGame();

	float targetFixedStep;
	float accumatedFixedTime;
	
	std::list<rigidBody> Objects;
	void addObject(rigidBody object);
	
	void init();
	void update();
	void fixedUpdate();
	

	bool shouldFixedUpdate();
};

