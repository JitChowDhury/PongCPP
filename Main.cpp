// Include SFML graphics (for RenderWindow, used by other classes)
#include <SFML/Graphics.hpp>
// Include GameLoop header to use the GameLoop class
#include "../../Header/Core/GameLoop.h"
// Use sf namespace for SFML classes
using namespace sf;
// Use Core namespace for GameLoop
using namespace Core;

// Main function: where the program starts
int main()
{
    // Create GameLoop object with a pointer (manages the game)
    GameLoop* game_loop_manager = new GameLoop();
    // Initialize the game (sets up window, event manager)
    game_loop_manager->initialize();
    // Game loop: runs while window is open
    while (game_loop_manager->isGameRunning())
    {
        // Process user input (e.g., key presses)
        game_loop_manager->pollEvent();
        // Update game state (empty for now)
        game_loop_manager->update();
        // Draw graphics (clear and display window)
        game_loop_manager->render();
    }
    // Clean up to free memory
    delete game_loop_manager;
    // Exit program
    return 0;
}