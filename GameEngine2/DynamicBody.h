#pragma once

#include "PhysBody.h"	
#include <iostream>

class DynamicBody : public PhysBody
{
public:
	DynamicBody();
	virtual ~DynamicBody();

	virtual Vector2f getPosition() = 0;
	virtual void setPosition(Vector2f) = 0;
	virtual Vector2f getSize() = 0;

	Vector2f getSpeed();
	float getMass();
	float getFriction();
	float getRefl();

	void setSpeed(Vector2f);
	void changeSpeed(Vector2f);
	void reduceSpeed(Vector2f);

private:
	Vector2f speed;

	float mass;
	float reflectivity;
	float friction;
};

