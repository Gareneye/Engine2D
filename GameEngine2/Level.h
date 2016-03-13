#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Resources.h"

#define TILE_SIZE 30

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

	void createLevelData(int width, int height)
	{
		data = new int*[height];

		for (int i = 0; i < height; i++)
			data[i] = new int[width];
	}

	void update(double dt);
	void draw(RenderTarget & target, RenderStates states) const;

private:
	int** data;
	unsigned int width, height;

	vector<Sprite> sprites;
	void addSprite(int x, int y, int type)
	{
		Sprite sprite;
		sprite.setPosition(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

		sprite.setTexture(rTextures::getInstance().get("wood"));
		sprites.push_back(sprite);

	}
};

