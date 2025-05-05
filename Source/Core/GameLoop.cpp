// Include GameLoop header
#include "../../Header/Core/GameLoop.h"

// Core namespace
namespace Core
{
    // Set up game
    void GameLoop::initialize()
    {
        // Create window and event managers
        game_window_manager = new GameWindowManager();
        event_manager = new EventManager();
        // Initialize window
        game_window_manager->initialize();
    }
    // Check if window is open
    bool GameLoop::isGameRunning()
    {
        return game_window_manager->isGameRunning();
    }
    // Process user inputs
    void GameLoop::pollEvent()
    {
        event_manager->pollEvents(game_window_manager->getGameWindow());
    }
    // Update game state (empty)
    void GameLoop::update()
    {
    }
    // Draw graphics
    void GameLoop::render()
    {
        game_window_manager->clearGameWindow();
        game_window_manager->displayGameWindow();
    }
}