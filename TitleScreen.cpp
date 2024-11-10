#include "TitleScreen.h"
/**
 * @brief Draw the title screen menu on the screen.
 * @param window - reference to the game window
 * @author William Brewer
 */

void TitleScreen::draw(sf::RenderWindow &window)
{
	//background texture
	sf::Texture texture;
	if (!texture.loadFromFile("room0000.png"))
	{
		// error...
	}
	texture.setSmooth(true);

	//start and quit buttons
	sf::Texture startTexture;
	sf::Texture quitTexture;
	if (!startTexture.loadFromFile("start.png"))
	{
	}
	startTexture.setSmooth(true);
	if (!quitTexture.loadFromFile("quit.png"))
	{
	}
	quitTexture.setSmooth(true);

	//make sprite buttons
	sf::Sprite start;
	sf::Sprite quit;
	start.setTexture(startTexture);
	quit.setTexture(quitTexture);

	//make background sprite
	sf::Sprite sprite;
	sprite.setTexture(texture);

	//import font
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf"))
	{
		// error...
	}

	//add text
	sf::Text text("DungeonScape", font, 64);
	sf::Text text2("Press ENTER", font, 30);
	sf::Text text3("Click the X", font, 30);

	// set the color of text
	text.setFillColor(sf::Color::Red);
	text2.setFillColor(sf::Color::White);
	text3.setFillColor(sf::Color::White);

	// set the text style and positions
	text.setStyle(sf::Text::Bold);
	text.setPosition(200, 250);
	text2.setPosition(450, 500);
	text3.setPosition(150, 500);

	//set position of buttons
	start.setColor(sf::Color(0, 255, 0));
	quit.setPosition(150, 400);
	start.setPosition(450, 400);

	quit.scale(sf::Vector2f(0.6f, 0.6f));
	start.scale(sf::Vector2f(0.12f, 0.12f));

	// inside the main loop, between window.clear() and window.display()
	window.draw(sprite);
	window.draw(start);
	window.draw(quit);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
}
