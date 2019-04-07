//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "spriteManager.h"
using namespace sf; 
#include "ship.h"

//============================================================
// YOUR HEADER WITH YOUR NAME GOES HERE. PLEASE DO NOT FORGET THIS
//============================================================
int main()
{
	// ======== basic window setup
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);


	// ======== setup the sprite manager
	SpriteManager spriteManager;


	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Sprite background;
	background = spriteManager.getBackgroundSprite();

	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	//background.setScale(1.5, 1.5);

	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.15f;
	Ship ship(background, spriteManager, shipX, shipY);
	
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					ship.fireMissile();
				}
				
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);

		ship.moveShip();
		ship.updateMissiles();

		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)
		ship.draw(window);
		
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

