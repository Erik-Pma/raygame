#include "shapes.h"
#include <iostream>
#include "raymath.h"
bool checkCircleCircle(const Vector2& posA, circle circleA, const Vector2& posB, circle circleB) 
{
	//retrieve the sum of their radii
	//calculate the distance between ther center
	//if distance is less than sum, they're in collition

	
	if (Vector2Distance(posA, posB) < circleA.radius + circleB.radius)
	{
		//std::cout << "you are coliding" << std::endl;
		return true;
	}
	return false;
}

bool checkCircleCircle(const Vector2& posA, const shape& circleA, const Vector2& posB, const shape& circleB)
{
	return checkCircleCircle(posA, circleA.circleData, posB, circleB.circleData);
}
