#include "baseGame.h"
#include "raylib.h"

baseGame::baseGame()
{
	accumatedFixedTime = 0.0f;
	targetFixedStep = 1.0f / 30.0;
}/*
void baseGame::addObject(rigidBody object) 
{
	Objects.push_back(object);
}*/

void baseGame::init() 
{
	int screenWidth = 1600;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	sphere ball = sphere(Vector2{ 0,0 }, Vector2{ 0,0 }, 1, 2, MAROON);
	SetTargetFPS(60);
	//TODO: add any other things to initalition 
	//Objects.push_back(ball);
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
void baseGame::draw() {
/*
	for (size_t i = 0; i < Objects.size(); i++)
	{
		Objects.front().draw();
	}*/
}
