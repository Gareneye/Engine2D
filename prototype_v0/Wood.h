#pragma once

#include "Tile.h"
#include "Resources.h"

class Wood :
	public Tile
{
public:
	Wood();
	~Wood();

private:
	sf::Texture texture;
};

