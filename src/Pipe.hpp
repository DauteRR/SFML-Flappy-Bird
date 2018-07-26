#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Definitions.hpp"
#include <vector>

class Pipe
{
private:

	GameDataRef gameData;

	std::vector<sf::Sprite> pipeSprites;

	std::vector<sf::Sprite> scoringPipes;

	int landHeight;

	int pipeSpawnYOffset;

public:

	Pipe(GameDataRef gameData);
	
	~Pipe();

	void drawPipes();

	void spawnBottomPipe();

	void spawnTopPipe();

	void spawnInvisiblePipe();

	void spawnScoringPipe();

	void movePipes(float dt);

	void randomizePipeOffset();

	const std::vector<sf::Sprite>& getSprites() const;

	std::vector<sf::Sprite>& getScoringSprites();
};

