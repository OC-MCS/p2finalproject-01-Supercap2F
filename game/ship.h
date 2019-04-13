//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Ship Class Definition 
//====================================================================
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "missile.h"
#include "spriteManager.h"

//====================================================================
// The ship class contains the code for keeping track of the ship 
// along with all of the missiles that it fires at the aliens. 
class Ship {
private:
	list<missile> missiles; // the main linked list for the missiles 
	
	Sprite shipSprite;		// holds the sprite for the ship returned by the spriteManager

	const float DISTANCE = 5.0; // the distance the ship moves when the arrow keys are pressed

	Sprite *background;				// the background of the window used for bounds checking
	SpriteManager *spriteManager;	// a pointer to the sprite manager for when missiles are created

	const int MISSILE_COOLDOWN = 10; // amount of time before another missile can be fired 
	int timer = 0;

public:
	Ship(Sprite &back, SpriteManager &text, float x, float y);

	// fires a missile from the current ship position
	void fireMissile();

	// moves all of the active missiles upwards
	void updateMissiles();

	void moveShip();
	void resetShip();
	void draw(RenderWindow &window);

	// returns true and deletes the missile if it contacts an alien 
	bool missileInContactWithAlien(FloatRect bounds);

	// getter functions used for bounds checking 
	Vector2f getPosition();
	FloatRect getBounds();
};
