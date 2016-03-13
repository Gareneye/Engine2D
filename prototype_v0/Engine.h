#pragma once

#include "Scene.h"
#include "Level.h"

class Engine :
	public Scene
{
public:
	Engine();
	~Engine();


	void handleEvents(Event & e);
	void update(double dt);
	void render(RenderWindow & window);

private:
	Level * level;
};

