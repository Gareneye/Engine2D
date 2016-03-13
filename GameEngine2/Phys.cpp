#include "Phys.h"

#include <iostream>

float g = 0.26;
float friction = 0.191;
int precision = 1;

Phys::Phys(){}
Phys::~Phys(){}

void Phys::addDynBody(DynamicBody & body)
{
	dynBodies.push_back(&body);
}

void Phys::addStatBody(DynamicBody & body)
{
	statBodies.push_back(&body);
}

void Phys::addLevel(Level * newLevel)
{
	level = newLevel;
}

void Phys::update(double dt)
{
	applyPhys(dt);

	for (int i = 0; i <= precision; i++)
		checkCollisions();
}

/*--------------------
   OBLICZANIE FIZYKI
--------------------*/
void Phys::applyPhys(double dt)
{
	for (auto i = dynBodies.begin(); i < dynBodies.end(); i++)
	{
		(*i)->changeSpeed(Vector2f(0, g));
		(*i)->move((*i)->getSpeed());
	}
}

/*------------
	KOLIZJE
------------*/

// Sprawdzanie kolizji
void Phys::checkCollisions()
{
	dCollisionCheckCount = 0;
	dCollisionCount = 0;

	// Obiekty dynamiczne ze soba
	for (auto i = dynBodies.begin(); i < dynBodies.end(); i++)
		for (auto j = i + 1; j < dynBodies.end(); j++)
		{
			PhysBody *a = *i;
			PhysBody *b = *j;

			if (collision.isCollide(*a, *b))
			{
				collision.resDynVsDyn(*i, *j);
				dCollisionCount++;
			}

			dCollisionCheckCount++;
		}

		

	// TODO z mapa
	for (auto i = dynBodies.begin(); i < dynBodies.end(); i++)
		for (auto j = statBodies.begin(); j < statBodies.end(); j++)
		{
			PhysBody *a = *i;
			PhysBody *b = *j;

			if (collision.isCollide(*a, *b))
			{
				collision.resDynVsStat(*i, *j);
				dCollisionCount++;
			}


			dCollisionCheckCount++;
		}
}


