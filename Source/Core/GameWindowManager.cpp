#include "../../Header/Core/GameWindowManager.h"
#include<string>
namespace Core
{
	void GameWindowManager::initialize()
	{
		//Allocate memory for the render window object
		game_window = new RenderWindow();
		//set up the window with configured properties
		createGameWindow();

	}

	void GameWindowManager::createGameWindow() {

		// Create the window with specified dimensions and title
		game_window->create(
			sf::VideoMode(1320,720),//getscreenResolution
				game_title,//window title
					sf::Style::Default //Fullscreen mode
			);
	}

	bool GameWindowManager::isGameRunning() {
		// Return true if window is open, false if closed
		return game_window->isOpen();
	}

	void GameWindowManager::render() {
		// Clear window with orange color (R:200, G:50, B:50, A:255)
		game_window->clear(sf::Color(200, 50, 50, 255));

		//draw shapes, sprites, etc 

	// Display the changes
		game_window->display();
		
    }

	void GameWindowManager::clearGameWindow()
	{
		game_window->clear();
	}

	void GameWindowManager::displayGameWindow()
	{
		return game_window->display();
	}

	RenderWindow* GameWindowManager::getGameWindow() {
		return game_window;
	}
}


