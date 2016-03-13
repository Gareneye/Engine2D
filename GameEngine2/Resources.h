#pragma once

#include "ResourceManager.h"
#include <SFML\Graphics.hpp>

using namespace std;


class rTextures :
	public ResourceManager<sf::Texture>
{
private:
	rTextures() {};
	rTextures(const rTextures &) {};
	rTextures& operator=(const rTextures &) {};
	~rTextures() {};

public: 
	static rTextures& getInstance()
	{
		static rTextures instance;
		return instance;
	}

	// todo: Wymyslic cos na singletona

	rTextures& load(string name, string path)
	{
		if (!isIn(name))
			create(name, path).loadFromFile(path);

		return *this;
	}
};