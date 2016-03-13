#include "Level.h"



Level::Level()
{
}


Level::~Level()
{
}

void Level::loadFromFile(string filename)
{
	fstream file;
	file.open("data/levels/" + filename, std::ios::in);

	if (!file.is_open())
	{
		cout << "Nie znaleziono poziomu: " << filename;
		return;
	}

	file >> width;
	file >> height;
	createLevelData(width, height);

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			file >> data[y][x];
			if (data[y][x] != NONE)
				addSprite(x, y, data[y][x]);
		}


	file.close();
}

void Level::update(double dt)
{
}

void Level::draw(RenderTarget & target, RenderStates states) const
{
	for (auto i = sprites.begin(); i < sprites.end(); i++)
		target.draw(*i);
}

