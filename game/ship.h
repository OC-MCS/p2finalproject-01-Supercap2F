#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "missile.h"
#include "spriteManager.h"

class Ship {
private:
	list<missile> missiles;

	Texture shipTexture;
	Sprite shipSprite;

	int shipX;
	int shipY;

	const float DISTANCE = 5.0;

	Sprite *background;
	SpriteManager *spriteManager;

	const int MISSILE_COOLDOWN = 15; // in fps
	int timer = 0;

public:
	// default constructor
	Ship(Sprite &back, SpriteManager &text, int x, int y);

	void fireMissile();
	void updateMissiles();

	void moveShip();

	void draw(RenderWindow &window);

};
