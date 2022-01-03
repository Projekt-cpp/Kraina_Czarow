#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include <sstream>
#include "player.h"
#include "window.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1200,800), "Kraina Czarow"); //Okno programu


    //Postac
    sf::Texture txt;
    txt.loadFromFile("grafika/test_postac.gif");
    const int sprwidth = 32;
    sf::IntRect rect(0,96,sprwidth,48); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite player(txt,rect);
    player.scale(2,2);
    player.setPosition(50,50);

    sf::Clock dt; //Czas

    window.setFramerateLimit(120); //120 fps , klatki na sekunde

    //Muzyka
    sf::Music music;
    if (!music.openFromFile("Muzyka/Winds_Of_Stories.ogg"))
        return -1; // blad
    music.play();

    //Petla gry
    while(window.isOpen())
    {
        Window::events_sfml(window);

        int keyleft=0, keyright=0, keyup=0, keydown=0;

        //Stan klawiatury
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            keyleft=1;
        else keyleft=0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            keyright=1;
        else keyright=0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            keyup=1;
        else keyup=0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            keydown=1;
        else keydown=0;

        //Przesuniecie postaci + animacja
        if(keyleft==1)
            Player::player_move(player,dt,rect,sprwidth,-3,0,0,48);

        if(keyright==1)
            Player::player_move(player,dt,rect,sprwidth,3,0,0,96);

        if(keyup==1)
            Player::player_move(player,dt,rect,sprwidth,0,-3,0,144);

        if(keydown==1)
            Player::player_move(player,dt,rect,sprwidth,0,3,0,0);



        window.clear(sf::Color(72,160,73,255));
        window.draw(player);
        window.display();
    }
    return 0;
}
