#include "DynamicBody.h"



DynamicBody::DynamicBody()
{
	reflectivity = 0.0f;
	mass = 50.0f;
}


DynamicBody::~DynamicBody()
{
}

Vector2f DynamicBody::getSpeed()
{
	return speed;
}

void DynamicBody::setSpeed(Vector2f newSpeed)
{
	speed = newSpeed;
}

void DynamicBody::setSpeedX(float x)
{
	speed.x = x;
}

void DynamicBody::setSpeedY(float y)
{
	speed.y = y;
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

float DynamicBody::getRefl()
{
	return reflectivity;
}

void DynamicBody::setOnGround(bool newSet)
{
	speed.y = 0;
	//onGround = newSet;
}

bool DynamicBody::isOnGround()
{
	return (speed.y == 0 ? true : false);
	//return onGround;
}

float DynamicBody::getMass()
{
	return mass;
}
