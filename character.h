// CHARACTER.h
#ifndef CHARACTER_H // include guard
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>
class Character
{
private:
    int health;
    int speed;
    int strength;
    int totalHealth;

public:
    Character(int h, int sp, int st);
    Character();
    int getHealth();
    int getSpeed();
    int getStrength();
    void setHealth(int health);
    void setSpeed(int speed);
    void setStrength(int strength);
    void setTotalHealth(int totalHealth);
    int getTotalHealth();
};

#endif /* CHARACTER_H */