#include "Wood.h"



Wood::Wood()
{
	texture = sf::Texture();
	texture.loadFromFile("data/skrzynka.png");

	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(2.f, 2.f));
}


Wood::~Wood()
{
}
