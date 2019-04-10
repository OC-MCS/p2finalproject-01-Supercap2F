#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;

class GameManager {
private:
	int level = 3;
	int lives = 3;

	bool gameLost = false;
	bool gameWon = false;

	Font menuFont;
	Text text;
	
	bool a = false;
	bool b = false;

	bool resetlvl = false;

	const int MENU_TIMEOUT = 120;
	int Timer = 0;
	bool timerStart = false;
	
public:
	GameManager();

	void updateMenu();
	void drawMenu(RenderWindow &window);
	void displayData(RenderWindow &window);

	bool isGameRunning();

	void win() {
		gameWon = true;
	};
	void gameOver() {
		gameLost = true;
	};
	void nextLevel();
	void loseLife();

	void aPressed() {
		a = true;
	};
	void bPressed() {
		b = true;
	};

	bool resetLevel();

	int getLives() {
		return lives;
	};
	int getLevel() {
		return level;
	};

};