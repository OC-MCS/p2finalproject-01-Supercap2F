#include "alienManager.h"


AlienManager::AlienManager(Sprite &back, SpriteManager &spriteMgr , GameManager &gameMgr, Ship &s) {
	// setup intial aliens
	for (int x = 0; x < 14; x++) {
		Alien a(spriteMgr, 50 + (x * 50), 100);
		aliens.push_back(a);
	}
	yline = 100;

	// keep these for later 
	spriteManager = spriteMgr;
	background = back;
	gameManager = &gameMgr;

	ship = &s;
};

void AlienManager::drawAliens(RenderWindow &window) {
	// draw all the aliens
	list<Alien>::iterator iter;
	for (iter = aliens.begin(); iter != aliens.end(); iter++) {
		iter->draw(window);
	}
};

void AlienManager::moveAliens(RenderWindow &window) {
	// draw all the aliens
	if (yline <= window.getSize().y / 1.15f) {
		if (timer == 0) {
			list<Alien>::iterator iter;
			for (iter = aliens.begin(); iter != aliens.end(); iter++) {
				iter->move(0, 1);
				yline = iter->getPosition().y;
			}
			timer = FALL_COOLDOWN;
		}
		else {
			timer--;
		}
	}
	else {
		// game over
	}
};

void AlienManager::detectCollisions() {
	// detect collisions between the missiles and the aliens 
	if (aliens.size() == 0) {
		gameManager->win();
	}
	else {
		list<Alien>::iterator iter;
		iter = aliens.begin();
		while (iter != aliens.end()) {
			if (ship->missileInContactWithAlien(iter->getBounds())) {
				iter = aliens.erase(iter);
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
				bombIter = bombs.erase(bombIter);
				//gameManager->gameOver();
				gameManager->loseLife();
			}
			else {
				bombIter++;
			}
		}
	}
};

void AlienManager::dropBombs() {
	if (bombTimer == 0) { // drop bomb
		int selectedAlien = rand() % aliens.size();
		list<Alien>::iterator iter;
		iter = aliens.begin();
		for(int x = 0 ; x < selectedAlien; x++) // find selected alien
			iter++;

		Bomb newBomb(background, &spriteManager, iter->getPosition().x + 10, iter->getPosition().y + 20);
		bombs.push_back(newBomb);

		bombTimer = bombTimeout;
	}
	else {
		bombTimer--;
	}
};

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

void AlienManager::drawBombs(RenderWindow &window) {
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end(); iter++) {
		iter->draw(window);
	}
};

void AlienManager::resetAliens() {
	// setup intial aliens
	aliens.clear(); // delete everything from the alien list
	bombs.clear();  // delete all the bombs

	for (int x = 0; x < 14; x++) {
		Alien a(spriteManager, 50 + (x * 50), 100);
		aliens.push_back(a);
	}
	yline = 100;

}


