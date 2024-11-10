// TITLESCREEN.h
#ifndef TITLESCREEN_H // include guard
#define TITLESCREEN_H
#include <SFML/Graphics.hpp>

class TitleScreen
{
private:
    int soundLevel;

public:
    void draw(sf::RenderWindow &window);
};

#endif /* TITLESCREEN_H */