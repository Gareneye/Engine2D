#include <iostream>
#include <fstream>
#include <string>


#define CHUNK_IN_FILE 8 
#define CHUNK_LENGHT 8

using namespace std;

class LevelTest
{
public:
	struct Chunk
	{
		int data[CHUNK_LENGHT][CHUNK_LENGHT];
	};

	struct QuadTree
	{
		int sX, sY;
		int eX, eY;

		Chunk * data = nullptr;

		QuadTree * NW = nullptr;
		QuadTree * NE = nullptr;
		QuadTree * SW = nullptr;
		QuadTree * SE = nullptr;
	};

	// Glowny korzen
	QuadTree * root = nullptr;

	void loadFromFile(string filename)
	{
		fstream file;
		file.open(filename, std::ios::in);

		if (!file.is_open())
		{
			cout << "Nie znaleziono poziomu: " << filename;
			return;
		}



		const int TILES_COUNT = CHUNK_IN_FILE * CHUNK_LENGHT;
		Chunk section[CHUNK_IN_FILE];

		for (int y = 0; y < TILES_COUNT; y++)
		{
			for (int x = 0; x < TILES_COUNT; x++)
			{
				int tmp;
				file >> tmp;

			}
		}




		file.close();

};

int main()
{
	LevelTest t;
	t.loadFromFile("data/start.level");

	system("pause");
	return 0;
}