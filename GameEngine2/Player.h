#pragma once

#include <SFML\Graphics.hpp>
#include "DynamicBody.h"

using namespace sf;

class Player : public Drawable, public DynamicBody
{
public:
	Player();
	~Player();

	void setPosition(Vector2f);
	Vector2f getPosition();
	Vector2f getSize();

	bool canJump();
	void jump();

private:
	sf::Sprite sprite;
	sf::RectangleShape a1;
	float width, height;

	void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	int jumped;
};

