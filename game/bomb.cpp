#include "bomb.h"


Bomb::Bomb(Sprite back, SpriteManager *spriteMgr, int x, int y) {
	// get the sprite for the bomb
	bombSprite = spriteMgr->getBombSprite();

	// setup initial bomb position
	posx = x;
	posy = y;
	bombSprite.setPosition(posx, posy);

	// keep a pointer to the background for bounds checking
	background = back;
}


void Bomb::draw(RenderWindow &window) {
	window.draw(bombSprite);
};

void Bomb::move() {
	bombSprite.move(0, DISTANCE);
	posy = bombSprite.getPosition().y;
};

Vector2f Bomb::getPosition() {
	return bombSprite.getPosition();
}

FloatRect Bomb::getBounds() {
	return bombSprite.getGlobalBounds();
};
