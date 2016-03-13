#include <iostream>
#include <unordered_map>
#include <memory>

#define MIDPOINT 0.0f
#define CHUNK_SIZE 64

using namespace std;

template <class T>
struct Vector2
{
	T x, y;
};

struct Bounds {
	Vector2<float> start;
	Vector2<float> end;
};

struct BoundsHash {
	std::size_t operator()(const Bounds& b) const
	{
		return 
			std::hash<float>()(b.start.x) + 
			std::hash<float>()(b.start.y)^2 + 
			std::hash<float>()(b.end.x)^3 + 
			std::hash<float>()(b.end.y)^4;
	}
};

struct Tile {
	Bounds bounds;
};


struct Chunk {
	Bounds bounds;

	Tile* TilesData[CHUNK_SIZE][CHUNK_SIZE];
};

struct Map {
	std::unordered_map<std::string, std::unique_ptr<Chunk>> MapData;
};


int main()
{
	Bounds test;
	test.start.x = 334.345;
	test.start.y = 123.123;
	test.end.x = 241.456;
	test.end.y = 345.657;

	BoundsHash test2;
	cout << test2(test) << endl;
	cout << test2(test) << endl;
	cout << test2(test) << endl;
	cout << test2(test) << endl;

	system("pause");
	return 0;
}