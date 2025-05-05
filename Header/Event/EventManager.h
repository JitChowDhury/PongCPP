// Prevent multiple includes
#pragma once
// Include SFML graphics for Event, Keyboard, Mouse
#include <SFML/Graphics.hpp>

// Event namespace
namespace Event
{
    // EventManager class: handles user input
    class EventManager
    {
    public:
        // Process events (e.g., close, key press)
        void pollEvents(sf::RenderWindow* game_window);
        // Check key press
        bool isKeyPressed(sf::Keyboard::Key key);
        // Check mouse click
        bool isLeftMouseButtonClicked();
    };
}