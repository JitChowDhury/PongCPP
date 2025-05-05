// Include EventManager header
#include "../../Header/Event/EventManager.h"
// Include iostream for console output
#include <iostream>

// Event namespace
namespace Event
{
    // Process user inputs
    void EventManager::pollEvents(sf::RenderWindow* game_window)
    {
        sf::Event event;
        // Check all events
        while (game_window->pollEvent(event))
        {
            // Close window if "X" clicked
            if (event.type == sf::Event::Closed)
                game_window->close();
            // Close window if Escape pressed
            if (isKeyPressed(sf::Keyboard::Escape))
                game_window->close();
            // Print mouse click position
            if (isLeftMouseButtonClicked())
            {
                sf::Vector2i position = sf::Mouse::getPosition(*game_window);
                std::cout << "Left mouse click at: " << position.x << ", " << position.y << std::endl;
            }
        }
    }
    // Check if key is pressed
    bool EventManager::isKeyPressed(sf::Keyboard::Key key)
    {
        return sf::Keyboard::isKeyPressed(key);
    }
    // Check if left mouse button is clicked
    bool EventManager::isLeftMouseButtonClicked()
    {
        return sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }
}