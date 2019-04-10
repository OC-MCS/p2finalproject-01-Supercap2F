#include "ship.h"
#include "spriteManager.h"

Ship::Ship(Sprite &back, SpriteManager &spriteMgr, int x, int y) {
	// get the sprite for the ship
	shipSprite = spriteMgr.getShipSprite();

	// setup intial ship position 
	shipX = x;
	shipY = y;
	shipSprite.setPosition(shipX, shipY);

	// keep a pointer to the background for bounds checking
	background = &back;

	// keep a pointer to the sprite manager for loading sprites in 
	spriteManager = &spriteMgr;
}


// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen
void Ship::moveShip() {
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		if ((shipSprite.getPosition().x + -DISTANCE) >= 0) {
			shipSprite.move(-DISTANCE, 0);
			shipX = shipSprite.getPosition().x;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		if ((shipSprite.getPosition().x + DISTANCE) <= (background->getLocalBounds().width - shipSprite.getLocalBounds().width)) {
			shipSprite.move(DISTANCE, 0);
			shipX = shipSprite.getPosition().x;
		}
	}
};


void Ship::draw(RenderWindow &window) {
	window.draw(shipSprite);

	// draw all the missiles along with the ship
	list<missile>::iterator iter;
	for (iter = missiles.begin(); iter != missiles.end(); iter++) {
		iter->draw(window);
	}
};


// functions that relate to the missile class
void Ship::fireMissile() {
	if (timer == 0) {
		missile m(spriteManager, shipX + 16, shipY - 5);
		missiles.push_back(m);
		timer = MISSILE_COOLDOWN;
	}
};

// updates the missiles and checks thier bounds
void Ship::updateMissiles() {
	list<missile>::iterator iter;

	// move the active missiles positions and make sure they are still in the window 
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

bool Ship::missileInContactWithAlien(FloatRect bounds) {
	bool r = false;
	list<missile>::iterator iter;
	iter = missiles.begin();
	while (iter != missiles.end()) {
		if (bounds.contains(iter->getPosition())) {
			iter = missiles.erase(iter);
			r = true;
		}
		else {
			iter++;
		}
	}
	return r;
};

Vector2f Ship::getPosition() {
	return shipSprite.getPosition();
};

FloatRect Ship::getBounds() {
	return shipSprite.getGlobalBounds();
};

void Ship::resetShip() {
	missiles.clear();
}

