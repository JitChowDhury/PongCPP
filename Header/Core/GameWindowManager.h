// Prevent multiple includes
#pragma once
// Include SFML graphics for RenderWindow
#include <SFML/Graphics.hpp>
// Use sf namespace
using namespace sf;

// Core namespace
namespace Core
{
    // GameWindowManager class: manages game window
    class GameWindowManager
    {
    private:
        // Window dimensions and title
        int game_window_width = 1280;
        int game_window_height = 720;
        std::string game_title = "SFML-Pong!";
        // Pointer to window
        RenderWindow* game_window;
        // Create window
        void createGameWindow();
    public:
        // Set up window
        void initialize();
        // Get window pointer
        RenderWindow* getGameWindow();
        // Check if window is open
        bool isGameRunning();
        // Draw graphics
        void render();
        // Clear window
        void clearGameWindow();
        // Display window
        void displayGameWindow();
    };
}