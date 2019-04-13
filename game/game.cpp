//====================================================================
// Daniel Andresen
// Due April 13st, 2019
// Programming 2 / Final Project
// Description: Main Game Loop
//====================================================================
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "spriteManager.h"
using namespace sf; 
#include "ship.h"
#include "alienManager.h"
#include "gameManager.h"

//============================================================
// SPACE INVADERS - CREATED BY DANIEL ANDRESEN 
//============================================================
int main()
{
	// ======== basic window setup
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	SpriteManager spriteManager;

	// create an instance of the game manager for keeping up with game variabls 
	GameManager gameManager;

	// create the backgrond for the game 
	Sprite background;
	background = spriteManager.getBackgroundSprite();

	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.15f;
	Ship ship(background, spriteManager, shipX, shipY);
	
	// create the alien manager
	AlienManager alienManager(background, spriteManager, gameManager, ship);

	// main game loop
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed) {
				// fire missile if the space bar was pressed
				if (event.key.code == Keyboard::Space) {
					ship.fireMissile();
				}
			}

			// mouse released event: the mouse was clicked most likely on a menu button
			if (event.type == Event::MouseButtonReleased) {
				gameManager.mouseButtonReleased(window.mapPixelToCoords(Mouse::getPosition(window)));
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================
		window.clear(); // delete everything from the last frame
		
		// check if the main game is running and not the menu
		if (gameManager.isGameRunning()) { 
			// check if the next level was reached or the ship lost a life
			if (gameManager.resetLevel()) {
				alienManager.resetAliens(); // reset the number of aliens and their positions
				ship.resetShip();			// delete all of the missiles that are in the air
			}

			// draw background first, so everything that's drawn later 
			// will appear on top of background
			window.draw(background);

			// draw the ship on top of background 
			// (the ship from previous frame was erased when we drew background)
			ship.moveShip();
			ship.updateMissiles(); // move the missiles 
			ship.draw(window);

			// draw the aliens ontop of the background next
			alienManager.moveAliens(window);
			alienManager.drawAliens(window);

			// drop the bombs and draw them on the screen
			alienManager.dropBombs();
			alienManager.moveBombs(window);
			alienManager.drawBombs(window);

			// detect any collisions after moving all of the game elements
			alienManager.detectCollisions();

			// finally add the game data to the top left corner
			gameManager.displayData(window);
		}
		else { // menu is displayed 
			gameManager.updateMenu();
			gameManager.drawMenu(window);
		}

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

