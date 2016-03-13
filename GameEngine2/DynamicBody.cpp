#include "DynamicBody.h"



DynamicBody::DynamicBody()
{
	reflectivity = .9f;
	mass = 50.0f;
	friction = 0.191;
}


DynamicBody::~DynamicBody() {}


/* GETTERS */
float DynamicBody::getMass()
{
	return mass;
}


float DynamicBody::getFriction()
{
	return friction;
}

float DynamicBody::getRefl()
{
	return reflectivity;
}

Vector2f DynamicBody::getSpeed()
{
	return speed;
}


/* SETTERS */
void DynamicBody::setSpeed(Vector2f newSpeed)
{
	speed = newSpeed;
}

void DynamicBody::changeSpeed(Vector2f diff)
{
	speed += diff;
}

void DynamicBody::reduceSpeed(Vector2f diff)
{

	if (speed.x > 0)
	{
		speed.x -= diff.x;

		if (speed.x < 0)
			speed.x = 0;
	}
	else if (speed.x < 0)
	{
		speed.x -= diff.x;
		if (speed.x > 0)
			speed.x = 0;
	}

	if (speed.y > 0)
	{
		speed.y -= diff.y;

		if (speed.y < 0)
			speed.y = 0;
	}
	else if (speed.y < 0)
	{
		speed.y += diff.y;
		if (speed.y > 0)
			speed.y = 0;
	}
}

