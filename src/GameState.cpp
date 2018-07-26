#include "stdafx.h"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include <iostream>
#include "Definitions.hpp"
#include "GameOverState.hpp"

GameState::GameState(GameDataRef gameData) :
	gameData(gameData)
{
}

GameState::~GameState()
{
}

void GameState::init()
{
	gameData->assetManager.loadSound("Hit Sound", HIT_SOUND_EFFECT_FILEPATH);
	gameData->assetManager.loadSound("Point Sound", POINT_SOUND_EFFECT_FILEPATH);
	gameData->assetManager.loadSound("Wing Sound", WING_SOUND_EFFECT_FILEPATH);
	gameData->assetManager.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	gameData->assetManager.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
	gameData->assetManager.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
	gameData->assetManager.loadTexture("Land", LAND_FILEPATH);
	gameData->assetManager.loadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
	gameData->assetManager.loadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
	gameData->assetManager.loadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
	gameData->assetManager.loadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
	gameData->assetManager.loadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
	gameData->assetManager.loadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

	pipes = new Pipe(gameData);
	land = new Land(gameData);
	bird = new Bird(gameData);
	flash = new Flash(gameData);
	hud = new HUD(gameData);

	backgroundSprite.setTexture(this->gameData->assetManager.getTexture("Game Background"));

	gameState = GameStates::READY;

	score = 0;
	hud->updateScore(score);

	hitSound.setBuffer(gameData->assetManager.getSound("Hit Sound"));
	pointSound.setBuffer(gameData->assetManager.getSound("Point Sound"));
	wingSound.setBuffer(gameData->assetManager.getSound("Wing Sound"));
}

void GameState::handleInput()
{
	sf::Event event;

	while (gameData->gameWindow.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			gameData->gameWindow.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (gameState != GameStates::GAME_OVER) 
			{
				gameState = GameStates::PLAYING;
				bird->action();
				wingSound.play();
			}
		}
	}
}

void GameState::update(float dt)
{
	if (gameState == GameStates::PLAYING)
	{
		pipes->movePipes(dt);
		bird->animate(dt);
		land->moveLand(dt);
		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
		{
			pipes->randomizePipeOffset();
			pipes->spawnInvisiblePipe();
			pipes->spawnBottomPipe();
			pipes->spawnTopPipe();
			pipes->spawnScoringPipe();

			clock.restart();
		}
		bird->update(dt);
		
		////// Collision dectection

		std::vector<sf::Sprite> landSprites = land->getSprites();
		for (int i = 0; i < landSprites.size(); ++i)
		{
			if (collision.checkSpriteCollision(landSprites.at(i), 0.7f, bird->getSprite(), 1.0f))
			{
				gameState = GameStates::GAME_OVER;

				clock.restart();

				hitSound.play();
			}
		}

		std::vector<sf::Sprite> pipeSprites = pipes->getSprites();
		for (int i = 0; i < pipeSprites.size(); ++i)
		{
			if (collision.checkSpriteCollision(pipeSprites.at(i), 0.625f, bird->getSprite(), 1.0f))
			{
				gameState = GameStates::GAME_OVER;

				clock.restart();

				hitSound.play();
			}
		}

		///////

		if (gameState == GameStates::PLAYING)
		{
			std::vector<sf::Sprite> &scoringSprites = pipes->getScoringSprites();
			for (int i = 0; i < scoringSprites.size(); ++i)
			{
				if (collision.checkSpriteCollision(scoringSprites.at(i), 0.625f, bird->getSprite(), 1.0f))
				{
					score++;
					hud->updateScore(score);
					scoringSprites.erase(scoringSprites.begin() + i);

					pointSound.play();
				}
			}
		}
	}

	if (gameState == GameStates::GAME_OVER)
	{
		flash->show(dt);

		if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
		{
			gameData->machine.addState(StateRef(new GameOverState(gameData, score)), true);
		}
	}

}

void GameState::draw(float dt)
{
	gameData->gameWindow.clear();

	gameData->gameWindow.draw(backgroundSprite);
	pipes->drawPipes();
	land->drawLand();
	bird->draw();
	flash->draw();
	hud->draw();

	gameData->gameWindow.display();
}

