#include "../../Header/Gameplay/Paddle/Paddle.h"
using namespace sf;

namespace Gameplay
{
    // Constructor: Initialize paddle with given position
    Paddle::Paddle(float pos_x, float pos_y)
    {
        paddle_sprite.setSize(Vector2f(paddle_width, paddle_height)); // Set size to 20x140
        paddle_sprite.setPosition(pos_x, pos_y); // Set initial position
    }

    // Get paddle shape for collision detection
    RectangleShape Paddle::getPaddleSprite()
    {
        return paddle_sprite;
    }

    // Move paddle based on input, respecting boundaries
    void Paddle::movePaddle(bool move_up_key_pressed, bool move_down_key_pressed)
    {
        // Move up if key pressed and not at top boundary
        if (move_up_key_pressed && paddle_sprite.getPosition().y > topBoundary)
        {
            paddle_sprite.move(0, -paddleSpeed); // Move up at 0.8 pixels/frame
        }
        // Move down if key pressed and not at bottom boundary
        if (move_down_key_pressed && paddle_sprite.getPosition().y + paddle_sprite.getSize().y < bottomBoundary)
        {
            paddle_sprite.move(0, paddleSpeed); // Move down at 0.8 pixels/frame
        }
    }

    // Update paddle position based on input
    void Paddle::update(bool move_up_key_pressed, bool move_down_key_pressed)
    {
        movePaddle(move_up_key_pressed, move_down_key_pressed);
    }

    // Draw paddle to the game window
    void Paddle::render(RenderWindow* game_window)
    {
        game_window->draw(paddle_sprite);
    }

    // Reset paddle position (not implemented in source)
    void Paddle::reset(float position_x, float position_y)
    {
        paddle_sprite.setPosition(position_x, position_y);
    }
}