#include "../../Header/Sound/SoundManager.h"
#include <iostream>

namespace Sound
{
    // Define static members
    sf::Music SoundManager::backgroundMusic;      // Background music object
    sf::SoundBuffer SoundManager::ballBounce;     // Buffer for ball bounce sound
    sf::Sound SoundManager::soundEffect;          // Sound effect player

    const std::string SoundManager::ballBouncePath = "Assets/Sounds/Ball_Bounce.wav"; // Path to ball bounce sound file
    const std::string SoundManager::bgmPath = "Assets/Sounds/Pong_bgm.mp3";           // Path to background music file

    float SoundManager::backgroundMusicVolume = 50.0f; // Default volume (50%)

    // Initialize sound resources by loading files
    void SoundManager::Initialize()
    {
        LoadSoundFromFile();
    }

    // Load sound files into buffers and music, log errors if loading fails
    void SoundManager::LoadSoundFromFile()
    {
        // Load ball bounce sound effect
        if (!ballBounce.loadFromFile(ballBouncePath))
            std::cerr << "Error loading sound file: " << ballBouncePath << std::endl;

        // Load background music
        if (!backgroundMusic.openFromFile(bgmPath))
            std::cerr << "Error loading background music file: " << bgmPath << std::endl;
    }

    // Play a sound effect based on the specified type
    void SoundManager::PlaySoundEffect(SoundType soundType)
    {
        switch (soundType)
        {
        case SoundType::BALL_BOUNCE:
            soundEffect.setBuffer(ballBounce); // Set ball bounce sound buffer
            break;
        default:
            std::cerr << "Invalid sound type" << std::endl; // Log error for unknown sound type
            return;
        }

        soundEffect.play(); // Play the selected sound effect
    }

    // Play background music on a loop with configured volume
    void SoundManager::PlayBackgroundMusic()
    {
        backgroundMusic.setLoop(true);              // Loop the music indefinitely
        backgroundMusic.setVolume(backgroundMusicVolume); // Set volume (default 50%)
        backgroundMusic.play();                     // Start playing the music
    }
}