#include"../../Header/Gameplay/Paddle/Paddle.h"
namespace Gameplay
{
	Paddle::Paddle(float pos_x, float pos_y)
	{
		paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
		paddle_sprite.setPosition(pos_x, pos_y);
	}
	
	void Paddle::render(RenderWindow* game_window)
	{
		game_window->draw(paddle_sprite);
	}
}