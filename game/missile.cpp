#include "missile.h"
#include "spriteManager.h"

missile::missile(SpriteManager *text, int x, int y) {
	// load in missile sprite
	missileSprite = text->getMissileSprite();

	// setup intial ship position 
	posx = x;
	posy = y;
	missileSprite.setPosition(posx, posy);
};

void missile::draw(RenderWindow &window) {
	window.draw(missileSprite);
};


void missile::move() {
	missileSprite.move(0, -DISTANCE);
	posy = missileSprite.getPosition().y;
};

Vector2f missile::getPosition() {
	return missileSprite.getPosition();
}


