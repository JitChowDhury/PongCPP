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
        SoundManager::Initialize();
        SoundManager::PlayBackgroundMusic();
        game_window_manager->initialize();
        gameplay_manager = new GameplayManager(event_manager);
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
        gameplay_manager->update();
    }
    // Draw graphics
    void GameLoop::render()
    {
        game_window_manager->clearGameWindow();
        //render the paddles and ball
        gameplay_manager->render(game_window_manager->getGameWindow());

        game_window_manager->displayGameWindow();
    }
}