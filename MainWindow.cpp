#include "MainWindow.h"
#include <SFML/Audio.hpp>
/**
 * @brief Sets the window state to splashscreen.
 * @param window - Reference to the game window
 * @author Brendan Bain
 */

MainWindow::MainWindow(sf::RenderWindow &window) : m_window(window)
{
	state = SplashScreen;
}
/**
 * @brief Runs the game on the window.
 * @author Brendan Bain
 */
// Main window loop
void MainWindow::run()
{

	while (m_window.isOpen())
	{

		sf::Event evnt;
		while (m_window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				m_window.close(); // If the x button is pressed (sf "Closed" event), close the window
		}

		if (state == Exit)
		{
			m_window.close();
		}
		m_window.clear();
		updateScreen();
		// call the craw function to decide what the screen needs to be displaying
		draw(m_window);
		m_window.display();
	}
}
/**
 * @brief Updates the window depending on the current state. 
 * @author Brendan Bain
 */
void MainWindow::updateScreen()
{
	if (state == SplashScreen & sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		state = MainGame;
	}
	if (state == SplashScreen & sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
	{
		state = Exit;
	}
	/*
    if (state == SplashScreen & sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1) & !musicOn)
	{
		sf::SoundBuffer buffer;
        if (!buffer.loadFromFile("arrow_x.wav"))
            printf("music error");// error
        else{
        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.play();
        musicOn = true;
        }
	}*/
	if (state == MainGame & win == 0 || win == 1)
	{
		state = GameOverScreen;
	}
	if (state == GameOverScreen & sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace))
	{
		win = -1;
		ViewModel g;
		gamescreen = g;
		state = SplashScreen;
	}
}
/**
 * @brief Draws the required game screen on the window.
 * @param window - reference to the game window
 * @author Brendan Bain
 */
void MainWindow::draw(sf::RenderWindow &window)
{
	// Draw the game
	switch (state)
	{
	case SplashScreen:
		titlescreen.draw(window);
		break;
	case MainGame:
		win = gamescreen.draw(window);
		break;
	case GameOverScreen:
		gameover.draw(window, win);
		break;
	}
}
