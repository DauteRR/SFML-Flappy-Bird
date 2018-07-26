#include "stdafx.h"
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include <sstream>
#include <iostream>
#include "Definitions.hpp"

SplashState::SplashState(GameDataRef gameData):
gameData(gameData)
{
}

SplashState::~SplashState()
{
}

void SplashState::init()
{
	gameData->assetManager.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
	backgroundSprite.setTexture(this->gameData->assetManager.getTexture("Splash State Background"));
}

void SplashState::handleInput()
{
	sf::Event event;

	while (gameData->gameWindow.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			gameData->gameWindow.close();
		}
	}
}

void SplashState::update(float dt)
{
	if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		gameData->machine.addState(StateRef(new MainMenuState(gameData)), true);
	}
}

void SplashState::draw(float dt)
{
	gameData->gameWindow.clear();
	gameData->gameWindow.draw(backgroundSprite);
	gameData->gameWindow.display();
}

