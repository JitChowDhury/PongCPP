#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
using namespace sf;
using namespace Core;

int main()
{
    GameWindowManager* game_window_manager = new GameWindowManager();
    game_window_manager->initialize();

    while (game_window_manager->isGameRunning())
    {
        
        game_window_manager->render();
    }

    return 0;
}