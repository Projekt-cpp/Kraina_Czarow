#include "window.h"
#include "player.h"
#include "tile.h"
#include "collision.h"
#include "game.h"

void Window::events_sfml(sf::RenderWindow &window)
{

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

}

