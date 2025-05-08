#pragma once

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

    // Load the ball texture from file
    void Ball::loadTexture()
    {
        pong_ball_texture.loadFromFile(texture_path); // Load texture from "Assets/Textures/Ball.png"
    }

    // Initialize ball sprite with texture, scale, position, and velocity
    void Ball::initializeVariables()
    {
        pong_ball_sprite.setTexture(pong_ball_texture);  // Link texture to sprite
        pong_ball_sprite.setScale(scale_x, scale_y);     // Scale to 6% of original size (0.06x)
        pong_ball_sprite.setPosition(position_x, position_y); // Start at center (615, 325)

        velocity = Vector2f(ball_speed, ball_speed);     // Initial velocity (0.25, 0.25) for right-down movement
    }

    // Reset ball to center position with initial velocity and state
    void Ball::reset()
    {
        pong_ball_sprite.setPosition(position_x, position_y); // Reset to center (615, 325)
        velocity = Vector2f(ball_speed, ball_speed);     // Reset velocity to right-down (0.25, 0.25)
        current_state = BallState::Idle;                 // Set state to Idle for delay before moving
        elapsed_delay_time = 0.0f;                       // Reset delay timer
    }

    // Update delay timer before the ball starts moving
    void Ball::updateDelayTime(float deltaTime)
    {
        if (current_state == BallState::Idle)
        {
            elapsed_delay_time += deltaTime;             // Increment time since reset
            if (elapsed_delay_time >= delay_duration)    // Check if delay duration (e.g., 1 second) is reached
            {
                current_state = BallState::Moving;       // Start moving after delay
            }
            else
            {
                return;                                  // Keep waiting during delay
            }
        }
    }

    // Move the ball based on velocity, adjusted by delta time and speed multiplier
    void Ball::move(TimeService* timeService)
    {
        updateDelayTime(timeService->getDeltaTime());    // Handle delay before moving

        if (current_state == BallState::Moving)          // Only move if in Moving state
        {
            // Move sprite: velocity * deltaTime * speed_multiplier ensures frame-rate independent movement
            pong_ball_sprite.move(velocity * timeService->getDeltaTime() * speed_multiplier);
            // Example: velocity (0.25, 0.25), deltaTime 0.016s (60 FPS), speed_multiplier 1.0
            // Moves 0.25 * 0.016 * 1.0 = 0.004 pixels per frame in x and y
        }
    }

    // Check and handle collision with top/bottom boundaries, reversing vertical direction
    void Ball::handleBoudaryCollision()
    {
        FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds(); // Get ball's bounding box

        // Hit top boundary while moving up, or bottom boundary while moving down
        if ((ball_bounds.top <= top_boundary && velocity.y < 0) ||
            (ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
        {
            velocity.y = -velocity.y;  // Reverse vertical direction (e.g., 0.25 to -0.25)
        }
    }

    // Check and handle collision with paddles, reversing horizontal direction
    void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
    {
        // Get paddle shapes for collision detection
        const RectangleShape& player1Paddle = player1->getPaddleSprite();
        const RectangleShape& player2Paddle = player2->getPaddleSprite();

        // Get bounding boxes of ball and paddles
        FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
        FloatRect Player1PaddleBounds = player1Paddle.getGlobalBounds();
        FloatRect player2PaddleBounds = player2Paddle.getGlobalBounds();

        // Bounce off Player 1's paddle (left side) if moving left
        if (ball_bounds.intersects(Player1PaddleBounds) && velocity.x < 0)
        {
            velocity.x = -velocity.x;  // Reverse horizontal direction (e.g., -0.25 to 0.25)
        }

        // Bounce off Player 2's paddle (right side) if moving right
        if (ball_bounds.intersects(player2PaddleBounds) && velocity.x > 0)
        {
            velocity.x = -velocity.x;  // Reverse horizontal direction (e.g., 0.25 to -0.25)
        }
    }

    bool Ball::isLeftCollisionOccurred()
    {
        return had_left_collison;
    }

    void Ball::updateLeftCollisionState(bool value)
    {
        had_left_collison = value;
    }

    bool Ball::isRightCollisionOccurred()
    {
        return had_right_collison;
    }

    void Ball::updateRightCollisionState(bool value)
    {
        had_right_collison = value;
    }

    // Check if ball goes out of bounds (left/right), reset if true
    void Ball::handleOutofBoundCollision()
    {
        FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds(); // Get ball's bounding box

        // Ball goes past left boundary (Player 2 scores)
        if (ball_bounds.left <= left_boundary)
        {
            updateLeftCollisionState(true);
            reset(); // Reset ball to center
        }
        // Ball goes past right boundary (Player 1 scores)
        else if (ball_bounds.left + ball_bounds.width >= right_boundary)
        {
            updateRightCollisionState(true);
            reset(); // Reset ball to center
        }
    }

    // Handle all collisions (boundaries, paddles, out-of-bounds)
    void Ball::onCollision(Paddle* player1, Paddle* player2)
    {
        handleBoudaryCollision();      // Check top/bottom walls
        handlePaddleCollision(player1, player2); // Check paddle hits
        handleOutofBoundCollision();   // Check left/right out-of-bounds
    }

    // Update ball: Move and check for collisions
    void Ball::update(Paddle* player1, Paddle* player2, TimeService* timeService)
    {
        move(timeService);             // Update position based on velocity and time
        onCollision(player1, player2); // Handle collisions
    }

    // Draw the ball to the game window
    void Ball::render(RenderWindow* game_window)
    {
        game_window->draw(pong_ball_sprite);
    }
}