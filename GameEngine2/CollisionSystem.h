#pragma once

#include "PhysBody.h"
#include "DynamicBody.h"

class CollisionSystem
{
public:
	bool isCollide(PhysBody &a, PhysBody &b);
	void resDynVsDyn(DynamicBody * a, DynamicBody * b);
	void resDynVsStat(DynamicBody * a, PhysBody * b);
};

