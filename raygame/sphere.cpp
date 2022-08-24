#include "sphere.h"
sphere::sphere(Vector2 b_position, Vector2 b_velocity, float b_mass, float radius, Color color) 
{
	position = b_position;
	velocity = b_velocity;
	mass = b_mass;
	m_radius = radius;
	m_color = color;
}

void sphere::draw()
{
	DrawCircleV(position, m_radius, m_color);
}
