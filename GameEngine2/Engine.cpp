#include "Engine.h"

//DEBUG
#include <iostream>
#include <string>
#include "Phys.h"
#include "Player.h"
#include "Resources.h"
Phys phys;
Player player;
Player player2;
Player player3;
Font font;
Text collisionCount;



Engine::Engine()
{
	// Ladowanie resourcow
	rTextures::getInstance()
		.load("wood", "data/skrzynka.png")
		.load("cursor", "data/cursor_static.png");

	player.move(Vector2f(0, 0));
	player2.move(Vector2f(3, 400));
	player3.move(Vector2f(20, -200));

	phys.addDynBody(player);
	phys.addStatBody(player2);
	phys.addDynBody(player3);

	level = new Level();
	level->loadFromFile("start.level");

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
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::D)
	{
		player.changeSpeed(Vector2f(3.1, 0));
	}
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::A)
	{
		player.changeSpeed(Vector2f(-3.1, 0));
	}
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::W)
	{
		if (player.canJump())
			player.jump();
	}
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::S)
	{
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
}

/*------------
	RENDER
------------*/
void Engine::render(RenderWindow & window)
{
	window.draw(*level);

	window.draw(player);
	window.draw(player2);
	window.draw(player3);

	window.draw(collisionCount);
}
