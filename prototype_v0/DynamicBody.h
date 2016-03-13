#pragma once

#include "PhysBody.h"

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

	void setSpeed(Vector2f);

	void setSpeedX(float);
	void setSpeedY(float);

	void changeSpeed(Vector2f);
	void reduceSpeed(Vector2f);

	float getRefl();

	// sprawdzanie czy jest na ziemi nie powinno sprawdzac czy speedY jest 0, tylko miec zmienna wlasna
	void setOnGround(bool newSet = true);
	bool isOnGround();

private:
	Vector2f speed;
	float mass;
	bool onGround;
	// 0 <=> 1f
	float reflectivity;
};

