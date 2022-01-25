#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include <sstream>
#include "game.h"
#include "player.h"
#include "window.h"
#include "tile.h"
#include "menu.h"
#include "collision.h"


int main()
{

    //Muzyka
    sf::Music music;
    if (!music.openFromFile("Muzyka/Winds_Of_Stories.ogg"))
        return -1; // blad
    music.play();
    music.setVolume(40.f);
    music.setLoop(true);

    Game::renderMap(); //Renderowanie gry

    return 0;
}
