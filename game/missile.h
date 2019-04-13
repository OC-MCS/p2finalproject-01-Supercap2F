//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Missile Class Definition 
//====================================================================
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "spriteManager.h"
#include "alien.h"

//====================================================================
// The missile class has all of the logic for keeping up with a 
// single missile.
class missile {
private:
	Sprite missileSprite;    // holds the sprite for the missile returned by the spriteManager
	const float DISTANCE = 10.0; // the amount the missile moves in each increment 

public:
	missile(SpriteManager *text, float x, float y);

	void move();
	void draw(RenderWindow &window);

	Vector2f getPosition();
	FloatRect getBounds();
};
