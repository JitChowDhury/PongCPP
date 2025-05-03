#include "../../Header/Event/EventManager.h"

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
		}

	}

	bool EventManager::isKeyPressed(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}


}