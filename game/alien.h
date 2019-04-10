#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "spriteManager.h"

class Alien {
private:
	int posx, posy;

	Sprite alienSprite;

	Sprite *background;

public:
	Alien(SpriteManager &spriteMgr, int x, int y);

	void move(int x, int y);

	void draw(RenderWindow &window);

	Vector2f getPosition();
	FloatRect getBounds();
};
