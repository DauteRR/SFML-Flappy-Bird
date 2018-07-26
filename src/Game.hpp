#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "StateMachine.hpp"
#include "InputManager.hpp"
#include "AssetManager.hpp"

struct GameData
{
	StateMachine machine;
	sf::RenderWindow gameWindow;
	AssetManager assetManager;
	InputManager inputManager;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
private:

	const float dt = 1.0f / 60.0f;

	sf::Clock clock;

	GameDataRef gameData = std::make_shared<GameData>();

	void run();

public:

	Game(int width, int height, std::string windowTitle);
	
	~Game();


};

