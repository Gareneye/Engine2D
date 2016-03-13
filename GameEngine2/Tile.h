#pragma once

#include <SFML\Graphics.hpp>
#include "PhysBody.h"

using namespace sf;

class Tile : public PhysBody, public Drawable
{
public:
	Tile();
	~Tile();

	Vector2f getPosition();
	void setPosition(Vector2f);
	Vector2f getSize();

	void update(float dt);
	
	// TODO: ON-COLLIDE(target), etc.

private:
	Sprite sprite;

	void draw(RenderTarget & target, RenderStates states) const override;
};

