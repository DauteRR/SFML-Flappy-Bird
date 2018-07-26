#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Definitions.hpp"

class Flash
{
private:

	GameDataRef gameData;

	sf::RectangleShape shape;

	bool flashOn;

public:

	Flash(GameDataRef gameData);
	
	~Flash();

	void show(float dt);

	void draw();
};

