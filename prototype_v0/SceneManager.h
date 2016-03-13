#pragma once

#include "Scene.h"

class SceneManager
{
public:
	SceneManager(sf::RenderWindow &window);
	~SceneManager();

	void set(Scene &scene);
	void handleEvents();
	void update(double dt);
	void render();

	bool isOn();

	inline void globalEvents(sf::Event);

private:
	RenderWindow *renderWindow;
	Scene *active;
	bool on;
};

