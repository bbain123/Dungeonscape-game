#include <SFML/Graphics.hpp>
#include <string>

class Enemy
{
private:
    sf::Texture texture;

    int width = 128;
    int height = 128;
    bool animate = false;
    int frameCount = 0;
    int movespeed;
    bool empty = true;
    int enemyType = 0;

public:
    sf::Sprite enemy;
    std::string types[8][2] = {{"goblin128.png", "goblin128_move.png"}, {"bat128.png", "bat128_move.png"}, {"bear128.png", "bear128_move.png"}, {"demon128.png", "demon128_move.png"}, {"ghost128.png", "ghost128_move.png"}, {"skeleton128.png", "skeleton128_move.png"}, {"vampire128.png", "vampire128_move.png"}, {"wolf128.png", "wolf128_move.png"}};
    /**
 * @brief Adds texture to enemy model and puts the enemy in the room.
 * @author Eric Liu
 */
    Enemy()

    {
        movespeed = 1;
        if (!texture.loadFromFile(types[enemyType][0]))
        {
            // error...
        }
        enemy.setTexture(texture);
        enemy.setTextureRect(sf::IntRect(0, 0, width, height));
        enemy.setPosition(0, 0);
    }
    /**
 * @brief Adds texture to enemy model and puts the enemy in the room.
 * @param newPosition - new position vector for the enemy
 * @author Eric Liu
 */
    void setpos(sf::Vector2f newPosition)

    {
        enemy.setPosition(newPosition);
    }
    /**
 * @brief Sets enemy to be (non) existent.
 * @param newPosition - new existence value for enemy
 * @author Eric Liu
 */
    void setEmpty(bool val)

    {
        this->empty = val;
    }

    /**
 * @brief Returns the enemy's existent state.
 * @return empty - whether or not the enemy exists
 * @author Eric Liu
 */
    bool getEmpty()

    {
        return this->empty;
    }
    /**
 * @brief Sets the enemy's type(sprite) to type.
 * @param type - new enemy(sprite) type
 * @author Eric Liu
 */
    void setEnemyType(int type)

    {
        this->enemyType = type;
    }
    /**
 * @brief Moves the enemy to mimic the player's movements.
 * @param playerx - x position of the player
 * @param playery - y position of the player
 * @author Eric Liu
 */
    void follow(int playerx, int playery)

    {
        int movex = movespeed, movey = movespeed;

        if (playerx < enemy.getPosition().x)
            movex = movespeed * -1;
        if (playery < enemy.getPosition().y)
            movey = movespeed * -1;

        enemy.move(movex, movey);
        if (animate)
        {
            if (frameCount)
            {
                frameCount++;
                if (frameCount > 5)
                {
                    frameCount = 0;
                }
            }
            else
            {
                if (!texture.loadFromFile(types[enemyType][1]))
                {
                    // error...
                }
                enemy.setTexture(texture);
                animate = false;
                frameCount++;
            }
        }
        else
        {
            if (frameCount)
            {
                frameCount++;
                if (frameCount > 5)
                {
                    frameCount = 0;
                }
            }
            else
            {
                if (!texture.loadFromFile(types[enemyType][0]))
                {
                    // error...
                }
                enemy.setTexture(texture);
                animate = true;
                frameCount++;
            }
        }
    }

    /**
 * @brief Returns whether the enemy has successfully attacked the player.
 * @param w - width of the player
 * @param h - height of the player
 * @param x- x position of the player
 * @param y - y position of the player
 * @return hurt - whether or not the enemy hurt the player
 * @author Eric Liu
 */
    bool attack(int w, int h, int x, int y)

    {
        bool hurt = false;

        int posPlayerWidthSize = x + (w / 2);
        int negPlayerWidthSize = x - (w / 2);
        int posPlayerHeightSize = y + (h / 2);
        int negPlayerHeightSize = y - (h / 2);

        //printf("%d %d",negEnemyWidthSize,posPlayerWidthSize);

        if (negPlayerWidthSize < this->getx() && this->getx() < posPlayerWidthSize && negPlayerHeightSize < this->gety() && this->gety() < posPlayerHeightSize)
        {
            hurt = true;
        }
        /*
            if(x == this->getx()){
                if(y == this->gety()){
                    hurt = true;
                }
                
            }
            */
        return hurt;
    }
    /**
 * @brief Returns the width of the enemy.
 * @return width - width of the player
 * @author Eric Liu
 */
    int getWidth()

    {
        return this->width;
    }

    /**
 * @brief Returns the height of the enemy.
 * @return height- height of the player
 * @author Eric Liu
 */
    int getHeight()

    {
        return this->height;
    }

    /**
 * @brief Returns the enemy position's x coordinate.
 * @return x - x position of the enemy
 * @author Eric Liu
 */
    int getx()

    {
        return enemy.getPosition().x;
    }
    /**
 * @brief Returns the enemy position's y coordinate.
 * @return y - y position of the enemy
 * @author Eric Liu
 */
    int gety()
    {
        return enemy.getPosition().y;
    }
    /**
 * @brief Draws the enemy on the game screen.
 * param window - reference to the window to draw to
 * @author Eric Liu
 */
    void draw(sf::RenderWindow &window)
    {
        window.draw(enemy);
    }
};
