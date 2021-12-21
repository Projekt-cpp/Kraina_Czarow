#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
    //Ruch postaci + animacja
    static void player_move(sf::Sprite &player, sf::Clock &dt, sf::IntRect &rect, int sprwidth, int right_left, int up_down, int sx, int sy);

};


#endif // PLAYER_H
