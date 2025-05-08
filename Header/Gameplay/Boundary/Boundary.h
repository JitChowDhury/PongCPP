#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

// Namespace for gameplay-related classes
namespace Gameplay
{
    // Boundary class: Defines the play area with top, bottom, left, right boundaries, and a center line
    class Boundary
    {
    private:
        // Boundary Shapes
        RectangleShape topBoundary;     // Top boundary of the play area
        RectangleShape bottomBoundary;  // Bottom boundary of the play area
        RectangleShape leftBoundary;    // Left boundary of the play area
        RectangleShape rightBoundary;   // Right boundary of the play area
        RectangleShape centerLine;      // Center line dividing the play area

        // Horizontal Boundary Dimensions
        const float horizontal_boundary_width = 1280.0f;  // Width of top/bottom boundaries
        const float horizontal_boundary_height = 20.0f;   // Height of top/bottom boundaries

        // Horizontal Boundary Positions
        const float top_position_x = 0.0f;    // Top boundary x-position
        const float top_position_y = 0.0f;    // Top boundary y-position
        const float bottom_position_x = 0.0f; // Bottom boundary x-position
        const float bottom_position_y = 700.0f; // Bottom boundary y-position

        // Vertical Boundary Dimensions
        const float vertical_boundary_width = 20.0f;   // Width of left/right boundaries
        const float vertical_boundary_height = 720.0f; // Height of left/right boundaries

        // Vertical Boundary Positions
        const float left_position_x = 0.0f;    // Left boundary x-position
        const float left_position_y = 0.0f;    // Left boundary y-position
        const float right_position_x = 1260.0f; // Right boundary x-position
        const float right_position_y = 0.0f;   // Right boundary y-position

        // Center Line Dimensions
        const float center_line_width = 10.0f;   // Width of center line
        const float center_line_height = 680.0f; // Height of center line

        // Center Line Position
        const float center_line_position_x = 640.0f; // Center line x-position (middle of screen)
        const float center_line_position_y = 20.0f;  // Center line y-position (below top boundary)

        // Colors
        const Color boundary_color = Color::Blue;    // Color of boundaries
        const Color center_line_color = Color::White; // Color of center line

        // Private Functions
        void createTopBoundary();    // Set up top boundary
        void createBottomBoundary(); // Set up bottom boundary
        void createLeftBoundary();   // Set up left boundary
        void createRightBoundary();  // Set up right boundary
        void createCenterLine();     // Set up center line

    public:
        // Constructor
        Boundary();                  // Initialize all boundaries and center line

        // Game Logic
        void update();               // Update boundaries (placeholder, currently empty)

        // Rendering
        void render(RenderWindow* game_window); // Draw boundaries and center line
    };
}