#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.h"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"

class GameState : public State
{
private:

	GameDataRef gameData;

	sf::Sprite backgroundSprite;

	sf::Clock clock;

	Pipe* pipes;

	Land* land;

	Bird* bird;

	Collision collision;

	GameStates gameState;

	Flash *flash;

	int score;

	int highScore;

	HUD *hud;

	sf::Sound hitSound;

	sf::Sound wingSound;

	sf::Sound pointSound;

public:

	GameState(GameDataRef gameData);

	~GameState();

	void init();

	void handleInput();

	void update(float dt);

	void draw(float dt);
};

