#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include "../../Header/Utility/TimeService.h"
#include "../../Header/Sound/SoundManager.h"
using namespace sf;
using namespace std;
using namespace Utility;
using namespace Sound;

// Namespace for gameplay-related classes
namespace Gameplay
{
    // Enum for ball states: Idle (waiting after reset) or Moving (active movement)
    enum class BallState
    {
        Idle,    // Ball is stationary, waiting for delay to end
        Moving   // Ball is actively moving across the screen
    };

    // Ball class: Manages the ball's appearance, movement, collisions, and rendering in the Pong game
    class Ball
    {
    private:
        // Ball Appearance
        Texture pong_ball_texture;      // Texture for the ball sprite
        Sprite pong_ball_sprite;        // Sprite to display the ball

        // File Path
        string texture_path = "Assets/Textures/Ball.png"; // Path to ball texture file

        // Scaling
        const float scale_x = 0.06f;    // Scale factor for ball width (6% of original)
        const float scale_y = 0.06f;    // Scale factor for ball height (6% of original)

        // Initial Position
        const float position_x = 615.0f; // Starting x-position (center of 1280px window)
        const float position_y = 335.0f; // Starting y-position (slightly below center of 720px window)

        bool had_left_collison = false;
        bool had_right_collison = false;

        // Movement
        Vector2f velocity;              // Velocity vector (x, y) for ball movement
        const float ball_speed = 5.0f;  // Base speed of the ball (pixels per second)
        const float speed_multiplier = 100.0f; // Multiplier to adjust speed for gameplay feel

        // Delay State
        float delay_duration = 2.0f;    // Delay (seconds) before ball starts moving after reset
        BallState current_state = BallState::Idle; // Current state (starts as Idle)
        float elapsed_delay_time = 0.0f; // Time elapsed since last reset

        // Play Area Boundaries
        const float top_boundary = 20.0f;    // Top edge of play area (below top boundary graphic)
        const float bottom_boundary = 700.0f; // Bottom edge of play area (above bottom boundary graphic)
        const float left_boundary = 0.0f;    // Left edge of play area
        const float right_boundary = 1280.0f; // Right edge of play area

        // Private Functions
        void loadTexture();          // Load the ball texture from file
        void initializeVariables();  // Set up sprite, scale, position, and initial velocity
        void reset();                // Reset ball to initial position and state
        void updateDelayTime(float deltaTime); // Update delay timer before movement starts

    public:
        // Constructor
        Ball();                      // Initialize the ball

        // Game Logic Functions
        void move(TimeService* timeService); // Move the ball based on velocity and delta time
        void handleBoudaryCollision();       // Check and handle top/bottom boundary collisions
        void handlePaddleCollision(Paddle* player1, Paddle* player2); // Check and handle paddle collisions
        void handleOutofBoundCollision();    // Check if ball goes out of bounds (left/right)

        // Collision and Update
        void onCollision(Paddle* player1, Paddle* player2); // Handle all collision checks
        void update(Paddle* player1, Paddle* player2, TimeService* timeService); // Update ball state

        bool isLeftCollisionOccurred();
        void updateLeftCollisionState(bool value);

        bool isRightCollisionOccurred();
        void updateRightCollisionState(bool value);

        // Rendering
        void render(RenderWindow* game_window); // Draw the ball to the window
    };
}