#include "stdafx.h"
#include "Land.hpp"
#include "Definitions.hpp"
	

Land::Land(GameDataRef gameData):
gameData(gameData)
{
	sf::Sprite firstLandSprite(gameData->assetManager.getTexture("Land"));
	sf::Sprite secondLandSprite(gameData->assetManager.getTexture("Land"));

	firstLandSprite.setPosition(0, gameData->gameWindow.getSize().y - firstLandSprite.getGlobalBounds().height);
	secondLandSprite.setPosition(firstLandSprite.getGlobalBounds().width, gameData->gameWindow.getSize().y - firstLandSprite.getGlobalBounds().height);

	landSprites.push_back(firstLandSprite);
	landSprites.push_back(secondLandSprite);
}


Land::~Land()
{
}

void Land::moveLand(float dt)
{
	float movement = PIPE_MOVEMENT_SPEED * dt;
	for (unsigned short int i = 0; i < landSprites.size(); ++i)
	{
		landSprites.at(i).move(-movement, 0.0f);

		if (landSprites.at(i).getPosition().x < 0 - landSprites.at(i).getGlobalBounds().width)
		{
			sf::Vector2f position(gameData->gameWindow.getSize().x, landSprites.at(i).getPosition().y);
			landSprites.at(i).setPosition(position);
		}
	}
}

void Land::drawLand()
{
	for (unsigned short int i = 0; i < landSprites.size(); ++i)
	{
		gameData->gameWindow.draw(landSprites.at(i));
	}
}

const std::vector<sf::Sprite>& Land::getSprites() const
{
	return landSprites;
}
