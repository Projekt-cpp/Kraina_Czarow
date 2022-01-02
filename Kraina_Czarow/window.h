#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

class Window
{
public:
    static void events_sfml(sf::RenderWindow& window); //Obsluga zdarzen okna w SFML
};


#endif // WINDOW_H