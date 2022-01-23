#include "player.h"
#include "window.h"
#include "tile.h"
#include "collision.h"
#include "game.h"

int keyleft=0, keyright=0, keyup=0, keydown=0;

//sx - pozycja x rogu grafiki
//sy - pozycja y

void Player::player_move(sf::Sprite &player, sf::Clock &dt, sf::IntRect &rect, int sprwidth, int right_left, int up_down, int sx, int sy)
{
    static int frame=0;

    //Ruch postaci + animacja
    player.move(right_left,up_down);
    if(dt.getElapsedTime().asSeconds() > 0.1)
        {
            frame++;
            if(frame>3) frame=0;

            rect.left=sx;
            rect.top=sy;

            rect.left+=sprwidth*frame;

            player.setTextureRect(rect);
            dt.restart();
        }
}

void Player::move_alice(sf::Sprite &player1, sf::Sprite &player, float v, float y)
{/*
    const int rinteraction = 1200/2; //W/2
    //Enemy spoczywa, kiedy nie ma blisko Player'a
    sf::Vector2<float> pos = player1.getPosition();
    sf::Vector2<float> pos2 = player.getPosition();
    sf::Vector2<float> i = pos-pos2;
    float d = length(i);
    if(d > rinteraction)
        return;
    else if(d) //Jesli Player blisko, wtedy Alicja porusza sie w jego kierunku
    {
       sf::Vector2<float> k;
       k=-i/d; //k - wektor kierunku
       //Przesuwamy Enemy
       k.x=k.x*v;
       k.y=k.y*y;
       player1.move(k);
    }*/
}
