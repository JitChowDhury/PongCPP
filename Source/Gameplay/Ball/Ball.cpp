#include "../../Header/Gameplay/Ball/Ball.h"
using namespace sf;

namespace Gameplay
{
    // Constructor: Initialize the ball by loading texture and setting up variables
    Ball::Ball()
    {
        loadTexture();
        initializeVariables();
    }

    // Load the ball texture from file, throw error if it fails
    void Ball::loadTexture()
    {
        if (!pong_ball_texture.loadFromFile(texture_path))
        {
            throw std::runtime_error("Failed to load ball texture!");
        }
    }

    // Initialize ball sprite with texture, scale, and position
    void Ball::initializeVariables()
    {
        pong_ball_sprite.setTexture(pong_ball_texture);  // Link texture to sprite
        pong_ball_sprite.setScale(scale_x, scale_y);     // Scale to 6% of original size
        pong_ball_sprite.setPosition(position_x, position_y); // Start at center (615, 325)
    }

    // Move the ball by adding velocity to its position
    void Ball::move()
    {
        pong_ball_sprite.move(velocity); // Moves at 0.25 pixels/frame in x and y
    }

    // Check and handle collision with paddles, reversing horizontal direction
    void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
    {
        // Get bounding boxes of ball and paddles
        const RectangleShape& player1Paddle = player1->getPaddleSprite();
        const RectangleShape& player2Paddle = player2->getPaddleSprite();

        FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
        FloatRect player1_bounds = player1Paddle.getGlobalBounds();
        FloatRect player2_bounds = player2Paddle.getGlobalBounds();

        // Bounce off Player 1's paddle (left side) if moving left
        if (ball_bounds.intersects(player1_bounds) && velocity.x < 0)
        {
            velocity.x = -velocity.x;  // Reverse horizontal direction (e.g., -0.25 to 0.25)
        }
        // Bounce off Player 2's paddle (right side) if moving right
        if (ball_bounds.intersects(player2_bounds) && velocity.x > 0)
        {
            velocity.x = -velocity.x;  // Reverse horizontal direction (e.g., 0.25 to -0.25)
        }
    }

    // Check if ball goes out of bounds (left/right), reset if true
    void Ball::handleOutofBoundCollision()
    {
        FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

        // Ball goes past left boundary (Player 2 scores)
        if (ball_bounds.left <= left_boundary)
        {
            reset();
        }
        // Ball goes past right boundary (Player 1 scores)
        else if (ball_bounds.left + ball_bounds.width >= right_boundary)
        {
            reset();
        }
    }

    // Check and handle collision with top/bottom boundaries, reversing vertical direction
    void Ball::handleBoudaryCollision()
    {
        FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

        // Hit top boundary while moving up, or bottom boundary while moving down
        if ((ball_bounds.top <= top_boundary && velocity.y < 0) ||
            (ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
        {
            velocity.y = -velocity.y;  // Reverse vertical direction (e.g., 0.25 to -0.25)
        }
    }

    // Reset ball to center position with initial velocity
    void Ball::reset()
    {
        pong_ball_sprite.setPosition(center_position_x, center_position_y); // Center (615, 325)
        velocity = Vector2f(ball_speed, ball_speed); // Reset to right-down movement
    }

    // Handle all collisions (boundaries, paddles, out-of-bounds)
    void Ball::onCollision(Paddle* player1, Paddle* player2)
    {
        handleBoudaryCollision();      // Top/bottom walls
        handlePaddleCollision(player1, player2); // Paddle hits
        handleOutofBoundCollision();   // Left/right out-of-bounds
    }

    // Update ball: Move and check for collisions
    void Ball::update(Paddle* player1, Paddle* player2)
    {
        move();
        onCollision(player1, player2);
    }

    // Draw the ball to the game window
    void Ball::render(RenderWindow* game_window)
    {
        game_window->draw(pong_ball_sprite);
    }
}