#pragma once

#include <SFML\Graphics.hpp>
#include "DynamicBody.h"
#include "Resources.h"
#include "AnimatedSprite.h"
#include "Animation.h"

using namespace sf;

class Player : public Drawable, public DynamicBody
{
public:
	Player();
	~Player();

	void setPosition(Vector2f);
	Vector2f getPosition();
	Vector2f getSize();

	void setConstRun(Vector2f);

	void update(double);

private:
	sf::Sprite sprite;
	float width, height;

	float maxSpeed;
	float constRunX;

	AnimatedSprite *animSystem;
	struct preResourceManager
	{
		Animation *a;
		sf::Texture *t;
	};
	std::vector<preResourceManager> animations;

	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

