#include "../../Header/UI/UIService.h"

namespace UI
{
    // Constructor: Initialize UI by loading font and setting up score texts
    UIService::UIService()
    {
        loadFontTexture();
        createLeftScoreText();
        createRightScoreText();
    }

    // Load font from file
    void UIService::loadFontTexture()
    {
        font.loadFromFile(texture_path); // Load font from "Assets/Fonts/VarelaRound-Regular.ttf"
    }

    // Set up Player 1's score text with font, size, color, and position
    void UIService::createLeftScoreText()
    {
        left_score_text.setFont(font);              // Set font for Player 1's score
        left_score_text.setString(initial_string);  // Initial score display ("00")
        left_score_text.setCharacterSize(font_size); // Set font size (40)
        left_score_text.setFillColor(font_color);   // Set color to white
        left_score_text.setPosition(left_score_postion_x, left_score_postion_y); // Position at (570, 30)
    }

    // Set up Player 2's score text with font, size, color, and position
    void UIService::createRightScoreText()
    {
        right_score_text.setFont(font);              // Set font for Player 2's score
        right_score_text.setString(initial_string);  // Initial score display ("00")
        right_score_text.setCharacterSize(font_size); // Set font size (40)
        right_score_text.setFillColor(font_color);   // Set color to white
        right_score_text.setPosition(right_score_position_x, right_score_position_y); // Position at (670, 30)
    }

    // Format score as a two-digit string (e.g., "05" for 5, "10" for 10)
    string UIService::formatScore(int score)
    {
        return (score < 10 ? "0" : "") + to_string(score); // Add leading zero if score < 10
    }

    // Increment Player 1's score by 1
    void UIService::incrementPlayer1Score()
    {
        player1_score++;
    }

    // Increment Player 2's score by 1
    void UIService::incrementPlayer2Score()
    {
        player2_score++;
    }

    // Update score display text with current scores
    void UIService::update()
    {
        left_score_text.setString(formatScore(player1_score));  // Update Player 1's score display
        right_score_text.setString(formatScore(player2_score)); // Update Player 2's score display
    }

    // Draw both score texts to the game window
    void UIService::render(RenderWindow* game_window)
    {
        game_window->draw(left_score_text);  // Draw Player 1's score
        game_window->draw(right_score_text); // Draw Player 2's score
    }
}