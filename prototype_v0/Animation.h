#pragma once

#include <SFML\Graphics.hpp>

/*
	Dokumentacja
	W zasobach mojej gry nalezy uzywac animacji ktore opieraja sie na atlasach od 0px do width*ilosc_klatek
	Jednopoziomowe.
	+--------------------------------+
	|  0  |  1   |  2  |  3   |   4  |
	+--------------------------------+
*/

class Animation
{
public:
	enum Type
	{
		DYNAMIC,
		STATIC
	};
	Animation(sf::Texture *t, size_t frames, float speed, bool looped = false, Animation::Type type = Type::DYNAMIC);
	virtual ~Animation();

	bool hasNext();
	bool hasPrev();
	Animation* getNext();
	Animation* getPrev();
	void setPrev(Animation *a);
	void setNext(Animation *a);

	sf::Texture* getTexture();

	bool isLooped();
	double getSpeed();
	size_t getFrames();

	bool isEnd(size_t frame);
	bool isStatic();

private:
	sf::Texture * texture;

	double speed;
	size_t frames;
	bool looped;
	Animation::Type typeAnimation;

	Animation *prev, *next;

};

