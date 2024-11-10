#include <SFML/Graphics.hpp>

class Bullet
{

private:
    sf::Texture texture;
    sf::Sprite bullet;
    int width = 128;
    int height = 128;
    bool animate = false;
    int frameCount = 0;
    int direction; // 0 Up , 1 Right, 2 Down, 3 Left
    int speed;
    bool empty = true;

public:
    /**
 * @brief Adds texture to bullet model and puts the bullet on the player in the room.
 * @author Luke Edward
 */
    Bullet()
    {
        if (!texture.loadFromFile("axe128.png"))
        {
            // error...
        }
        bullet.setTexture(texture);
        bullet.setTextureRect(sf::IntRect(0, 0, width, height));
        //bullet.setPosition(375,275);
        bullet.setOrigin(64, 64);
        bullet.setScale(0.5, 0.5);
        bullet.setRotation(0);
    }
    /**
 * @brief Sets direction of the bullets path.
 * @param dir - New direction for the bullet path
 * @author Luke Edward
 */
    void setDirection(int dir)
    {
        this->direction = dir;
    }
    /**
 * @brief Sets bullet to be non existant.
 * @param val - bullet existence value
 * @author Luke Edward
 */
    void setEmpty(bool val)
    {
        this->empty = val;
    }
    /**
 * @brief Returns the bullet's existant state.
 * @return empty - bullet existence value
 * @author Luke Edward
 */
    bool getEmpty()
    {
        return this->empty;
    }
    /**
 * @brief Sets bullet speed to s.
 * @param s - bullet speed value
 * @author Luke Edward
 */
    void setSpeed(int s)
    {
        this->speed = s;
    }
    /**
 * @brief Moves the bullet in the room by it's direction and speed.
 * @author Luke Edward
 */
    void move()
    {

        if (this->direction == 0)
        {
            bullet.move(0, -this->speed);
        }
        else if (this->direction == 1)
        {
            bullet.move(this->speed, 0);
        }
        else if (this->direction == 2)
        {
            bullet.move(0, this->speed);
        }
        else
        {
            bullet.move(-this->speed, 0);
        }

        if (frameCount == 0)
        {
            if (frameCount > 2)
            {
                frameCount = 0;
            }
            //bullet.rotate(45);
            frameCount++;
        }
        else
        {
            if (!texture.loadFromFile("axe128.png"))
            {
                // error...
            }
            bullet.setTexture(texture);
            bullet.rotate(45);
            frameCount++;
        }
    }
    /**
 * @brief Returns whether the bullet is within the bounds of the room.
 * @return inBounds - whether the bullet is in the room or not
 * @author Luke Edward
 */

    bool inBounds()
    {
        if (this->getx() < 100 || this->getx() > 700 || this->gety() < 80 || this->gety() > 520)
        {
            return false;
        }
        return true;
    }
    /**
 * @brief Draws the bullet on the game screen.
 * @param window - reference to the game window
 * @author Luke Edward
 */
    void draw(sf::RenderWindow &window)
    {
        window.draw(bullet);
    }
    /**
 * @brief Sets the bullet's position.
 * @param x - new bullet x position
 * @param y - new bullet y position
 * @author Luke Edward
 */
    void setPosition(int x, int y)
    {
        bullet.setPosition(x + 64, y + 64);
    }
    /**
 * @brief Returns the width of the bullet.
 * @return width - width of the bullet
 * @author Luke Edward
 */
    int getWidth()
    {
        return this->width;
    }
    /**
 * @brief Returns the height of the bullet.
 * @return height - height of the bullet
 * @author Luke Edward
 */
    int getHeight()
    {
        return this->height;
    }
    /**
 * @brief Returns the bullet position's x coordinate.
 * @return x - x position of the bullet
 * @author Luke Edward
 */
    int getx()
    {
        return bullet.getPosition().x;
    }
    /**
 * @brief Returns the bullet position's y coordinate.
 * @return y - y position of the bullet
 * @author Luke Edward
 */
    int gety()
    {
        return bullet.getPosition().y;
    }
};
