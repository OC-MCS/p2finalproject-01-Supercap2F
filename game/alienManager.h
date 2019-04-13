//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Alien Manager Definition
//====================================================================
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "spriteManager.h"
#include "bomb.h"
#include "alien.h"
#include "ship.h"
#include "gameManager.h"

//====================================================================
// The AlienManager keeps up with both the alien and bombs list. It
// handles collisions, dropping bombs, and moving everything around on
// screen. 
class AlienManager {
private:
	list<Alien> aliens; // linked list that keeps track of all the alien instances 
	list<Bomb> bombs;   // linked list that keeps track of all the bomb instances 

	Ship *ship; // pointer to the ship instance - we need this for bomb collisions

	SpriteManager spriteManager; // holds the spriteManager for creating new aliens and bombs
	Sprite background;           // holds the background for bounds checking on bombs and aliens 
	GameManager *gameManager;    // holds the gameManager for getting levels and lives 

	float yline; // the current y position that the aliens are at - used for checking if the aliens have invaded

	const int FALL_COOLDOWN = 3; // controls how quickly the bombs fall
	int timer;					 //
	int bombTimeout = 50;        // controls how often the bombs drop 
	int bombTimer;				 //

public:
	AlienManager(Sprite &back, SpriteManager &spriteMgr, GameManager &gameManager, Ship &s);

	void moveAliens(RenderWindow &window);
	void drawAliens(RenderWindow &window);
	
	void resetAliens();		 // creates a new line of aliens at the top of the screen
	void detectCollisions(); // handles collisions between missiles and aliens and 
							 // the bombs and the ship 
	 
	void moveBombs(RenderWindow &window); //
	void drawBombs(RenderWindow &window); //
	void dropBombs();					  // drops a random bomb at a random interval

};
