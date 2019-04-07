#include "spriteManager.h"


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
	if (!backgroundTexture.loadFromFile("stars.jpg")) {
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	backgroundSprite.setTexture(backgroundTexture);

};

Sprite SpriteManager::getMissileSprite() {
	return missileSprite;
};

Sprite SpriteManager::getShipSprite() {
	return shipSprite;
};

Sprite SpriteManager::getBackgroundSprite() {
	return backgroundSprite;
};

