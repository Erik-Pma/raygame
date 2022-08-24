#include "baseGame.h"
#include "raylib.h"

baseGame::baseGame()
{
	accumatedFixedTime = 0.0f;
	targetFixedStep = 1.0f / 30.0;
}
void baseGame::addObject(rigidBody object) 
{
	Objects.push_back(object);
}

void baseGame::init() 
{
	int screenWidth = 1600;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//TODO: add any other things to initalition 
}

void baseGame::update() 
{
	//regular game update
	accumatedFixedTime += GetFrameTime();

	//TODO: all update data goes here

}
void baseGame::fixedUpdate() 
{
	accumatedFixedTime -= targetFixedStep;
	//TODO: physics updates in here;
}
bool baseGame::shouldFixedUpdate()
{
	return accumatedFixedTime >= targetFixedStep;
}
