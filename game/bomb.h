#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "spriteManager.h"

class Bomb {
private:
	int posx, posy;

	Sprite bombSprite;
	Sprite background;

	const int DISTANCE = 5;

public:
	Bomb(Sprite back, SpriteManager *spriteMgr, int x, int y);

	void move();
	void draw(RenderWindow &window);

	Vector2f getPosition();
	FloatRect getBounds();
};
