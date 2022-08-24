#pragma once
#include "physics.h"
class sphere: public rigidBody
{
	public:
		sphere(Vector2 position, Vector2 velocity, float mass, float radius, Color color);
		
		virtual void draw();
		float getRadius() { return m_radius; }
		Color getColor() { return m_color; }

protected:
	float m_radius;
	Color m_color;
};

