#include "gameManager.h"

GameManager::GameManager() {
	// Load from a font file on disk
	if (!menuFont.loadFromFile("VT323-Regular.ttf"))
	{
		cout << "Unable to load menu font!" << endl;
		exit(EXIT_FAILURE);
	}
};

void GameManager::updateMenu() {
	if (a) { // reset game states and restart game
		a = false;
		lives = 3;
		level = 1;
		gameLost = false;
		gameWon = false;
		resetlvl = true;
		timerStart = false;
	}
	else if (b) { // exit game 
		b = false;
		exit(0);
	}
};

void GameManager::drawMenu(RenderWindow &window) {
	if (Timer != 0) {
		Timer--;
		if (gameLost) {
			text.setFont(menuFont);
			text.setFillColor(Color(255, 153, 0));

			text.setString("The Aliens have Invaded!");
			text.setCharacterSize(50);
			text.setPosition(120, 100);
			window.draw(text);
		}
		else {
			text.setFont(menuFont);
			text.setFillColor(Color(255, 153, 0));

			text.setString("You have Destroyed the Aliens!");
			text.setCharacterSize(50);
			text.setPosition(120, 100);
			window.draw(text);
		}
	}
	else {
		text.setFont(menuFont);
		text.setFillColor(Color(255, 153, 0));

		text.setString("Space Invaders");
		text.setCharacterSize(100);
		text.setPosition(120, 100);
		window.draw(text);

		text.setString("A -  Start game");
		text.setCharacterSize(30);
		text.setPosition(310, 230);
		window.draw(text);

		text.setString("B - Quit");
		text.setCharacterSize(30);
		text.setPosition(310, 260);
		window.draw(text);
	}
};

void GameManager::displayData(RenderWindow &window) {
	text.setFont(menuFont);


	text.setString("Lives " + to_string(lives) 
	+ " - Level " + to_string(level));
	text.setFillColor(Color(255, 153, 0));
	text.setCharacterSize(24);
	text.setPosition(8, 0);

	window.draw(text);
};



bool GameManager::isGameRunning() {
	bool temp = true;
	if (gameWon || gameLost) {
		if (!timerStart) {
			Timer = MENU_TIMEOUT;
			timerStart = true;
		}
		temp = false;
	}
	return temp;
};


void GameManager::nextLevel() {
	if (level != 2) {
		level = 2;
		resetlvl = true;
	}
	else {
		gameWon = true;
	}
};

void GameManager::loseLife() {
	lives--;
	if (lives <= 0) {
		gameLost = true;
	} 
	resetlvl = true;
	
};


bool GameManager::resetLevel() {
	bool tmp = resetlvl;
	if (resetlvl) 
		resetlvl = false;
	return tmp;
}
