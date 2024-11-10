#include "character.h"
/**
 * @brief Initializes a character with health h, speed sp, and strength st
 * @param h - Health of the character
 * @param sp - Speed of the character
 * @param st - Strength of the character
 * @author William Brewer
 */

Character::Character(int h, int sp, int st)
{
    // Initializations
    this->totalHealth = h;
    this->health = h;
    this->speed = sp;
    this->strength = st;
}
/**
 * @brief Initializes a character with health, speed, and strength to 0.
 * @author William Brewer
 */
Character::Character()
{
    this->health = 0;
    this->speed = 0;
    this->strength = 0;
}
/**
 * @brief Returns the character's health.
 * @return health - Health of the character
 * @author William Brewer
 */
int Character::getHealth()
{
    return this->health;
}
/**
 * @brief Returns the total health of the character.
 * @return totalHealth - Total health of the character
 * @author William Brewer
 */
int Character::getTotalHealth()
{
    return this->totalHealth;
}
/**
 * @brief Returns the character's speed.
 * @return speed - Speed of the character
 * @author William Brewer
 */
int Character::getSpeed()
{
    return this->speed;
}
/**
 * @brief Returns the character's strength.
 * @return strength - Strength of the character
 * @author Brendan Bain
 */

int Character::getStrength()
{
    return this->strength;
}
/**
 * @brief Sets the character's health.
 * @param health - New health of the character
 * @author Brendan Bain
 */
void Character::setHealth(int health)
{
    this->health = health;
}
/**
 * @brief Sets the character's total health.
 * @param totalHealth - New health of the character
 * @author Brendan Bain
 */

void Character::setTotalHealth(int totalHealth)
{
    this->totalHealth = totalHealth;
}
/**
 * @brief Sets the character's speed.
 * @param speed - New speed of the character
 * @author Brendan Bain
 */
void Character::setSpeed(int speed)
{
    this->speed = speed;
}
/**
 * @brief Sets the character's strength.
 * @param strength - New strength of the character
 * @author Brendan Bain
 */

void Character::setStrength(int strength)
{
    this->strength = strength;
}
