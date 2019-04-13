//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: GameManager Class Code
//====================================================================
#include "gameManager.h"

//====================================================================
// The constructor sets up the default menu font 
GameManager::GameManager() {
	// Load from a font file on disk
	if (!menuFont.loadFromFile("VT323-Regular.ttf")) {
		cout << "Unable to load menu font!" << endl;
		exit(EXIT_FAILURE);
	}
};

//====================================================================
// Checks if either the start/exit game button has been pressed and 
// carries out the corresponding action. 
void GameManager::updateMenu() {
	if (startPressed) { // reset game states and restart game
		startPressed = false;
		lives = 3;
		level = 1;
		gameLost = false;
		gameWon = false;
		resetlvl = true;
		timerStart = false;
		aliensKilled = 0;
	}
	else if (endPressed) { // exit game 
		endPressed = false;
		exit(0);
	}
};

//====================================================================
// draws the menu along with the game over/won notifications
void GameManager::drawMenu(RenderWindow &window) {
	if (Timer != 0) { // if the timer isn't done counting down
		Timer--; // decrease the timer
		if (gameLost) { // display the game lost notification
			text.setFont(menuFont);
			text.setFillColor(Color(255, 153, 0));

			text.setString("The Aliens have Invaded!");
			text.setCharacterSize(50);
			text.setPosition(120, 100);
			window.draw(text);
		}
		else { // display the game won notification 
			text.setFont(menuFont);
			text.setFillColor(Color(255, 153, 0));

			text.setString("You have Destroyed the Aliens!");
			text.setCharacterSize(50);
			text.setPosition(120, 100);
			window.draw(text);
		}
	}
	else { // display the default menu
		text.setFont(menuFont);
		text.setFillColor(Color(255, 153, 0));

		text.setString("Space Invaders");
		text.setCharacterSize(100);
		text.setPosition(120, 100);
		window.draw(text);

		startGame.setFont(menuFont);
		startGame.setFillColor(Color(255, 153, 0));
		endGame.setFont(menuFont);
		endGame.setFillColor(Color(255, 153, 0));

		startGame.setString("Start game");
		startGame.setCharacterSize(30);
		startGame.setPosition(310, 230);
		window.draw(startGame);

		endGame.setString("Quit");
		endGame.setCharacterSize(30);
		endGame.setPosition(310, 260);
		window.draw(endGame);
	}
};

//====================================================================
// displays the game data at the top of the screen
void GameManager::displayData(RenderWindow &window) {
	text.setFont(menuFont);

	text.setString("Lives " + to_string(lives) 
	+ " - Level " + to_string(level) + " - Aliens killed " + to_string(aliensKilled));
	text.setFillColor(Color(255, 153, 0));
	text.setCharacterSize(24);
	text.setPosition(8, 0);

	window.draw(text);
};

//====================================================================
// Returns true if the game isn't on the menu
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

//====================================================================
// advances to the next level and sets the game won state if the level
// advances past 2.
void GameManager::nextLevel() {
	if (level != 2) {
		level = 2;
		resetlvl = true;
	}
	else {
		gameWon = true;
	}
};

//====================================================================
// decrease the number of lives the ship has left
void GameManager::loseLife() {
	lives--;
	if (lives <= 0) {
		gameLost = true;
	} 
	resetlvl = true;
};

//====================================================================
// resets the game level 
bool GameManager::resetLevel() {
	bool tmp = resetlvl;
	if (resetlvl) 
		resetlvl = false;
	return tmp;
}

//====================================================================
// if the mouse button is released this function checks if it was on
// one of the menu buttons. 
void GameManager::mouseButtonReleased(Vector2f pos) {
	if (startGame.getGlobalBounds().contains(pos)) {
		startPressed = true;
	}

	if (endGame.getGlobalBounds().contains(pos)) {
		endPressed = true;
	}
}