#include "stdafx.h"
#include "Flash.hpp"


Flash::Flash(GameDataRef gameData):
gameData(gameData)
{
	shape = sf::RectangleShape(sf::Vector2f(gameData->gameWindow.getSize()));
	shape.setFillColor(sf::Color(255, 255, 255, 0));

	flashOn = true;
}


Flash::~Flash()
{
}

void Flash::show(float dt)
{
	if (flashOn)
	{
		int alpha = shape.getFillColor().a + (FLASH_SPEED * dt);

		if (alpha >= 255.0f)
		{
			flashOn = false;
			alpha = 255.0f;
		}

		shape.setFillColor(sf::Color(255, 255, 255, alpha));
	}
	else
	{
		int alpha = shape.getFillColor().a - (FLASH_SPEED * dt);

		if (alpha <= 0.0f)
		{
			flashOn = false;
			alpha = 0.0f;
		}

		shape.setFillColor(sf::Color(255, 255, 255, alpha));
	}
}

void Flash::draw()
{
	gameData->gameWindow.draw(shape);
}
