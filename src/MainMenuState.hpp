#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.hpp"

class MainMenuState : public State
{
private:

	GameDataRef gameData;

	sf::Sprite backgroundSprite;

	sf::Sprite gameTitle;

	sf::Sprite playButton;

public:

	MainMenuState(GameDataRef	gameData);

	~MainMenuState();

	void init();

	void handleInput();

	void update(float dt);

	void draw(float dt);
};

