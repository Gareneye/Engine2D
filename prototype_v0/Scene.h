#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	enum State
	{
		ON,
		END,
		PAUSE
	};

	virtual void handleEvents(Event &e) = 0;
	virtual void update(double dt) = 0;
	virtual void render(RenderWindow &window) = 0;

	State getState();
	void setState(State s);

private:
	State state;
};

