#include "demoGame.h"

#include <iostream>

#include "raylib.h"

void demoGame::onTick() 
{
	//left-click => spawn circle

	
	bool mb0 = IsMouseButtonPressed(0);

	if (mb0) 
	{
		std::cout << "mouse click" << std::endl;

		physObject.emplace_back();
		//make refrance to new object
		auto & babyPhys = physObject.back();
		Vector2 mousePos = GetMousePosition();
		babyPhys.position = { mousePos.x,mousePos.y };

		shape babyCircle;
		
		babyCircle.type = shapeType::CIRCLE;
		babyCircle.circleData.radius = 25.0f;
		babyPhys.collider = babyCircle;
	}
	

	
}