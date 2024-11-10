// VIEWMODEL.h
#ifndef VIEWMODEL_H // include guard
#define VIEWMODEL_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "character.h"
#include "powerUp.h"
#include "powerUp.cpp"
#include "Boss.h"
#include "gamemap.h"
#include "gamemap.cpp"
#include "room.cpp"

class ViewModel
{
public:
    Character character = Character(3, 5, 1);
    static const int TotalHealth = 3;
    sf::Sprite health[TotalHealth];
    Player player;
    Enemy enemy;
    Boss boss;
    Gamemap map;
    Room* map_info;
    ViewModel();
    ViewModel(int roomNum, int enemyHeal, int enemyType);
    int draw(sf::RenderWindow &window);
    static const int bulletNumber = 25;
    static const int enemyNumber = 9;
    static const int powerNumber = 4;
    Enemy enemies[enemyNumber];
    
    Bullet bullets[bulletNumber];
    powerUp pUps[9];
    int bulletCount = 0;
    int bulletFrame = 0;
    static const int bulletFrameLimit = 7;
    int bulletSpeed = 5;
    int damageTimer = 0;
    int damagePosition[2] = {0, 0};
    std::string rooms[9] = {"room0012.png", "room0015.png", "room0010.png",
                            "room0009.png", "room0000.png", "room0008.png",
                            "room0011.png", "room0007.png", "room0013.png"};
    int enemyType = 0;
    int enemyHealth = 1;
    int bossHealth = 10;
    int enemyCount = enemyNumber;
    int roomNumber = 0;
    int score = 0;
    bool newRoom=true;
    int warningTimer=10;
};

#endif /* VIEWMODEL_H */