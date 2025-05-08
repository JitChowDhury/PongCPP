#include "../../Header/Gameplay/Boundary/Boundary.h"
using namespace sf;

namespace Gameplay
{
    // Set up top boundary with size, position, and color
    void Boundary::createTopBoundary()
    {
        topBoundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height)); // 1280x20
        topBoundary.setPosition(top_position_x, top_position_y); // (0, 0)
        topBoundary.setFillColor(boundary_color); // Blue
    }

    // Set up bottom boundary with size, position, and color
    void Boundary::createBottomBoundary()
    {
        bottomBoundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height)); // 1280x20
        bottomBoundary.setPosition(bottom_position_x, bottom_position_y); // (0, 700)
        bottomBoundary.setFillColor(boundary_color); // Blue
    }

    // Set up left boundary with size, position, and color
    void Boundary::createLeftBoundary()
    {
        leftBoundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height)); // 20x720
        leftBoundary.setPosition(left_position_x, left_position_y); // (0, 0)
        leftBoundary.setFillColor(boundary_color); // Blue
    }

    // Set up right boundary with size, position, and color
    void Boundary::createRightBoundary()
    {
        rightBoundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height)); // 20x720
        rightBoundary.setPosition(right_position_x, right_position_y); // (1260, 0)
        rightBoundary.setFillColor(boundary_color); // Blue
    }

    // Set up center line with size, position, and color
    void Boundary::createCenterLine()
    {
        centerLine.setSize(Vector2f(center_line_width, center_line_height)); // 10x680
        centerLine.setPosition(center_line_position_x, center_line_position_y); // (640, 20)
        centerLine.setFillColor(center_line_color); // White
    }

    // Constructor: Initialize all boundaries and center line
    Boundary::Boundary()
    {
        createTopBoundary();
        createBottomBoundary();
        createLeftBoundary();
        createRightBoundary();
        createCenterLine();
    }

    // Update boundaries (placeholder, currently empty)
    void Boundary::update()
    {
        // No dynamic updates needed for static boundaries
    }

    // Draw all boundaries and center line to the game window
    void Boundary::render(RenderWindow* game_window)
    {
        game_window->draw(topBoundary);
        game_window->draw(bottomBoundary);
        game_window->draw(leftBoundary);
        game_window->draw(rightBoundary);
        game_window->draw(centerLine);
    }
}