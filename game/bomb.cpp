//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Bomb Class Code
//====================================================================
#include "bomb.h"

//====================================================================
// Constructor creates a single bomb with the position passed to it
Bomb::Bomb(GameManager *gameManager, SpriteManager *spriteMgr, float x, float y) {
	// get the sprite for the bomb based on the current game level
	if (gameManager->getLevel() == 1) {
		bombSprite = spriteMgr->getBombSpriteLvl1();
	}
	else {
		bombSprite = spriteMgr->getBombSpriteLvl2();
	}

	// setup initial bomb position
	bombSprite.setPosition(x, y);
}

//====================================================================
// Draws the bomb on the screen
void Bomb::draw(RenderWindow &window) {
	window.draw(bombSprite);
};

//====================================================================
// Moves the bomb by its default distance 
void Bomb::move() {
	bombSprite.move(0, DISTANCE);
};

//====================================================================
// getter functions used for collision detection in alien manager 
Vector2f Bomb::getPosition() {
	return bombSprite.getPosition();
}

FloatRect Bomb::getBounds() {
	return bombSprite.getGlobalBounds();
};
