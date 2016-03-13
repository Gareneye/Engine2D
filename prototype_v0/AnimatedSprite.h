#pragma once

#include <vector>
#include <SFML\Graphics.hpp>
#include "Animation.h"

class AnimatedSprite
{
public:
	AnimatedSprite(sf::Sprite *sprite, Animation *a, int width, int height);
	virtual ~AnimatedSprite();

	size_t add(Animation *a);
	void run(size_t index);
	void update(double dt);
	void clear();
	void setMirror(bool = true);

private:
	sf::Sprite *sprite;
	std::vector<Animation *> animations;

	Animation *actually;
	Animation *temp;
	Animation *idle;

	enum Proccess
	{
		START,
		MAIN, 
		NEW,
		LOOP, 
		END,
		STATIC
	};
	Proccess state;

	bool mirror;

	size_t frame;
	inline void reset() { frame = 0; accumulator = 0; };
	void setRect();

	int width, height;
	double accumulator;
};

