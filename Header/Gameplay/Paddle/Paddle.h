#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

// Namespace for gameplay-related classes
namespace Gameplay
{
    // Paddle class: Manages a player's paddle, its movement, and rendering
    class Paddle
    {
    private:
        // Paddle Appearance
        RectangleShape paddle_sprite;    // Rectangle shape for the paddle

        // Paddle Dimensions
        const float paddle_width = 20.0f;  // Paddle width
        const float paddle_height = 140.0f; // Paddle height

        // Movement
        float paddleSpeed = 0.8f;          // Movement speed (pixels per frame)
        float topBoundary = 20.0f;         // Top limit for paddle movement
        float bottomBoundary = 700.0f;     // Bottom limit for paddle movement

        // Private Functions
        void createPaddle(float position_x, float position_y); // Set up paddle size and position
        void movePaddle(bool move_up_key_pressed, bool move_down_key_pressed); // Move paddle based on input

    public:
        // Constructor
        Paddle(float position_x, float position_y); // Initialize paddle at given position

        // Accessor
        RectangleShape getPaddleSprite(); // Get paddle shape for collision detection

        // Reset
        void reset(float position_x, float position_y); // Reset paddle position (not implemented)

        // Game Logic
        void update(bool move_up_key_pressed, bool move_down_key_pressed); // Update paddle position
        void render(RenderWindow* game_window); // Draw paddle to the window
    };
}