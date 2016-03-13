#include "Level.h"



Level::Level()
{
}


Level::~Level()
{
	for (auto i = objects.begin(); i < objects.end(); i++)
		delete *i;
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
			addObject(x, y, data[y][x]);
		}


	file.close();
}

void Level::createLevelData(int width, int height)
{
	data = new int*[height];

	for (int i = 0; i < height; i++)
		data[i] = new int[width];
}

void Level::update(double dt)
{
}

void Level::draw(RenderTarget & target, RenderStates states) const
{
	for (auto i = objects.begin(); i < objects.end(); i++)
		target.draw(**i);
}

std::vector<Tile *> & Level::getObjects()
{
	return objects;
}

void Level::addTile(Vector2f pos, int type)
{
	if (type == 1)
	{
		Wood * object = new Wood();
		object->setPosition(pos);
		cout << pos.x << " " << pos.y << endl ;
		objects.push_back(object);
	}
}

void Level::addObject(int x, int y, int type)
{
	if (type == 1)
	{
		Wood * object = new Wood();
		object->setPosition(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

		objects.push_back(object);
	}
}