#include "../../Header/Event/EventManager.h"
#include<iostream>

namespace Event
{
	void EventManager::pollEvents(sf::RenderWindow* game_window)
	{
		sf::Event event;
		while (game_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				game_window->close();
			}

			//check for escape key
			if (isKeyPressed(sf::Keyboard::Escape))
			{
				game_window->close();
				
			}
			//Handle left mouse button click
			if (isLeftMouseButtonClicked())
			{
				sf::Vector2i position = sf::Mouse::getPosition(*game_window);
					//log the pos
					std::cout << "Left mouse clock at: " << position.x << " , " << position.y << std::endl;
			}
		}

	}

	bool EventManager::isKeyPressed(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}

	bool EventManager::isLeftMouseButtonClicked()
	{
		//detect if left mouse button is clicked
		return (sf::Mouse::isButtonPressed(sf::Mouse::Left));
	}


}