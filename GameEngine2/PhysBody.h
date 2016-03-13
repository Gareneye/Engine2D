#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;

class PhysBody
{
public:
	PhysBody();
	virtual ~PhysBody();

	/* POSITION AND SIZE */
	virtual Vector2f getPosition() = 0;
	virtual void setPosition(Vector2f) = 0;
	virtual Vector2f getSize() = 0;

	Vector2f getMax() { return (getPosition() + getSize()); };
	Vector2f getMin() { return getPosition(); };

	void move(Vector2f diff) { setPosition(getPosition() + diff);  };
};

