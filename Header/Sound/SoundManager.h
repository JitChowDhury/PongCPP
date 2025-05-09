#pragma once

#include <SFML/Audio.hpp>
#include <string>

// Namespace for sound-related classes
namespace Sound
{
    // Enum for different sound effect types
    enum class SoundType
    {
        BALL_BOUNCE    // Sound played when the ball bounces off a paddle or boundary
    };

    // SoundManager class: Manages sound effects and background music for the game
    class SoundManager
    {
    private:
        // Static Sound Resources
        static sf::Music backgroundMusic;      // Background music for the game
        static sf::Sound soundEffect;          // Sound effect player
        static sf::SoundBuffer ballBounce;     // Buffer for ball bounce sound effect

        // Configuration
        static float backgroundMusicVolume;    // Volume level for background music (0-100)
        static const std::string bgmPath;      // File path to background music ("Assets/Sounds/Pong_bgm.mp3")
        static const std::string ballBouncePath; // File path to ball bounce sound ("Assets/Sounds/Ball_Bounce.wav")

    public:
        // Static Public Functions
        static void Initialize();              // Initialize sound resources (load files)
        static void PlaySoundEffect(SoundType soundType); // Play a specific sound effect
        static void PlayBackgroundMusic();     // Play the background music on a loop

    private:
        // Private Helper Function
        static void LoadSoundFromFile();       // Load sound files into buffers and music
    };
}