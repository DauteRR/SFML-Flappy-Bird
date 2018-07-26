#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "Game.hpp"
#include <vector>

class Bird
{
private:

	GameDataRef gameData;

	sf::Sprite birdSprite;

	std::vector<sf::Texture> animationFrames;

	unsigned int animationIterator;

	sf::Clock animationClock;

	sf::Clock statesClock;

	BirdState birdState;

	float rotationAngle;

public:

	Bird(GameDataRef gameData);

	~Bird();

	void draw();

	void animate(float dt);

	void update(float dt);

	void action();

	const sf::Sprite& getSprite() const;
};

