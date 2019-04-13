//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Alien class code 
//====================================================================
#include "alien.h"

//====================================================================
// constructor for the alien class, passed an initial position for the 
// alien
Alien::Alien(GameManager *gameManager, SpriteManager &spriteMgr, float x, float y) {
	// get the sprite for the alien based on the current level
	if(gameManager->getLevel() == 1) {
		alienSprite = spriteMgr.getAlienSpriteLvl1();
	}
	else {
		alienSprite = spriteMgr.getAlienSpriteLvl2(); 
	}

	// setup intial alien position 
	alienSprite.setPosition(x, y);
};

//====================================================================
// draws the alien on the window 
void Alien::draw(RenderWindow &window) {
	window.draw(alienSprite);
};

//====================================================================
// moves the alien by the amount passed in the x and y variables 
void Alien::move(float x, float y) {
	alienSprite.move(x, y);
};

//====================================================================
// getter functions used for bounds checking 
Vector2f Alien::getPosition() {
	return alienSprite.getPosition();
}

FloatRect Alien::getBounds() {
	return alienSprite.getGlobalBounds();
};
