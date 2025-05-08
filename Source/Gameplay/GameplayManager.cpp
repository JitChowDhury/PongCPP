#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay
{

	GameplayManager::GameplayManager(EventManager* manager)
	{
		time_service->initialize();// Start our time tracking
		event_manager = manager;
	}
	void GameplayManager::render(RenderWindow* game_window)
	{
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);

		
	}
	void GameplayManager::update()
	{
		time_service->update();
		player1->update(event_manager->isKeyPressed(Keyboard::W), event_manager->isKeyPressed(Keyboard::S), time_service);
		player2->update(event_manager->isKeyPressed(Keyboard::Up), event_manager->isKeyPressed(Keyboard::Down), time_service);
		ball->update(player1, player2, time_service);
	}


}