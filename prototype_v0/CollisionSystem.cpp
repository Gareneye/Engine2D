#include "CollisionSystem.h"

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
			b->move(Vector2f(- diffX * bMassRatio, 0));

			a->changeSpeed(Vector2f(diffX * aMassRatio * avRefl, 0));
			b->changeSpeed(Vector2f(-diffX * bMassRatio * avRefl, 0));
		}
		else
		{
			a->move(Vector2f(-diffX * aMassRatio, 0));
			b->move(Vector2f(diffX * bMassRatio, 0));

			a->changeSpeed(Vector2f(-diffX * aMassRatio * avRefl, 0));
			b->changeSpeed(Vector2f(diffX * bMassRatio * avRefl, 0));
		}

	}
	else {
		float diffY = ((a->getSize().y + b->getSize().y) - (abs(a->getMin().y - b->getMin().y) + abs(a->getMax().y - b->getMax().y))) / 2;

		// INFO: Poki "on ground" bedzie opieral sie o speedY, to przekazywanie energii w pionie jest wylaczone

		if (py >= 0)
		{
			a->move(Vector2f(0, diffY * aMassRatio));
			b->move(Vector2f(0, -diffY * bMassRatio));

			a->changeSpeed(Vector2f(0, diffY * aMassRatio * avRefl));
			//b->changeSpeed(Vector2f(0, -diffY * bMassRatio * avRefl));

			b->setOnGround();
		}
		else
		{
			a->move(Vector2f(0, -diffY * aMassRatio));
			b->move(Vector2f(0, diffY * bMassRatio));

			//a->changeSpeed(Vector2f(0, -diffY * aMassRatio * avRefl));
			b->changeSpeed(Vector2f(0, diffY * bMassRatio * avRefl));

			a->setOnGround();
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
			a->move(Vector2f(diffX, 0));
		else
			a->move(Vector2f(-diffX, 0));
	}
	else {
		float diffY = ((a->getSize().y + b->getSize().y) - (abs(a->getMin().y - b->getMin().y) + abs(a->getMax().y - b->getMax().y))) / 2;

		if (py >= 0)
		{
			a->move(Vector2f(0, diffY));
			a->setSpeedY(0);
		}
		else
		{
			a->setOnGround();
			a->move(Vector2f(0, -diffY));
		}

	}
}