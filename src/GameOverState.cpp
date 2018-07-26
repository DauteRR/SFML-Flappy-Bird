#include "stdafx.h"
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include <iostream>
#include <fstream>
#include "Definitions.hpp"
#include "GameState.hpp"

GameOverState::GameOverState(GameDataRef gameData, int score):
gameData(gameData),
score(score)
{

}

GameOverState::~GameOverState()
{
}

void GameOverState::init()
{
	std::ifstream reader;
	reader.open(HIGH_SCORE_FILE_FILEPATH);

	if (reader.is_open())
	{
		while (!reader.eof())
		{
			reader >> highScore;
		}
	}

	reader.close();

	std::ofstream writer;
	writer.open(HIGH_SCORE_FILE_FILEPATH);

	if (writer.is_open())
	{
		if (score > highScore)
		{
			highScore = score;
		}
		writer << highScore;
	}

	writer.close();

	gameData->assetManager.loadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
	gameData->assetManager.loadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
	gameData->assetManager.loadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
	gameData->assetManager.loadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
	gameData->assetManager.loadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
	gameData->assetManager.loadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
	gameData->assetManager.loadTexture("Platinum Medal", PLATINUM_MEDAL_FILEPATH);


	backgroundSprite.setTexture(this->gameData->assetManager.getTexture("Game Over Background"));
	gameOverTitle.setTexture(this->gameData->assetManager.getTexture("Game Over Title"));
	gameOverContainer.setTexture(this->gameData->assetManager.getTexture("Game Over Body"));
	retryButton.setTexture(this->gameData->assetManager.getTexture("Play Button"));
	
	gameOverContainer.setPosition((gameData->gameWindow.getSize().x / 2) - (gameOverContainer.getGlobalBounds().width / 2), 
		                          (gameData->gameWindow.getSize().y / 2) - (gameOverContainer.getGlobalBounds().height / 2));
	gameOverTitle.setPosition((gameData->gameWindow.getSize().x / 2) - (gameOverTitle.getGlobalBounds().width / 2), 
		                       gameOverContainer.getPosition().y - (gameOverTitle.getGlobalBounds().height * 1.2));
	retryButton.setPosition((gameData->gameWindow.getSize().x / 2) - (retryButton.getGlobalBounds().width / 2), 
						     gameOverContainer.getPosition().y + gameOverContainer.getGlobalBounds().height + retryButton.getGlobalBounds().height * 0.2);

	scoreText.setFont(gameData->assetManager.getFont("Flappy Font"));
	scoreText.setString(std::to_string(score));
	scoreText.setCharacterSize(56);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
	scoreText.setPosition(gameData->gameWindow.getSize().x / 10 * 7.25, gameData->gameWindow.getSize().y / 2.15);

	highScoreText.setFont(gameData->assetManager.getFont("Flappy Font"));
	highScoreText.setString(std::to_string(highScore));
	highScoreText.setCharacterSize(56);
	highScoreText.setFillColor(sf::Color::White);
	highScoreText.setOrigin(highScoreText.getGlobalBounds().width / 2, highScoreText.getGlobalBounds().height / 2);
	highScoreText.setPosition(gameData->gameWindow.getSize().x / 10 * 7.25, gameData->gameWindow.getSize().y / 1.78);

	if (score >= PLATINUM_MEDAL_SCORE)
	{
		medalSprite.setTexture(gameData->assetManager.getTexture("Platinum Medal"));
	} 
	else if (score >= GOLD_MEDAL_SCORE)
	{
		medalSprite.setTexture(gameData->assetManager.getTexture("Gold Medal"));
	}
	else if (score >= SILVER_MEDAL_SCORE)
	{
		medalSprite.setTexture(gameData->assetManager.getTexture("Silver Medal"));
	}
	else
	{
		medalSprite.setTexture(gameData->assetManager.getTexture("Bronze Medal"));
	}

	medalSprite.setPosition(175, 465);
}

void GameOverState::handleInput()
{
	sf::Event event;

	while (gameData->gameWindow.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			gameData->gameWindow.close();
		}

		if (gameData->inputManager.isSpriteClicked(retryButton, sf::Mouse::Left, gameData->gameWindow))
		{
			gameData->machine.addState(StateRef(new GameState(gameData)), true);
		}
	}
}

void GameOverState::update(float dt)
{

}

void GameOverState::draw(float dt)
{
	gameData->gameWindow.clear();

	gameData->gameWindow.draw(backgroundSprite);
	gameData->gameWindow.draw(gameOverContainer);
	gameData->gameWindow.draw(gameOverTitle);
	gameData->gameWindow.draw(retryButton);
	gameData->gameWindow.draw(highScoreText);
	gameData->gameWindow.draw(scoreText);
	gameData->gameWindow.draw(medalSprite);

	gameData->gameWindow.display();
}

