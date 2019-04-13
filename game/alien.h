//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Alien class definitions
//====================================================================
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "spriteManager.h"
#include "gameManager.h"

//====================================================================
// The alien class has all of the logic for keeping up with a 
// single alien.
class Alien {
private:
	Sprite alienSprite; // holds the sprite returned by sprite manager that represents the alien

public:
	Alien(GameManager *gameManager,  SpriteManager &spriteMgr, float x, float y);

	// call with an x and y distance to move the alien by
	void move(float x, float y);
	// draw the alien sprite on the window at the proper position
	void draw(RenderWindow &window);

	// getter functions for checking collisions in alien manager 
	Vector2f getPosition();
	FloatRect getBounds();
};
