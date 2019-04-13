//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Missile Class Codess
//====================================================================
#include "missile.h"

//====================================================================
// The constructor loads the sprite for the missile 
missile::missile(SpriteManager *text, float x, float y) {
	// load in missile sprite
	missileSprite = text->getMissileSprite();

	// setup intial missile position
	missileSprite.setPosition(x, y);
};

//====================================================================
// Draws the missile on the screen
void missile::draw(RenderWindow &window) {
	window.draw(missileSprite);
};

//====================================================================
// Moves the missile by the predefiend distance 
void missile::move() {
	missileSprite.move(0, -DISTANCE);
};

//====================================================================
// getter functions are used for bounds checking in the ship class
Vector2f missile::getPosition() {
	return missileSprite.getPosition();
}

FloatRect missile::getBounds() {
	return missileSprite.getGlobalBounds();
};
