#pragma once

#include<stdint.h>
#include "raylib.h"
struct circle
{
	//TODO: local offset
	float radius;
};
struct aabb
{
	float size;
	
};

enum class shapeType : uint8_t
{
	NONE = 0,
	CIRCLE =1<<0,
	AABB =1 << 1
};

struct shape
{
	//an enum for type of shape
	shapeType type;
	//storage* for those shape types
	union
	{
		circle circleData;
		aabb aabbData;
	};
};

bool checkCircleCircle(const Vector2& posA, circle circleA, const Vector2& posB, circle circleB);

//wrapper for circle-circle collision

bool checkCircleCircle(const Vector2& posA, const shape & circleA, const Vector2& posB, const shape & circleB);

bool checkAabbAabb(const Vector2& posA, aabb aabbA, const Vector2& posB, aabb aabbB);

bool checkAabbAabb(const Vector2& posA, const shape & aabbA, const Vector2& posB, const shape & aabbB);

bool checkCircleAabb(const Vector2& posA, circle Circle, const Vector2& posB, aabb Aabb);


bool checkCircleAabb(const Vector2& posA, const shape& Circle, const Vector2& posB, const shape& Aabb);

Vector2 depenatrateCircleCircle(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB, float& pen);

Vector2 depenatrateAabbAabb(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB, float& pen);

Vector2 depenatrateCircleAabb(const Vector2& posA, const shape& shapeA, const Vector2& posB, const shape& shapeB, float& pen);
float resolveCollision(Vector2 posA, Vector2 velA, float massA, Vector2 posB, Vector2 velB, float massB, float elasticity, const Vector2& normal);

	