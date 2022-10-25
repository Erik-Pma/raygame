#pragma once
#include "raylib.h"
#include "physics.h"
#include <vector>

class baseGame
{
protected:
	void virtual onInit() { }
	void virtual onTick() { }
	void virtual onTickPhys() { }
	void virtual onDraw() const { }
	void virtual onExit() { }
	
	bool useGravity;
	bool usingWrapping;

public:
	baseGame();

	std::vector<physicsObject> physObject;


	float targetFixedStep;
	float accumatedFixedTime;
	
	void init();
	void update();
	void fixedUpdate();
	
	void draw();

	bool shouldFixedUpdate();
};

