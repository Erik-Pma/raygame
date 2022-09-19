#include "shapes.h"
#include <iostream>
#include "raymath.h"
/// <summary>
/// check so see if the cicles are colliding
/// </summary>
/// <param name="posA"></param>
/// <param name="circleA"></param>
/// <param name="posB"></param>
/// <param name="circleB"></param>
/// <returns></returns>
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
/// <summary>
/// check to see if an aabb and a circle are colliding with eachother and returns a bool if they are
/// </summary>
/// <param name="posA">position of the circle</param>
/// <param name="Circle">the data of the cicle</param>
/// <param name="posB">the position of the aabb</param>
/// <param name="Aabb">the data of the aabb</param>
/// <returns>returns true if they are connected</returns>
bool checkCircleAabb(const Vector2& posA, circle Circle, const Vector2& posB, aabb Aabb)
{
	float testX = posA.x;
	float testY = posA.y;
	// check to see what side of the box you are on
	if (posA.x < posB.x)
	{
		testX = posB.x;
	}
	else if (posA.x > posB.x + Aabb.size)
	{
		testX = posB.x + Aabb.size;
	}
	if (posA.y < posB.y)
	{
		testY = posB.y;
	}
	else if (posA.y > posB.y + Aabb.size)
	{
		testY = posB.y + Aabb.size;
	}
	//check to see the distance the sphwew is away form the line
	float distX = posA.x - testX;
	float distY = posA.y - testY;
	float distance = sqrt((distX * distX) + (distY * distY));

	if (distance <= Circle.radius)
	{
		return true;
	}
	return false;
}
/// <summary>
/// check to see if an aabb and a circle are colliding with eachother and returns a bool if they are
/// </summary>
/// <param name="posA">the position of the first object</param>
/// <param name="Circle"> the circle of of the 2 objects</param>
/// <param name="posB">posision of the aabb</param>
/// <param name="Aabb"> theaabb out of the 2 obnects</param>
/// <returns>returns true if they are over lapping</returns>
bool checkCircleAabb(const Vector2& posA, const shape& Circle, const Vector2& posB, const shape& Aabb)
{
	return checkCircleAabb(posA, Circle.circleData,posB,Aabb.aabbData);
}
/// <summary>
/// how to move to circles that are colliding with each other
/// </summary>
/// <param name="posA">posision of the first circle</param>
/// <param name="shapeA"> what type of shape that is colliding even tho we know its a circle</param>
/// <param name="posB">posision of second circle</param>
/// <param name="shapeB">what type of shape that is colliding even tho we know its a circle</param>
/// <param name="pen">distance the 2 objects are penatrating</param>
/// <returns>vector2 to move both objects by</returns>
Vector2 depenatrateCircleCircle(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB,float&pen)
{
	float dist = Vector2Distance(posA, posB);
	float radiusSum = shapeA.circleData.radius + shapeB.circleData.radius;

	pen = radiusSum - dist;
	std::cout << "depen circle" << std::endl;


	return Vector2Normalize(Vector2Subtract(posA, posB));
}
Vector2 depenatrateAabbAabb(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB, float& pen)
{
	//float dist = Vector2Distance(posA, posB);
	

	return Vector2Normalize(Vector2Subtract(posA, posB));
}
/// <summary>
/// takes in the the values of 2 objects and caluclates the impulse force and returns it
/// </summary>
/// <param name="posA"> the position of object 1</param>
/// <param name="velA"> the velocity of object 1</param>
/// <param name="massA"> the mass of object 1</param>
/// <param name="posB">the position of object 2</param>
/// <param name="velB">the velocity of object 2</param>
/// <param name="massB">the mass of object 2</param>
/// <param name="elasticity">the elasticity of the interaction</param>
/// <param name="normal"> the normal vector of the interaction</param>
/// <returns>impulse force</returns>
float resolveCollision(Vector2 posA, Vector2 velA, float massA, Vector2 posB, Vector2 velB, float massB, float elasticity, const Vector2& normal)
{
	Vector2 relativeVelocity = Vector2Subtract(velA, velB);

	float impulsMagnutude = (2 * Vector2DotProduct(Vector2Subtract(velA,velB), normal))
		/(Vector2DotProduct(normal,normal)*((1/massA)+(1/massB)));

	return impulsMagnutude;
}




