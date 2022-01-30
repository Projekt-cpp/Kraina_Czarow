#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
    sf::Vector2f GetPosition(sf::Sprite &player) {return player.getPosition(); } //Pozycja postaci
    //Ruch postaci + animacja
    static void player_move(sf::Sprite &player, sf::Clock &dt, sf::IntRect &rect, int sprwidth, int right_left, int up_down, int sx, int sy);
    static void move_alice(sf::Sprite &player1, sf::Sprite &player);
};


#endif // PLAYER_H
