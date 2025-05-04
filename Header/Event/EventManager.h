#pragma once

#include<SFML\Graphics.hpp>

namespace Event
{
	class EventManager
	{
	public:
		void pollEvents(sf::RenderWindow* game_window);//process all events
		bool isKeyPressed(sf::Keyboard::Key key);//check specific key
		bool isLeftMouseButtonClicked();
	};
}