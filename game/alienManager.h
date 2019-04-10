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


class AlienManager {
private:
	list<Alien> aliens;
	list<Bomb> bombs;

	Ship *ship;

	SpriteManager spriteManager;
	Sprite background;
	GameManager *gameManager;

	int yline;

	const int FALL_COOLDOWN = 3;
	int timer;

	int bombTimeout = 30;
	int bombTimer;

public:
	AlienManager(Sprite &back, SpriteManager &spriteMgr, GameManager &gameManager, Ship &s);

	void moveAliens(RenderWindow &window);
	void drawAliens(RenderWindow &window);
	
	
	void resetAliens();
	void detectCollisions();

	void moveBombs(RenderWindow &window);
	void drawBombs(RenderWindow &window);
	void dropBombs();
};
