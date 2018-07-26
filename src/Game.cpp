#include "stdafx.h"
#include "Game.hpp"
#include "SplashState.hpp"
#include <stdlib.h>
#include <time.h>

Game::Game(int width, int height, std::string windowTitle)
{
	srand(time(NULL));
	gameData->gameWindow.create(sf::VideoMode(width, height), windowTitle, sf::Style::Close | sf::Style::Titlebar);
	gameData->machine.addState(StateRef(new SplashState(this->gameData)));
	this->run();
}


Game::~Game()
{
}

void Game::run()
{
	float newTime, frameTime, interpolation;
	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;
	const float MAX_FRAME_TIME = 0.25f;

	while (this->gameData->gameWindow.isOpen())
	{
		this->gameData->machine.processStateChanges();

		newTime = this->clock.getElapsedTime().asSeconds();	
		frameTime = newTime - currentTime;

		if (frameTime > MAX_FRAME_TIME) 
		{
			frameTime = MAX_FRAME_TIME;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while ( accumulator >= dt)
		{
			this->gameData->machine.getActiveState()->handleInput();
			this->gameData->machine.getActiveState()->update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->gameData->machine.getActiveState()->draw(interpolation);
	}
}
