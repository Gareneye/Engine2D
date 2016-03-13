#include "Player.h"

// DEBUG
Texture text;

Player::Player()
{
	width = 50;
	height = 60;

	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.scale(sf::Vector2f(2, 2)); // bezstratne powiekszenie
	sprite.setPosition(100, 100);

	// Tworzenie tekstury
	preResourceManager erun;
	erun.t = new sf::Texture();
	erun.t->loadFromFile("data/end_ruch.png");
	erun.a = new Animation(erun.t, 3, 0.08, false);
	animations.push_back(erun);

	preResourceManager srun;
	srun.t = new sf::Texture();
	srun.t->loadFromFile("data/start_ruch.png");
	srun.a = new Animation(srun.t, 4, 0.005, false);
	animations.push_back(srun);

	preResourceManager run;
	run.t = new sf::Texture();
	run.t->loadFromFile("data/ruch.png");
	run.a = new Animation(run.t, 4, 0.08, true);
	run.a->setPrev(srun.a);
	run.a->setNext(erun.a);
	animations.push_back(run);

	preResourceManager stay;
	stay.t = new sf::Texture();
	stay.t->loadFromFile("data/stay.png");
	stay.a = new Animation(stay.t, 12, 0.18, true, Animation::STATIC);
	animations.push_back(stay);

	animSystem = new AnimatedSprite(&sprite, stay.a, 32, 32);
	animSystem->add(run.a);
}


Player::~Player()
{
}

void Player::setPosition(Vector2f pos)
{
	sprite.setPosition(pos);
}

Vector2f Player::getPosition()
{
	return sprite.getPosition();
}

Vector2f Player::getSize()
{
	return Vector2f(width, height);
}

void Player::setConstRun(Vector2f diff)
{
	if (abs(diff.x) < 50)
	{
		constRunX = 0;
		animSystem->clear();
	}
	else
	{
		animSystem->run(1);

		if (diff.x > 0)
		{
			constRunX = 0.5;
			animSystem->setMirror(false);
		}
		else
		{
			constRunX = -0.5;
			animSystem->setMirror(true);
		}


	}
}

void Player::update(double dt)
{
	if(this->isOnGround())
		changeSpeed(Vector2f(constRunX, 0));

	animSystem->update(dt);
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
