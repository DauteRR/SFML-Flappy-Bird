#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.hpp"

class SplashState : public State
{
private:

	GameDataRef gameData;

	sf::Clock clock;

	sf::Sprite backgroundSprite;

public:

	SplashState(GameDataRef	gameData);
	
	~SplashState();

	void init();

	void handleInput();

	void update(float dt);

	void draw(float dt);
};

