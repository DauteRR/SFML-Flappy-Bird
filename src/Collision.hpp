#pragma once
#include <SFML/Graphics.hpp>

class Collision
{
public:
	
	Collision();
	
	~Collision();

	bool checkSpriteCollision(sf::Sprite firstSprite, sf::Sprite secondSprite);

	bool checkSpriteCollision(sf::Sprite firstSprite, float firstScale, sf::Sprite secondSprite, float secondScale);
};

