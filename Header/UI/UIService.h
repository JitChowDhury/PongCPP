#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

// Namespace for UI-related classes
namespace UI
{
    // UIService class: Manages the display of player scores in the Pong game
    class UIService
    {
    private:
        // Font and Text
        Font font;                    // Font for displaying scores
        Text left_score_text;         // Text for Player 1's score (left side)
        Text right_score_text;        // Text for Player 2's score (right side)

        // File Path
        string texture_path = "Assets/Fonts/VarelaRound-Regular.ttf"; // Path to font file

        // Text Configuration
        int font_size = 40;           // Font size for score text
        Color font_color = Color::White; // Font color for score text
        string initial_string = "00"; // Initial score display (two digits)

        // Score Positions
        float left_score_postion_x = 570.0f; // X-position for Player 1's score
        float left_score_postion_y = 30.0f;  // Y-position for Player 1's score
        float right_score_position_x = 670.0f; // X-position for Player 2's score
        float right_score_position_y = 30.0f;  // Y-position for Player 2's score

        // Scores
        int player1_score = 0;        // Player 1's current score
        int player2_score = 0;        // Player 2's current score

        // Private Functions
        string formatScore(int score); // Format score as two-digit string (e.g., "05")
        void loadFontTexture();       // Load font from file
        void createLeftScoreText();   // Set up Player 1's score text
        void createRightScoreText();  // Set up Player 2's score text

    public:
        // Constructor
        UIService();                  // Initialize UI components

        // Score Management
        void incrementPlayer1Score(); // Increment Player 1's score
        void incrementPlayer2Score(); // Increment Player 2's score

        // Game Logic
        void update();                // Update score display text
        void render(RenderWindow* game_window); // Draw scores to the window
    };
}