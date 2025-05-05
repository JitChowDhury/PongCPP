// Include GameWindowManager header
#include "../../Header/Core/GameWindowManager.h"
// Include string for game_title
#include <string>
// Core namespace
namespace Core
{
    // Set up window
    void GameWindowManager::initialize()
    {
        game_window = new RenderWindow();
        createGameWindow();
    }
    // Create window with size, title
    void GameWindowManager::createGameWindow()
    {
        game_window->create(
            sf::VideoMode(1280, 720), // Fixed size
            game_title,
            sf::Style::Default
        );
    }
    // Check if window is open
    bool GameWindowManager::isGameRunning()
    {
        return game_window->isOpen();
    }
    // Draw graphics (clear, display)
    void GameWindowManager::render()
    {
        game_window->clear(sf::Color(200, 50, 50, 255));
        game_window->display();
    }
    // Clear window
    void GameWindowManager::clearGameWindow()
    {
        game_window->clear();
    }
    // Display window
    void GameWindowManager::displayGameWindow()
    {
        game_window->display();
    }
    // Get window pointer
    RenderWindow* GameWindowManager::getGameWindow()
    {
        return game_window;
    }
}