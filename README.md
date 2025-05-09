Pong

Pong is a two-player game where you control paddles to hit a ball. Score by getting the ball past your opponent’s paddle. Features sound effects, music, and a score display.

Dependencies





SFML 2.5.x+



C++11 compiler



Assets: VarelaRound-Regular.ttf, Pong_bgm.mp3, Ball_Bounce.wav, Ball.png

Installation

Pre-Built (Windows x64)





Go to Releases.



Download Pong-Release.zip.



Extract and run Pong.exe.

Build from Source





Clone: git clone https://github.com/yourusername/pong.git



Install SFML (e.g., sudo apt install libsfml-dev on Linux).



Build: Use CMake or your IDE (e.g., cmake .. && cmake --build .).



Run: ./Pong (or Pong.exe on Windows).

How to Play





Controls:





Player 1: W (Up), S (Down).



Player 2: Up Arrow (Up), Down Arrow (Down).



Close window to exit.



Scoring:





Ball past left: Player 2 scores.



Ball past right: Player 1 scores.



Ball starts after a 2-second delay, bounces off paddles and top/bottom boundaries.
