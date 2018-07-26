#include "stdafx.h"
#include "Pipe.hpp"
#include <iostream>

Pipe::Pipe(GameDataRef gameData):
gameData(gameData)
{
	landHeight = gameData->assetManager.getTexture("Land").getSize().y;
	pipeSpawnYOffset = 0;
}

Pipe::~Pipe()
{
}

void Pipe::drawPipes()
{
	for (unsigned short int i = 0; i < pipeSprites.size(); ++i)
	{
		gameData->gameWindow.draw(pipeSprites.at(i));
	}
}

void Pipe::spawnBottomPipe()
{
	sf::Sprite pipeSprite(gameData->assetManager.getTexture("Pipe Up"));

	pipeSprite.setPosition(gameData->gameWindow.getSize().x, gameData->gameWindow.getSize().y - pipeSprite.getGlobalBounds().height - pipeSpawnYOffset);

	pipeSprites.push_back(pipeSprite);
}

void Pipe::spawnTopPipe()
{
	sf::Sprite pipeSprite(gameData->assetManager.getTexture("Pipe Down"));

	pipeSprite.setPosition(gameData->gameWindow.getSize().x, -pipeSpawnYOffset);

	pipeSprites.push_back(pipeSprite);
}

void Pipe::spawnInvisiblePipe()
{
	sf::Sprite pipeSprite(gameData->assetManager.getTexture("Pipe Up"));

	pipeSprite.setPosition(gameData->gameWindow.getSize().x, gameData->gameWindow.getSize().y - pipeSprite.getGlobalBounds().height - pipeSpawnYOffset);

	pipeSprite.setColor(sf::Color(0, 0, 0, 0));

	pipeSprites.push_back(pipeSprite);
}

void Pipe::spawnScoringPipe()
{
	sf::Sprite pipeSprite(gameData->assetManager.getTexture("Scoring Pipe"));

	pipeSprite.setPosition(gameData->gameWindow.getSize().x, 0);

	scoringPipes.push_back(pipeSprite);
}

void Pipe::movePipes(float dt)
{
	float movement = PIPE_MOVEMENT_SPEED * dt;
	for (unsigned short int i = 0; i < pipeSprites.size(); ++i)
	{
		if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width)
		{
			pipeSprites.erase(pipeSprites.begin() + i);
		}
		else
		{
			pipeSprites.at(i).move(-movement, 0);
		}
	}

	for (unsigned short int i = 0; i < scoringPipes.size(); ++i)
	{
		if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width)
		{
			scoringPipes.erase(scoringPipes.begin() + i);
		}
		else
		{
			scoringPipes.at(i).move(-movement, 0);
		}
	}
}

void Pipe::randomizePipeOffset()
{
	pipeSpawnYOffset = rand() % (landHeight + 1);
}

const std::vector<sf::Sprite>& Pipe::getSprites() const
{
	return pipeSprites;
}

std::vector<sf::Sprite>& Pipe::getScoringSprites()
{
	return scoringPipes;
}
