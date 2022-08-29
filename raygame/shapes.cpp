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

bool checkAabbAabb(const Vector2& posA, aabb aabbA, const Vector2& posB, aabb aabbB)
{
	if (Vector2Distance(posA,posB) < (aabbA.size*sqrt(2)) + (aabbB.size*sqrt(2))) 
	{
		return true;
	}
	return false;
}

bool checkAabbAabb(const Vector2& posA, const shape& aabbA, const Vector2& posB, const shape& aabbB)
{
	return checkAabbAabb(posA, aabbA.aabbData,posB ,aabbB.aabbData);
}
