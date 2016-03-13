#include "SceneManager.h"



SceneManager::SceneManager(sf::RenderWindow &window)
{
	renderWindow = &window;
	on = true;
}


SceneManager::~SceneManager()
{
}

void SceneManager::set(Scene & scene)
{
	active = &scene;
}

void SceneManager::handleEvents()
{
	sf::Event event;
	while (renderWindow->pollEvent(event))
	{
		this->globalEvents(event);
		active->handleEvents(event);
	}

}

void SceneManager::update(double dt)
{
	active->update(dt);
}

void SceneManager::render()
{
	renderWindow->clear();
	active->render(*renderWindow);
	renderWindow->display();
}

bool SceneManager::isOn()
{
	return on;
}

inline void SceneManager::globalEvents(sf::Event event)
{
	if (event.type == sf::Event::Closed ||
		event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		on = false;
}
