//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Ship Class Code
//====================================================================
#include "ship.h"

//====================================================================
// The constructor gets the default sprite for the ship and sets up its
// initial position.
Ship::Ship(Sprite &back, SpriteManager &spriteMgr, float x, float y) {
	// get the sprite for the ship
	shipSprite = spriteMgr.getShipSprite();

	// setup intial ship position 
	shipSprite.setPosition(x, y);

	// keep a pointer to the background for bounds checking
	background = &back;

	// keep a pointer to the sprite manager for loading sprites in 
	spriteManager = &spriteMgr;
}


//====================================================================
// moves the ship based on the arrow keys
void Ship::moveShip() {
	if (Keyboard::isKeyPressed(Keyboard::Left)) { 
		// left arrow is pressed: move our ship left if it isn't outside of the screen
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		if ((shipSprite.getPosition().x + -DISTANCE) >= 0) {
			shipSprite.move(-DISTANCE, 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right)) {
		// right arrow is pressed: move our ship right if it isn't outside of the screen
		if ((shipSprite.getPosition().x + DISTANCE) <= (background->getLocalBounds().width - shipSprite.getLocalBounds().width)) {
			shipSprite.move(DISTANCE, 0);
		}
	}
};

//====================================================================
// Draws all of the current missiles and the ship on the screen
void Ship::draw(RenderWindow &window) {
	window.draw(shipSprite);

	// draw all the missiles
	list<missile>::iterator iter;
	for (iter = missiles.begin(); iter != missiles.end(); iter++) {
		iter->draw(window);
	}
};

//====================================================================
// Fire a single missile from the current location of the ship
void Ship::fireMissile() {
	if (timer == 0) { // make sure the timeout has passed
		missile m(spriteManager, shipSprite.getPosition().x + 16, shipSprite.getPosition().y - 5);
		missiles.push_back(m);
		timer = MISSILE_COOLDOWN;
	}
};

//====================================================================
// update all of the missiles and check if they are still on the screen
void Ship::updateMissiles() {
	list<missile>::iterator iter;

	// move the active missiles positions upward
	for (iter = missiles.begin(); iter != missiles.end(); iter++){
		iter->move();
	}

	// check to see if the missile is still contained in the background
	for (iter = missiles.begin(); iter != missiles.end(); /* note no ++ here*/)
	{
		if (!background->getGlobalBounds().contains(iter->getPosition())) {
			iter = missiles.erase(iter);
		}
		// the above works because erase returns a new iterator 
		// that points to next thing in list after what we just deleted
		else
			iter++;
	}

	// keep track of the missile firing timeout 
	if (timer != 0) {
		timer--;
	}
 }

//====================================================================
// Checks and returns true if a missile is touching an alien 
// along with deleting the missile if it is.
bool Ship::missileInContactWithAlien(FloatRect bounds) {
	bool r = false;
	list<missile>::iterator iter;
	iter = missiles.begin();
	while (iter != missiles.end()) {
		if (bounds.contains(iter->getPosition())) {
			iter = missiles.erase(iter); // delete the missile
			r = true;
		}
		else {
			iter++;
		}
	}
	return r;
};

//====================================================================
// Getter functions used for bounds checking 
Vector2f Ship::getPosition() {
	return shipSprite.getPosition();
};

FloatRect Ship::getBounds() {
	return shipSprite.getGlobalBounds();
};

//====================================================================
// removes all of the active missiles when a new game is started
void Ship::resetShip() {
	missiles.clear();
}

