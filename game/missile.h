#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "spriteManager.h"

class missile {
private:
	int posx;
	int posy;

	Texture missileTexture;
	Sprite missileSprite;

	const int DISTANCE = 10;

public:
	missile(SpriteManager *text, int x, int y);

	// copy constructor
	
	void move();
	void draw(RenderWindow &window);

	Vector2f getPosition();
};
