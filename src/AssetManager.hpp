#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
private:

	std::map<std::string, sf::Texture> textures;

	std::map<std::string, sf::Font> fonts;

	std::map<std::string, sf::SoundBuffer> sounds;

public:

	AssetManager();

	~AssetManager();

	void loadTexture(std::string name, std::string fileName);	

	sf::Texture & getTexture(std::string textureName);

	void loadFont(std::string name, std::string fileName);

	sf::Font & getFont(std::string fontName);

	void loadSound(std::string name, std::string fileName);

	sf::SoundBuffer & getSound(std::string soundName);

};

