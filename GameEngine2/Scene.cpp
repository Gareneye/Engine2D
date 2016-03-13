#include "Scene.h"

Scene::Scene()
{
	state = State::ON;
}


Scene::~Scene()
{
}

Scene::State Scene::getState()
{
	return state;
}

void Scene::setState(State newState)
{
	state = newState;
}
