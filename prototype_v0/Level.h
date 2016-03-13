#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Resources.h"
#include "PhysBody.h"
#include "Wood.h"

#define TILE_SIZE 60

using namespace sf;
using namespace std;

class Level : public Drawable
{
public:
	Level();
	~Level();

	enum TILE_TYPE
	{
		NONE,
		GROUND
	};

	void loadFromFile(string filename);

	void update(double dt);
	void draw(RenderTarget & target, RenderStates states) const;

	std::vector<Tile *> & getObjects();
	void addTile(Vector2f, int type);

private:
	int** data;
	unsigned int width, height;

	std::vector<Tile *> objects;

	void addObject(int x, int y, int type);
	void createLevelData(int width, int height);
};

