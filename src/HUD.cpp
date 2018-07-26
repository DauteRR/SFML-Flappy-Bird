#include "stdafx.h"
#include "HUD.hpp"
#include <string>


HUD::HUD(GameDataRef gameData):
gameData(gameData)
{
	scoreText.setFont(gameData->assetManager.getFont("Flappy Font"));
	scoreText.setString("0");
	scoreText.setCharacterSize(128);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
	scoreText.setPosition(gameData->gameWindow.getSize().x / 2, gameData->gameWindow.getSize().y / 5);
}


HUD::~HUD()
{
}

void HUD::draw()
{
	gameData->gameWindow.draw(scoreText);
}

void HUD::updateScore(int newScore)
{
	scoreText.setString(std::to_string(newScore));
}
