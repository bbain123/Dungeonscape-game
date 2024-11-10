// MAINWINDOW.h
#ifndef MAINWINDOW_H // include guard
#define MAINWINDOW_H
#include <SFML/Graphics.hpp>
#include "TitleScreen.cpp"
#include "ViewModel.cpp"
#include "GameOver.cpp"

class MainWindow
{
private:
    sf::RenderWindow &m_window;
    int win = -1;

public:
    enum ScreenState
    {
        SplashScreen,
        MainGame,
        GameOverScreen,
        Exit
    };
    ScreenState state;
    TitleScreen titlescreen;
    ViewModel gamescreen;
    GameOver gameover;
    bool musicOn = false;

public:
    MainWindow(sf::RenderWindow &window);
    void run();

private:
    void updateScreen();
    void draw(sf::RenderWindow &window);
};

#endif /* MAINWINDOW_H */