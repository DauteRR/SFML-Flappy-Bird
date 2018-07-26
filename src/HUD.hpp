#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "Game.hpp"

class HUD
{
private:

	GameDataRef gameData;

	sf::Text scoreText;

public:
	
	HUD(GameDataRef gameData);
	
	~HUD();

	void draw();

	void updateScore(int newScore);
};

