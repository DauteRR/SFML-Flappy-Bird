#include "stdafx.h"
#include "MainMenuState.hpp"
#include <sstream>
#include <iostream>
#include "Definitions.hpp"
#include "GameState.hpp"

MainMenuState::MainMenuState(GameDataRef gameData) :
	gameData(gameData)
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::init()
{
	gameData->assetManager.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
	gameData->assetManager.loadTexture("Game Title", GAME_TITLE_FILEPATH);
	gameData->assetManager.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);

	backgroundSprite.setTexture(this->gameData->assetManager.getTexture("Main Menu Background"));
	gameTitle.setTexture(this->gameData->assetManager.getTexture("Game Title"));
	playButton.setTexture(this->gameData->assetManager.getTexture("Play Button"));

	gameTitle.setPosition((WINDOW_WIDTH / 2) - (gameTitle.getGlobalBounds().width / 2), gameTitle.getGlobalBounds().height / 2);
	playButton.setPosition((WINDOW_WIDTH / 2) - (playButton.getGlobalBounds().width / 2), (WINDOW_HEIGHT / 2) - (playButton.getGlobalBounds().height / 2));
}

void MainMenuState::handleInput()
{
	sf::Event event;

	while (gameData->gameWindow.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			gameData->gameWindow.close();
		}

		if (gameData->inputManager.isSpriteClicked(playButton, sf::Mouse::Left, gameData->gameWindow))
		{
			gameData->machine.addState(StateRef(new GameState(gameData)), true);
		}
	}
}

void MainMenuState::update(float dt)
{
	
}

void MainMenuState::draw(float dt)
{
	gameData->gameWindow.clear();
	gameData->gameWindow.draw(backgroundSprite);
	gameData->gameWindow.draw(gameTitle);
	gameData->gameWindow.draw(playButton);
	gameData->gameWindow.display();
}

