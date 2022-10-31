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
	Vector2 posACentered = { posA.x + aabbA.size / 2,posA.y + aabbA.size / 2 };
	
	Vector2 posBCentered = { posB.x + aabbB.size / 2,posB.y + aabbB.size / 2 };
	float left = posBCentered.x - (posACentered.x + aabbA.size);
	float top = (posBCentered.y + aabbB.size) - posACentered.y;
	float right = (posBCentered.x + aabbB.size) - posACentered.x;
	float bottom = posBCentered.y - (posACentered.y + aabbA.size);
	if (left > 0|| right < 0 || top < 0 || bottom > 0)
	{
		
		return false;
	}
	std::cout << "you are coliding" << std::endl;
	return true;
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
bool checkCirclePlane(const Vector2& posA, circle circle, const Vector2& posB, aabb plane)
{
	
	return checkCircleAabb(posA, circle, posB, plane);
	
}
bool checkCirclePlane(const Vector2& posA, const shape& circleA, const Vector2& posB, const shape& planeB)
{
	return checkCirclePlane(posA, circleA.circleData, posB, planeB.aabbData);
}
bool checkAabbPlane(const Vector2& posA, aabb Aabb, const Vector2& posB, aabb plane)
{
	return false;
}
bool checkAabbPlane(const Vector2& posA, const shape& circleA, const Vector2& posB, const shape& planeB)
{
	return checkCirclePlane(posA, circleA.circleData, posB, planeB.aabbData);
}
bool checkPlanePlane(const Vector2& posA, const shape& AabbA, const Vector2& posB, const shape& planeB)
{
	return false;
}
void setVelocity(const Vector2& velo, circle shape)
{
	shape.vx = velo.x;
	shape.vy = velo.y;
}
void setVelocity(const Vector2& velo, aabb shape) 
{
	shape.vx = velo.x;
	shape.vy = velo.y;
}

void setVelocity(const Vector2& velo, const shape& shape) 
{
	switch (shape.type)
	{
	case shapeType::CIRCLE:
		setVelocity(velo,shape.circleData);
		break;
	case shapeType::AABB:
		setVelocity(velo, shape.aabbData);
	}
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
	


	return Vector2Normalize(Vector2Subtract(posA, posB));
}
/// <summary>
/// depens the aabb
/// </summary>
/// <param name="posA"></param>
/// <param name="shapeA"></param>
/// <param name="posB"></param>
/// <param name="shapeB"></param>
/// <param name="pen"></param>
/// <returns></returns>
Vector2 depenatrateAabbAabb(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB, float& pen)
{
	Vector2 posValue = {0,0};

	Vector2 posACentered = {posA.x + shapeA.aabbData.size/2,posA.y + shapeA.aabbData.size/2};
	Vector2 posBCentered = { posB.x + shapeB.aabbData.size / 2,posB.y + shapeB.aabbData.size / 2 };

	Vector2 distance = calculateAabbDistanceTo(posACentered,shapeA,posBCentered,shapeB);
	
	
	
	
	 
	pen = (shapeA.aabbData.size * pow(2,.5f) + shapeB.aabbData.size * pow(2,.5f)) - Vector2Distance(posACentered,posBCentered);
	

	
	


	return Vector2Normalize(Vector2Subtract(posBCentered, posACentered));
	
	
}
Vector2 depenatrateCircleAabb(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB, float& pen)
{
	Vector2 posBCentered = { posB.x + shapeB.aabbData.size / 2,posB.y + shapeB.aabbData.size / 2 };
	float sizeAdded = shapeA.circleData.radius + shapeB.aabbData.size;
	pen = sizeAdded - Vector2Distance(posA,posBCentered);
	std::cout << "depened" << std::endl;

	return Vector2Normalize(Vector2Subtract(posA, posBCentered));
}
Vector2 depenatratePlanePlane(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB, float& pen)
{
	return Vector2();
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

	

	float impulsMagnutude = Vector2DotProduct(Vector2Scale(relativeVelocity, -(1.f + elasticity)), normal);
	impulsMagnutude /= Vector2DotProduct(normal, Vector2Scale(normal, 1 / massA + massB)) / 2;
	
	
	return impulsMagnutude ;

	


	
}
/// <summary>
/// 
/// </summary>
/// <param name="posA"></param>
/// <param name="shapeA"></param>
/// <param name="posB"></param>
/// <param name="shapeB"></param>
/// <returns></returns>
Vector2 calculateAabbDistanceTo(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB)
{
	Vector2 distance = {0,0};

	if(posA.x <= posB.x)
	{

		distance.x = posB.x - (posA.x + shapeA.aabbData.size);
		std::cout << distance.x << std::endl;
	}
	else if(posA.x > posB.x)
	{
		distance.x = posA.x - (posB.x + shapeB.aabbData.size);
		std::cout << distance.x << std::endl;
	}
	if (posA.y <= posB.y) 
	{
		distance.y = posB.y - (posA.y + shapeA.aabbData.size);
		std::cout << distance.y << std::endl;
	}
	else if (posB.y > posA.y) 
	{
		distance.y = posA.y - (posB.y + shapeB.aabbData.size);
		std::cout << distance.y << std::endl;
	}



	return distance;
}




