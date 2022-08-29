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
	float hieght;
	float width;
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