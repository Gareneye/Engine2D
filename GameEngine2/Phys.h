#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
using namespace sf;

#include "CollisionSystem.h"
#include "DynamicBody.h"
#include "Level.h"

//DEBUG
#include <iostream>
using namespace std;

class Phys
{
public:
	Phys();
	~Phys();

	void addDynBody(DynamicBody &body);
	void addStatBody(DynamicBody & body);
	void addLevel(Level * newLevel);
	void update(double dt);

	int dGetCollisionCheckCount()
	{
		return dCollisionCheckCount;
	}
	int dGetCollisionCount() {
		return dCollisionCount;
	}

private:
	CollisionSystem collision;

	vector<DynamicBody *> dynBodies;
	vector<DynamicBody *> statBodies;
	Level *level;

	void applyPhys(double dt);
	void checkCollisions();

	int dCollisionCheckCount;
	int dCollisionCount;
};

