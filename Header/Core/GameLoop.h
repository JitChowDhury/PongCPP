// Prevent multiple includes
#pragma once
// Include SFML graphics (for RenderWindow)
#include <SFML/Graphics.hpp>
// Include headers for GameWindowManager and EventManager
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"
// Use namespaces for SFML, Core, Event, and std
using namespace sf;
using namespace Core;
using namespace Event;
using namespace std;
using namespace Gameplay;

// Core namespace for game classes
namespace Core
{
    // GameLoop class: manages game loop
    class GameLoop
    {
    private:
        // Pointers to window and event managers (has-a relationship)
        GameWindowManager* game_window_manager;
        EventManager* event_manager;
        GameplayManager* gameplay_manager;
    public:
        // Set up game
        void initialize();
        // Check if window is open
        bool isGameRunning();
        // Process inputs
        void pollEvent();
        // Update game state
        void update();
        // Draw graphics
        void render();
    };
}