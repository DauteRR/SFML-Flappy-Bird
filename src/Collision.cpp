#include "stdafx.h"
#include "Collision.hpp"


Collision::Collision()
{
}


Collision::~Collision()
{
}

bool Collision::checkSpriteCollision(sf::Sprite firstSprite, sf::Sprite secondSprite)
{
	return firstSprite.getGlobalBounds().intersects(secondSprite.getGlobalBounds());
}

bool Collision::checkSpriteCollision(sf::Sprite firstSprite, float firstScale, sf::Sprite secondSprite, float secondScale)
{
	firstSprite.setScale(firstScale, secondScale);
	secondSprite.setScale(firstScale, secondScale);
	return firstSprite.getGlobalBounds().intersects(secondSprite.getGlobalBounds());
}
