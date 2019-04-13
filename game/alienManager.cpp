//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Alien Manager Code
//====================================================================
#include "alienManager.h"

//====================================================================
// The constructor creates a initial line of 14 aliens 
AlienManager::AlienManager(Sprite &back, SpriteManager &spriteMgr , GameManager &gameMgr, Ship &s) {
	// setup intial aliens
	for (int x = 0; x < 14; x++) {
		Alien a(&gameMgr, spriteMgr, 50.0f + (x * 50.0f), 100.0f);
		aliens.push_back(a);
	}
	yline = 100; 

	// keep these for later 
	spriteManager = spriteMgr;
	background = back;
	gameManager = &gameMgr;
	ship = &s;
};

//====================================================================
// This function loops through the linked list and draws all the 
// aliens from it. 
void AlienManager::drawAliens(RenderWindow &window) {
	// draw all the aliens in the list
	list<Alien>::iterator iter;
	for (iter = aliens.begin(); iter != aliens.end(); iter++) {
		iter->draw(window);
	}
};

//====================================================================
// moves the aliens down the screen
void AlienManager::moveAliens(RenderWindow &window) {
	if (yline <= window.getSize().y / 1.15f) {
		// if the timer is done counting down 
		if (timer == 0) {
			list<Alien>::iterator iter;
			for (iter = aliens.begin(); iter != aliens.end(); iter++) { 
				iter->move(0, 1);
				yline = iter->getPosition().y; // keep track of the y position in a variable
			}
			timer = FALL_COOLDOWN; // reset timer 
		}
		else { // if the timer is still counting down
			timer--;
		}
	}
	else { // if the aliens have reached the bottom of the screen
		gameManager->gameOver();
	}
};

//====================================================================
// This function detects collisions between the aliens and the missiles
// and the bombs and the ship. 
void AlienManager::detectCollisions() {
	if (aliens.size() == 0) {     // if all of the aliens are killed
		gameManager->nextLevel(); // progress to the next level
	}
	else {
		// loop through all the aliens to see if the any of the missiles has hit one
		list<Alien>::iterator iter;
		iter = aliens.begin();
		while (iter != aliens.end()) {
			if (ship->missileInContactWithAlien(iter->getBounds())) {
				iter = aliens.erase(iter);  // delete hit alien
				gameManager->alienKilled(); // increase alien death count
			}
			else {
				iter++;
			}
		}

		// detect collisions between the bombs and the ship
		list<Bomb>::iterator bombIter;
		bombIter = bombs.begin();
		while (bombIter != bombs.end()) {
			if (ship->getBounds().contains(bombIter->getPosition())) {
				bombIter = bombs.erase(bombIter); // delete the bomb
				gameManager->loseLife();		  // remove a life from the ship
			}
			else {
				bombIter++;
			}
		}
	}
};

//====================================================================
// drops bombs at random intervals from random aliens
void AlienManager::dropBombs() {
	if (bombTimer == 0) { // if the timer has finished counting down
		// select a random alien to drop a bomb 
		int selectedAlien = rand() % aliens.size();

		// find selected alien
		list<Alien>::iterator iter;
		iter = aliens.begin();
		for(int x = 0 ; x < selectedAlien; x++) 
			iter++;

		// drop bomb with generated values
		Bomb newBomb(gameManager, &spriteManager, iter->getPosition().x + 10, iter->getPosition().y + 20);
		bombs.push_back(newBomb);

		// reset the timer - if the game is on level two make it a shorter interval 
		int tmp = rand() % 20;
		bombTimer = static_cast<int>((bombTimeout + tmp) / ((gameManager->getLevel() * 0.3) + 1)); 
	}
	else {
		bombTimer--; // count down on the bsomb timer 
	}
};

//====================================================================
// moves the bombs downward 
void AlienManager::moveBombs(RenderWindow &window) {
	list<Bomb>::iterator iter;
	iter = bombs.begin();
	while (iter != bombs.end()) {
		iter->move();
		if (iter->getPosition().y > window.getSize().y) {
			iter = bombs.erase(iter);
		}
		else {
			iter++;
		}
	}
};

//====================================================================
// draws all the bombs on the screen
void AlienManager::drawBombs(RenderWindow &window) {
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end(); iter++) {
		iter->draw(window);
	}
};

//====================================================================
//	reset the postion and number of the aliens 
void AlienManager::resetAliens() {
	aliens.clear(); // delete everything from the alien list
	bombs.clear();  // delete all the bombs

	// regenerate aliens
	for (int x = 0; x < 14; x++) {
		Alien a(gameManager, spriteManager, 50.0f + (x * 50.0f), 100.0f);
		aliens.push_back(a);
	}
	yline = 100;
}


