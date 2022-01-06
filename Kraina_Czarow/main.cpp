#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include <sstream>
#include "player.h"
#include "window.h"
#include "tile.h"


int main()
{

    //Muzyka
    sf::Music music;
    if (!music.openFromFile("Muzyka/Winds_Of_Stories.ogg"))
        return -1; // blad
    music.play();

    Tile::renderMap(); //Renderowanie gry

    return 0;
}
