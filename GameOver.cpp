#include "GameOver.h"
/**
 * @brief Draws the GameOver screen on the window.
 * @param window - Reference to the game window
 * @author Brendan Bain
 */

void GameOver::draw(sf::RenderWindow &window, int value)
{
    //background texture
    sf::Texture texture;
    if (!texture.loadFromFile("room0000.png"))
    {
        // error...
    }
    texture.setSmooth(true);

    //make sprite with texture
    sf::Sprite sprite;
    sprite.setTexture(texture);

    //import font
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf"))
    {
        // error...
    }

    //add text
    if (value == 0)
    {
        sf::Text text("Game Over!", font, 64);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        text.setPosition(200, 250);
        sf::Text t("Press Backspace To Continue", font, 64);
        t.setFillColor(sf::Color::Yellow);
        t.setStyle(sf::Text::Bold);
        t.setPosition(175, 375);
        t.setScale(0.5, 0.5);
        // inside the main loop, between window.clear() and window.display()
        window.draw(sprite);
        window.draw(text);
        window.draw(t);
    }
    else
    {
        sf::Text text("Win!", font, 64);
        text.setFillColor(sf::Color::Green);
        text.setStyle(sf::Text::Bold);
        text.setPosition(325, 275);
        sf::Text t("Press Backspace To Continue", font, 64);
        t.setFillColor(sf::Color::Yellow);
        t.setStyle(sf::Text::Bold);
        t.setPosition(175, 375);
        t.setScale(0.5, 0.5);

        // inside the main loop, between window.clear() and window.display()
        window.draw(sprite);
        window.draw(text);
        window.draw(t);
    }
    // set the color of text

    // set the text style and positions
}
