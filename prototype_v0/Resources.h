#pragma once

#include "ResourceManager.h"
#include <SFML\Graphics.hpp>

using namespace std;


class rTextures :
	public ResourceManager<sf::Texture>
{
public: 
	rTextures& load(string name, string path)
	{
		if (!isIn(name))
			create(name, path).loadFromFile(path);

		return *this;
	}
};