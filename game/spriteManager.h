#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;

class SpriteManager {
private:
	Texture missileTexture;
	Sprite missileSprite;

	Texture shipTexture;
	Sprite shipSprite;
	
	Texture backgroundTexture;
	Sprite backgroundSprite;
public:

	// constructor loads all textures
	SpriteManager();

	Sprite getMissileSprite();
	Sprite getShipSprite();
	Sprite getBackgroundSprite();

};