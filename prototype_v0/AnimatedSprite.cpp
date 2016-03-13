#include "AnimatedSprite.h"

#include <iostream>

AnimatedSprite::AnimatedSprite(sf::Sprite *sprite, Animation *a, int width, int height)
{
	this->sprite = sprite;
	this->width = width;
	this->height = height;
	reset();
	
	add(a);
	run(0);
	actually = idle = temp;
	sprite->setTexture(*(actually->getTexture()));
}


AnimatedSprite::~AnimatedSprite()
{
}


size_t AnimatedSprite::add(Animation *a)
{
	animations.push_back(a);
	size_t index = animations.size() - 1;

	return index;
}

void AnimatedSprite::run(size_t index)
{
	if (temp == animations.at(index) || actually == animations.at(index))
		return;


	temp = animations.at(index);
	state = Proccess::NEW;
}

void AnimatedSprite::clear()
{
	if (temp == idle || actually == idle)
		return;

	temp = idle;
	state = Proccess::NEW;
}

void AnimatedSprite::setMirror(bool value)
{
	this->mirror = value;
}


void AnimatedSprite::update(double dt)
{
	accumulator += dt;

	// Ogranicznik czasu
	if (accumulator < actually->getSpeed())
		return;


	switch (state)
	{
		// kiedy ustawiamy nowa animacje
		case NEW:
		{
			if (actually->hasNext())
			{
				state = Proccess::END;
				actually = actually->getNext();
			}
			else if(temp->hasPrev())
			{
				state = Proccess::START;
				actually = temp->getPrev();
			}
			else
			{
				state = Proccess::MAIN;
				actually = temp;
			}

			reset();
			sprite->setTexture(*(actually->getTexture()));
		}
		break;

		// kiedy uruchomiona jest animacja PREV animacji docelowej (i ona trwa)
		case END:
		{
			if (actually->isEnd(frame))
			{
				if (temp->hasPrev())
				{
					state = Proccess::START;
					actually = temp->getPrev();
				}
				else
				{
					state = Proccess::MAIN;
					actually = temp;
				}
				reset();
				sprite->setTexture(*(actually->getTexture()));
			}
		}
		break;

		// start
		case START:
		{
			if (actually->isEnd(frame))
			{
				state = Proccess::MAIN;
				actually = temp;
				reset();
				sprite->setTexture(*(actually->getTexture()));
			}
		}
		break;

		//kiedy uruchomiono animacje docelowa (i ona trwa)
		case MAIN:
		{
			if (actually->isLooped())
			{
				state = Proccess::LOOP;
			}

			else if (actually->isStatic())
			{
				state = Proccess::STATIC;
			}

			else if (actually->isEnd(frame))
			{
				if (actually->hasNext())
				{
					state = Proccess::NEW;
					temp = actually->getNext();
				}
				else 
				{
					clear();
				}

				reset();
			}
		}
		break;

		// Kiedy animacja jest zapetlona
		case LOOP:
		{
			if (actually->isEnd(frame))
			{
				reset();
			}

		}
		break;

		
		case STATIC:
		{
			return;
		}
		break;

	}


		setRect();
		accumulator = 0;
		frame++;

}

void AnimatedSprite::setRect()
{
	if(mirror)
		sprite->setTextureRect(sf::IntRect((frame +1) * width, 0, -width, height));
	else
	sprite->setTextureRect(sf::IntRect(frame * width, 0, width, height));

	// podawaæ indeks w change na minusie i zrobic zmienna medium
}