#include <SFML/Graphics.hpp>
#include "game.cpp"

int main()
{
    
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "test");
    MainWindow main_window(window);
    main_window.run();
    
    
    return 0;
}
