#include "window.h"
#include "player.h"

void Window::events_sfml(sf::RenderWindow& window)
{
    int keyleft = 0, keyright = 0, keyup = 0, keydown = 0;

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
    }

}