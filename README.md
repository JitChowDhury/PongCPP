🎮 Pong
Pong is a classic two-player arcade game where each player controls a paddle to hit a ball back and forth. Score points by getting the ball past your opponent’s paddle. This version includes sound effects, background music, and a live score display.

🛠️ Features
2-player paddle-based gameplay
Realistic ball physics
Sound effects and background music
Score display with custom font
Smooth 2-second game start delay

📦 Dependencies
SFML 2.5.x or newer

C++11 compatible compiler

Assets:
VarelaRound-Regular.ttf (font)
Pong_bgm.mp3 (background music)
Ball_Bounce.wav (sound effect)
Ball.png (ball sprite)

🚀 Installation
🔧 Pre-Built (Windows x64)
Go to the Releases section.
Download Pong-Release.zip.
Extract the archive.
Run Pong.exe.

🛠️ Build from Source

# Clone the repository
git clone https://github.com/yourusername/pong.git
cd pong

# Install SFML (Linux example)
sudo apt install libsfml-dev

# Build using CMake
mkdir build && cd build
cmake ..
cmake --build .

# Run the game
./Pong   # or Pong.exe on Windows

# Clone the repository
git clone (https://github.com/JitChowDhury/PongCPP.git)
cd pong
# Install SFML (Linux example)
sudo apt install libsfml-dev
# Build using CMake
mkdir build && cd build
cmake ..
cmake --build .
# Run the game
./Pong   # or Pong.exe on Windows

🎮 How to Play
Controls:
Player 1: W (Up), S (Down)
Player 2: Up Arrow (Up), Down Arrow (Down)
Exit: Close the game window

Scoring:
Ball passes left edge → Player 2 scores
Ball passes right edge → Player 1 scores
Game starts after a 2-second countdown. The ball bounces off the paddles and the top/bottom edges of the screen.
