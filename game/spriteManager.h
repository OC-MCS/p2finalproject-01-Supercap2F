//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: SpriteManager Class Definition
//====================================================================
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;

//====================================================================
// The SpriteManager class keeps track of loading all of the sprites
// used in the game. 
class SpriteManager {
private:
	Texture missileTexture;
	Sprite missileSprite;

	Texture shipTexture;
	Sprite shipSprite;
	
	Texture backgroundTexture;
	Sprite backgroundSprite;

	Texture alienTexture;
	Sprite alienSprite;

	Texture alienTexture2;
	Sprite alienSprite2;

	Texture bombTexture;
	Sprite bombSprite;

	Texture bombTexture2;
	Sprite bombSprite2;
public:
	// constructor loads all textures
	SpriteManager();

	Sprite getMissileSprite();
	Sprite getShipSprite();
	Sprite getBackgroundSprite();

	Sprite getAlienSpriteLvl1();
	Sprite getAlienSpriteLvl2();

	Sprite getBombSpriteLvl1();
	Sprite getBombSpriteLvl2();

};