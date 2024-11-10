// GAME.h
#ifndef GAME_H // include guard
#define GAME_H

#include <SFML/Graphics.hpp>
#include "MainWindow.cpp"
#include "character.cpp"
#include <string>

class Game
{
public:
    int score;
    bool gameStatus;
    Character character;

    Game();
    ~Game();
    int run();
};

#endif /* GAME_H */