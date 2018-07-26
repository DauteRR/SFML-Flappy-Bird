#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.hpp"

class GameOverState : public State
{
private:

	GameDataRef gameData;

	sf::Sprite backgroundSprite;

	sf::Sprite gameOverTitle;

	sf::Sprite gameOverContainer;

	sf::Sprite retryButton;

	sf::Text scoreText;

	sf::Text highScoreText;

	int score;

	int highScore;

	sf::Sprite medalSprite;

public:

	GameOverState(GameDataRef gameData, int score);

	~GameOverState();

	void init();

	void handleInput();

	void update(float dt);

	void draw(float dt);
};

