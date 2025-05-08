#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Paddle/Paddle.h"
using namespace sf;

// Namespace for gameplay-related classes
namespace Gameplay
{
    // Ball class: Manages the ball's movement, collisions, and rendering in the Pong game
    class Ball
    {
    private:
        // Ball Appearance
        Texture pong_ball_texture;      // Texture for the ball sprite
        Sprite pong_ball_sprite;        // Sprite to display the ball
        const std::string texture_path = "Assets/Textures/Ball.png";

        // Movement
        float ball_speed = 0.25f;       // Speed of the ball (pixels per frame)
        Vector2f velocity = Vector2f(ball_speed, ball_speed); // Initial velocity (right-down)

        // Scaling
        const float scale_x = 0.06f;    // Scale factor for ball width (6% of original)
        const float scale_y = 0.06f;    // Scale factor for ball height (6% of original)

        // Initial Position
        const float position_x = 615.0f; // Starting x-position (center of 1280px window)
        const float position_y = 325.0f; // Starting y-position (center of 720px window)

        // Play Area Boundaries
        const float left_boundary = 0.0f;    // Left edge of the play area
        const float right_boundary = 1280.0f; // Right edge of the play area
        const float top_boundary = 0.0f;     // Top edge of the play area
        const float bottom_boundary = 720.0f; // Bottom edge of the play area

        // Reset Position
        const float center_position_x = 615.0f; // Center x-position for resetting
        const float center_position_y = 325.0f; // Center y-position for resetting

        // Private Functions
        void loadTexture();        // Load the ball texture from file
        void initializeVariables(); // Set up sprite, scale, and position
        void move();               // Update ball position based on velocity

    public:
        // Constructor
        Ball();                    // Initialize the ball

        // Game Logic Functions
        void update(Paddle* player1, Paddle* player2); // Update ball movement and collisions
        void onCollision(Paddle* player1, Paddle* player2); // Handle all collision checks
        void handlePaddleCollision(Paddle* player1, Paddle* player2); // Check and handle paddle collisions
        void handleOutofBoundCollision(); // Check if ball goes out of bounds (left/right)
        void handleBoudaryCollision();    // Check and handle top/bottom boundary collisions
        void reset();                     // Reset ball to center position

        // Rendering
        void render(RenderWindow* game_window); // Draw the ball to the window
    };
}