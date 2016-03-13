#include "Tile.h"



Tile::Tile() {}

Tile::~Tile() {}

Vector2f Tile::getPosition()
{
	return sprite.getPosition();
}

void Tile::setPosition(Vector2f newPos)
{
	sprite.setPosition(newPos);
}

Vector2f Tile::getSize()
{
	//temp
	return Vector2f(30, 30);
}

void Tile::update(float dt) {}

void Tile::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(sprite);
}
