	#include "stdafx.h"
#include "Bird.hpp"


Bird::Bird(GameDataRef gameData):
gameData(gameData)
{
	animationIterator = 0;

	animationFrames.push_back(gameData->assetManager.getTexture("Bird Frame 1"));
	animationFrames.push_back(gameData->assetManager.getTexture("Bird Frame 2"));
	animationFrames.push_back(gameData->assetManager.getTexture("Bird Frame 3"));
	animationFrames.push_back(gameData->assetManager.getTexture("Bird Frame 4"));

	birdSprite.setTexture(animationFrames.at(animationIterator));

	birdSprite.setPosition((gameData->gameWindow.getSize().x / 4) - (birdSprite.getGlobalBounds().width / 2), (gameData->gameWindow.getSize().y / 2) - (birdSprite.getGlobalBounds().height / 2));

	birdState = STILL;

	sf::Vector2f origin = sf::Vector2f(birdSprite.getGlobalBounds().width / 2, birdSprite.getGlobalBounds().height / 2);

	birdSprite.setOrigin(origin);

	rotationAngle = 0;
}


Bird::~Bird()
{
}

void Bird::draw()
{
	gameData->gameWindow.draw(birdSprite);
}

void Bird::animate(float dt)
{
	if (animationClock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / animationFrames.size())
	{
		animationIterator = (animationIterator + 1) % animationFrames.size();
		birdSprite.setTexture(animationFrames.at(animationIterator));
		animationClock.restart();
	}
}

void Bird::update(float dt)
{
	if (birdState == FALLING)
	{
		birdSprite.move(0, GRAVITY * dt);
		rotationAngle += ROTATION_SPEED * dt;
		rotationAngle = (rotationAngle > 25.0f) ? 25.0f : rotationAngle;
		birdSprite.setRotation(rotationAngle);
	}
	else if (birdState == FLYING)
	{
		birdSprite.move(0, -FLYING_SPEED * dt);
		rotationAngle -= ROTATION_SPEED * dt;
		rotationAngle = (rotationAngle < -25.0f) ? -25.0f : rotationAngle;
		birdSprite.setRotation(rotationAngle);
	}

	if (statesClock.getElapsedTime().asSeconds() > FLYING_DURATION)
	{
		statesClock.restart();
		birdState = FALLING;
	}
}

void Bird::action()
{
	statesClock.restart();
	birdState = FLYING;
}

const sf::Sprite & Bird::getSprite() const
{
	return birdSprite;
}
