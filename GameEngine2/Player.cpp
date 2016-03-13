#include "Player.h"

// DEBUG
Texture text;
#include <iostream>

Player::Player()
{
	width = height = 100;


	a1.setFillColor(sf::Color::Green);
	a1.setOrigin(Vector2f(0, 0));
	a1.setPosition(100, 100);
	a1.setSize(sf::Vector2f(width, height));

	jumped = 0;
}


Player::~Player()
{
}

void Player::setPosition(Vector2f pos)
{
	//sprite.setPosition(pos);
	a1.setPosition(pos);
}

Vector2f Player::getPosition()
{
	//return sprite.getPosition();
	return a1.getPosition();
}

Vector2f Player::getSize()
{
	return Vector2f(width, height);
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(sprite, states);
	target.draw(a1, states);
}

bool Player::canJump()
{
	std::cout << "Czy moze:" << &jumped << std::endl;
	//return (jumped == 0);
	return true;
}

void Player::jump()
{
	changeSpeed(Vector2f(0, -10.1));
	jumped++;
}

