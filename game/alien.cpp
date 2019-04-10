#include "alien.h"

Alien::Alien( SpriteManager &spriteMgr, int x, int y) {
	// get the sprite for the alien
	alienSprite = spriteMgr.getAlienSprite();

	// setup intial alien position 
	posx = x;
	posy = y;
	alienSprite.setPosition(posx, posy);

	// keep a pointer to the background for bounds checking
	//background = &back;
};

void Alien::draw(RenderWindow &window) {
	window.draw(alienSprite);
};

void Alien::move(int x, int y) {
	alienSprite.move(x, y);
	posy = alienSprite.getPosition().y;
	posx = alienSprite.getPosition().x;
};

Vector2f Alien::getPosition() {
	return alienSprite.getPosition();
}

FloatRect Alien::getBounds() {
	return alienSprite.getGlobalBounds();
};
