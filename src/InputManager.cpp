#include "stdafx.h"
#include "InputManager.hpp"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

bool InputManager::isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect buttonRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

		if (buttonRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow & window)
{
	return sf::Mouse::getPosition(window);
}
