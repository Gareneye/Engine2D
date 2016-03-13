
#include <SFML\Graphics.hpp>
#include "SceneManager.h"
#include "Scene.h"
#include "Engine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 700), "Tytul", sf::Style::None);
	SceneManager sceneManager(window);

	/*-----------------
		   SCENY
	-----------------*/
	Engine game;
	sceneManager.set(game);

	/*-----------------
		PETLA CZASU
	-----------------*/
	sf::Clock timer;
	const double dt = 0.01;
	double currentTime = timer.getElapsedTime().asSeconds();
	double accumulator = 0.0;

	while (sceneManager.isOn())
	{
		// Obliczanie "akumulatora czasu"
		double newTime = timer.getElapsedTime().asSeconds();
		double frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime;

		// Sprawdzanie eventow
		sceneManager.handleEvents();

		// Liczenie fizyki, mechaniki silnika
		while (accumulator >= dt)
		{
			sceneManager.update(dt);
			accumulator -= dt;
		}

		// Rysowanie
		sceneManager.render();
	}

	return 0;
}