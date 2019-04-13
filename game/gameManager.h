//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: GameManager Class Definition
//====================================================================
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;

//====================================================================
// The GameManager keeps up with lives and levels along with the menu
// and things relating to the game win and game over state. 
class GameManager {
private:
	int level = 1; // keeps track of the current level - there is two in total
	int lives = 3; // keeps track of the number of lives remaining for the ship
	int aliensKilled = 0; // keeps up with the total number of aliens destroyed 

	bool gameLost = false; // set to true when the game is over
	bool gameWon = false;  // set to true when the game is won

	Font menuFont; // holds the main font for the game 

	Text text;		// used for drawing all of the non-clickable text 
	Text startGame; // holds the text for the clickable start game button
	Text endGame;   // holds the text for the clickable exit game button
	
	bool startPressed = false; // set to true if the start button is pressed
	bool endPressed = false;   // set to true if the exit game button is pressed

	bool resetlvl = false; // set to true if a function requests that the game be reset

	const int MENU_TIMEOUT = 120; // the amount of time that the game won/game lost notification is displayed 
	int Timer = 0;
	bool timerStart = false;      // used to remove the bug where the won/lost notification is displayed when the game is first ran

public:
	GameManager();

	void updateMenu();
	void drawMenu(RenderWindow &window);
	void displayData(RenderWindow &window);

	// returns true if the game is not on the menu
	bool isGameRunning(); 

	// advances to the next level of the game
	void nextLevel();

	// resets the level to the start 
	bool resetLevel();

	// decreases the number of lives the ship has left
	void loseLife();

	// called when the mouse clicker is released
	void mouseButtonReleased(Vector2f pos);

	// called when the game hits a win/lose state
	void win() { gameWon = true; };
	void gameOver() { gameLost = true; };

	// getter function returns information about lives/levels
	int getLives() { return lives; };
	int getLevel() { return level; };

	// increases the total number of aliens killed
	void alienKilled() { aliensKilled++; }
};