//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: SpriteManager Class code
//====================================================================
#include "spriteManager.h"

//====================================================================
// The constructor simply loads in all of the different sprites used
// in the game.
SpriteManager::SpriteManager() {
	// load texture and sprite for the missiles
	if (!missileTexture.loadFromFile("fireMissile.png")) {
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	missileSprite.setTexture(missileTexture);

	// load texture and sprite for the ship
	if (!shipTexture.loadFromFile("ship2.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	shipSprite.setTexture(shipTexture);

	// load texture for the background
	if (!backgroundTexture.loadFromFile("blueBackground.png")) {
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	backgroundSprite.setTexture(backgroundTexture);

	// load texture for the aliens
	if (!alienTexture.loadFromFile("alien.png")) {
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	alienSprite.setTexture(alienTexture);

	if (!alienTexture2.loadFromFile("alien2.png")) {
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	alienSprite2.setTexture(alienTexture2);

	// load texture for the bombs
	if (!bombTexture.loadFromFile("bomb1.png")) {
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	bombSprite.setTexture(bombTexture);

	if (!bombTexture2.loadFromFile("bomb2.png")) {
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	bombSprite2.setTexture(bombTexture2);
};

//====================================================================
// Getter functions return the sprites for the other classes to use
Sprite SpriteManager::getMissileSprite() {
	return missileSprite;
};

Sprite SpriteManager::getShipSprite() {
	return shipSprite;
};

Sprite SpriteManager::getBackgroundSprite() {
	return backgroundSprite;
};

Sprite SpriteManager::getAlienSpriteLvl1() {
	return alienSprite;
};

Sprite SpriteManager::getAlienSpriteLvl2() {
	return alienSprite2;
};

Sprite SpriteManager::getBombSpriteLvl1() {
	return bombSprite;
};

Sprite SpriteManager::getBombSpriteLvl2() {
	return bombSprite2;
};

