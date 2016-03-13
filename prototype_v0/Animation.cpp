#include "Animation.h"



Animation::Animation(sf::Texture *t, size_t frames, float speed, bool looped, Animation::Type type)
{
	this->texture = t;
	this->typeAnimation = type;
	this->speed = speed;
	this->frames = frames;
	this->looped = looped;

	this->next = nullptr;
	this->prev = nullptr;
}


Animation::~Animation()
{
}

sf::Texture* Animation::getTexture()
{
	return this->texture;
}

bool Animation::hasNext()
{
	return (this->next != nullptr);
}

bool Animation::hasPrev()
{
	return (this->prev != nullptr);
}

Animation * Animation::getNext()
{
	return this->next;
}

Animation * Animation::getPrev()
{
	return this->prev;
}

void Animation::setPrev(Animation * a)
{
	this->prev = a;
}

void Animation::setNext(Animation * a)
{
	this->next = a;
}

bool Animation::isLooped()
{
	return looped;
}

double Animation::getSpeed()
{
	return speed;
}

size_t Animation::getFrames()
{
	return frames;
}

bool Animation::isEnd(size_t actualFrame)
{
	return actualFrame >= this->frames;
}

bool Animation::isStatic()
{
	return (typeAnimation == Type::STATIC);
}
