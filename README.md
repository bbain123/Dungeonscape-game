
# Dungeonscape
A 2D rogue-like, top-down dungeon crawler video game developed in C++ for the Raspberry Pi platform. This game is designed to deliver a thrilling experience with procedurally generated dungeons, unique enemies, challenging bosses, and collectible power-ups. Players must conquer randomly generated levels, survive waves of enemies, gather power-ups, and defeat bosses to advance.

### Demo Video (Click the heart)
[![Dungeon Crawler Game Trailer](health.png)](https://youtu.be/2RPimxoHtgs)


## Features

### Core Gameplay
- **2D Dungeon Exploration**: Navigate through randomly generated dungeon levels.
- **Score System**: Score increases with each enemy defeated.
- **Power-Ups**: Collect power-ups scattered throughout the levels to enhance player abilities.
- **Character Control**: Movement controls allow players to navigate and explore freely.
- **Random Level Generation**: Each game session generates a new dungeon layout.
- **Boss Battles**: A boss appears at the end of each level; defeating it allows the player to proceed.
- **Music**: Background music enhances the immersive experience.
- **Combat**: Attack enemies using projectile attacks to clear the room.
- **User Interface**: Title screen, win and defeat screen.
- **Health System**: Players lose health when hit; game ends if health reaches zero.
- **Optimized Performance**: Game runs at an acceptable performance level, targeting over 30fps.

## Controls
- Start Game: Press ENTER on the title screen.
- Movement: Use WASD keys to move the player character.
- Attack: Use the arrow keys to fire projectiles in four directions.

## Setup Instructions

### Prerequisites
The game uses the **SFML** (Simple and Fast Multimedia Library) open-source game engine. Ensure SFML is installed on your system:

#### Linux
```sh
sudo apt-get install libsfml-dev
```

#### macOS (Using Homebrew)

```sh
brew install sfml
```

#### Building and Running the Game
To build and run the game, execute the following commands in your terminal:

```sh
g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
```
## License for Sprites
Sprites are licensed under CC BY-ND. Check out the creator's page [here](https://chr15m.itch.io/doodle-rogue-tileset).

