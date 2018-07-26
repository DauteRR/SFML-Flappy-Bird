#include "stdafx.h"
#include "AssetManager.hpp"
#include <iostream>

AssetManager::AssetManager()
{
}


AssetManager::~AssetManager()
{
}

void AssetManager::loadTexture(std::string name, std::string fileName)
{
	sf::Texture texture;

	if (texture.loadFromFile(fileName)) 
	{
		this->textures[name] = texture;
	}
	else 
	{
		std::cerr << "Error loading a texture: " + fileName << std::endl;
	}
}

sf::Texture & AssetManager::getTexture(std::string textureName)
{
	return this->textures.at(textureName);
}

void AssetManager::loadFont(std::string name, std::string fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->fonts[name] = font;
	}
	else
	{
		std::cerr << "Error loading a font: " + fileName << std::endl;
	}
}

sf::Font & AssetManager::getFont(std::string fontName)
{
	return this->fonts.at(fontName);
}

void AssetManager::loadSound(std::string name, std::string fileName)
{
	sf::SoundBuffer sound;

	if (sound.loadFromFile(fileName))
	{
		if (this->sounds.find(name) == this->sounds.end())
		{
			this->sounds[name] = sound;
		}
	}
	else
	{
		std::cerr << "Error loading a sound: " + fileName << std::endl;
	}
}

sf::SoundBuffer & AssetManager::getSound(std::string soundName)
{
	return this->sounds.at(soundName);
}
