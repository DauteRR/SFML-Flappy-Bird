#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

class Land
{
private:

	GameDataRef gameData;

	std::vector<sf::Sprite> landSprites;

public:

	Land(GameDataRef gameData);
	
	~Land();

	void moveLand(float dt);

	void drawLand();

	const std::vector<sf::Sprite>& getSprites() const;
};

