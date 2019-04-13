//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Bomb Class Definitions 
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
// The bomb class has all of the logic for keeping up with a 
// single bomb.
class Bomb {
private:
	Sprite bombSprite;          // holds the sprite returned by the sprite manager for the bomb
	const float DISTANCE = 5.0; // the distance the bomb falls when it drops 

public:
	Bomb(GameManager *gameManager, SpriteManager *spriteMgr, float x, float y);

	void move();
	void draw(RenderWindow &window);

	// getter functions for checking collisions in alien manager 
	Vector2f getPosition();
	FloatRect getBounds();
};
