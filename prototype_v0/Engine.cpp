#include "Engine.h"

//DEBUG
#include <iostream>
#include <string>
#include "Phys.h"
#include "Player.h"
#include "Resources.h"
Phys phys;
Player player;
Player player3;
Font font;
Text collisionCount;

sf::Sprite bg;
sf::Texture bgt;


Engine::Engine()
{
	phys.addDynBody(player);
	phys.addDynBody(player3);

	bgt.loadFromFile("data/bg.png");
	bg.setScale(sf::Vector2f(4, 4));
	bg.setTexture(bgt);


	level = new Level();
	level->loadFromFile("start.level");
	phys.addLevel(level);

	font.loadFromFile("data/arial.ttf");
	collisionCount.setFont(font);
	collisionCount.setColor(Color::White);
	collisionCount.setPosition(Vector2f(10, 10));
	collisionCount.setCharacterSize(17);
}


Engine::~Engine()
{
	delete(level);
}

/*------------
	EVENTY
------------*/
void Engine::handleEvents(Event & e)
{

	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::D)
		{
			player3.setConstRun(Vector2f(60, 0));
		}
		else if (e.key.code == sf::Keyboard::A)
		{
			player3.setConstRun(Vector2f(-60, 0));
		}

		if (e.key.code == sf::Keyboard::W)
		{
			if (player3.isOnGround())
				player3.changeSpeed(Vector2f(0, -10.1));
		}

		if (e.key.code == sf::Keyboard::R)
		{
			player.setPosition(sf::Vector2f(100, 100));
			player3.setPosition(sf::Vector2f(100, 100));
		}
	}

	if (e.type == sf::Event::KeyReleased)
	{
		if (e.key.code == sf::Keyboard::D)
		{
			player3.setConstRun(Vector2f(0, 0));
		}
		else if (e.key.code == sf::Keyboard::A)
		{
			player3.setConstRun(Vector2f(0, 0));
		}
	}

	float positionX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	player.setConstRun(Vector2f(positionX, 0));

	if(player.isOnGround() && sf::Joystick::isButtonPressed(0, 0))
		player.changeSpeed(Vector2f(0, -10.1));

	if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
	{
		level->addTile(sf::Vector2f(e.mouseButton.x, e.mouseButton.y), 1);
	}
}

/*------------
	UPDATE
------------*/
void Engine::update(double dt)
{
	// Update fizyki
	phys.update(dt);

	collisionCount.setString(
		"[DEBUG INFO]"
		"\nCollision checks: " + to_string(phys.dGetCollisionCheckCount()) + 
		"\nCollisions: " + to_string(phys.dGetCollisionCount())
		);

	level->update(dt);
	player.update(dt);
	player3.update(dt);
}

/*------------
	RENDER
------------*/
void Engine::render(RenderWindow & window)
{
	window.draw(bg);
	window.draw(*level);

	window.draw(player);
	window.draw(player3);

	window.draw(collisionCount);
}
