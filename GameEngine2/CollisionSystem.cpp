#include "CollisionSystem.h"

#include <iostream>

// Sprawdzanie czy jest kolizja
bool CollisionSystem::isCollide(PhysBody &a, PhysBody &b)
{
	if (a.getMax().x <= b.getMin().x || a.getMin().x >= b.getMax().x) return false;
	if (a.getMax().y <= b.getMin().y || a.getMin().y >= b.getMax().y) return false;

	return true;
}

// Rozwiazywanie kolizji
void CollisionSystem::resDynVsDyn(DynamicBody * a, DynamicBody * b)
{
	float px = (a->getMin().x + a->getSize().x / 2) - (b->getMin().x + b->getSize().x / 2);
	float py = (a->getMin().y + a->getSize().y / 2) - (b->getMin().y + b->getSize().y / 2);

	float aMassRatio = a->getMass() / b->getMass() / 2;
	float bMassRatio = b->getMass() / a->getMass() / 2;

	float avRefl = (a->getRefl() + b->getRefl()) / 2;

	if (abs(px) >= abs(py))
	{
		float diffX = ((a->getSize().x + b->getSize().x) - (abs(a->getMin().x - b->getMin().x) + abs(a->getMax().x - b->getMax().x))) / 2;

		if (px >= 0)
		{
			a->move(Vector2f(diffX * aMassRatio, 0));
			b->move(Vector2f(-diffX * bMassRatio, 0));

			a->changeSpeed(Vector2f(diffX * aMassRatio + (aMassRatio*avRefl), 0));
			b->changeSpeed(Vector2f(-diffX * bMassRatio - (bMassRatio*avRefl), 0));

			//b->collideLeft(a);
			//a->collideRight(b);

			/*
			 ____     ____
			| a  |<->|  b |
			|____|   |____|
			
			*/
		}
		else
		{
			a->move(Vector2f(-diffX * aMassRatio, 0));
			b->move(Vector2f(diffX * bMassRatio, 0));

			a->changeSpeed(Vector2f(-diffX * aMassRatio - (aMassRatio*avRefl), 0));
			b->changeSpeed(Vector2f(diffX * bMassRatio + (bMassRatio*avRefl), 0));

			//a->collideLeft(b);
			//b->collideRight(a);

			/*
			 ____     ____
			| b  |<->|  a |
			|____|   |____|

			*/
		}

	}
	else {
		float diffY = ((a->getSize().y + b->getSize().y) - (abs(a->getMin().y - b->getMin().y) + abs(a->getMax().y - b->getMax().y))) / 2;

		if (py >= 0)
		{
			a->move(Vector2f(0, diffY * aMassRatio));
			b->move(Vector2f(0, -diffY * bMassRatio));

			a->changeSpeed(Vector2f(0, diffY * aMassRatio + (aMassRatio*avRefl)));
			b->changeSpeed(Vector2f(0, -diffY * bMassRatio - (bMassRatio*avRefl)));

			b->reduceSpeed(Vector2f((a->getFriction() + b->getFriction()) / 2 * b->getSpeed().x, 0));

			//b->collideBottom(a);
			//a->collideTop(b);

			/*
			 ____  
			| b  |
			|____|
			 ____
			| a  |
			|____|

			*/
		}
		else
		{
			a->move(Vector2f(0, -diffY * aMassRatio));
			b->move(Vector2f(0, diffY * bMassRatio));

			a->changeSpeed(Vector2f(0, -diffY * aMassRatio - (aMassRatio*avRefl)));
			b->changeSpeed(Vector2f(0, diffY * bMassRatio + (bMassRatio*avRefl)));

			a->reduceSpeed(Vector2f((a->getFriction() + b->getFriction()) / 2 * a->getSpeed().x, 0));

			//a->collideBottom(b);
			//b->collideTop(a);

			/*
			 ____
			| a  |
			|____|
			 ____
			| b  |
			|____|

			*/
		}

	}
}

// To bedzie do Dynamiczny vs Static
void CollisionSystem::resDynVsStat(DynamicBody * a, PhysBody * b)
{
	float px = (a->getMin().x + a->getSize().x / 2) - (b->getMin().x + b->getSize().x / 2);
	float py = (a->getMin().y + a->getSize().y / 2) - (b->getMin().y + b->getSize().y / 2);

	if (abs(px) >= abs(py))
	{
		float diffX = ((a->getSize().x + b->getSize().x) - (abs(a->getMin().x - b->getMin().x) + abs(a->getMax().x - b->getMax().x))) / 2;

		if (px >= 0)
		{
			a->move(Vector2f(diffX, 0));
			a->changeSpeed(Vector2f(diffX, 0));
		}
		else
		{
			a->move(Vector2f(-diffX, 0));
			a->changeSpeed(Vector2f(-diffX, 0));
		}
	}
	else {
		float diffY = ((a->getSize().y + b->getSize().y) - (abs(a->getMin().y - b->getMin().y) + abs(a->getMax().y - b->getMax().y))) / 2;

		if (py >= 0)
		{
			a->move(Vector2f(0, diffY));
			a->changeSpeed(Vector2f(0, diffY));
		}
		else
		{
			a->move(Vector2f(0, -diffY));
			a->changeSpeed(Vector2f(0, -diffY));

			a->reduceSpeed(Vector2f((a->getFriction()) * a->getSpeed().x, 0));
		}

	}
}