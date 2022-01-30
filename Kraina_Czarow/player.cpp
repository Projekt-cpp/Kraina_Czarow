#include "player.h"
#include "window.h"
#include "tile.h"
#include "collision.h"
#include "game.h"
#include <cmath>

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

float length(sf::Vector2f &a)
{
    return hypot(a.x, a.y);
}

void Player::move_alice(sf::Sprite &player1, sf::Sprite &player)
{
    const int R=450;
    //spoczywaj, gdy nie ma blisko królika
    sf::Vector2<float> pos1=player1.getPosition();
    sf::Vector2<float> pos=player.getPosition();
    sf::Vector2<float>i=pos1-pos;
    float d=length(i);
    if(d > R)
    {
        return;
    }
    else if(d) //jesli królik blisko to idŸ w jego kierunku
    {
        sf::Vector2<float> k;
        k=-i/d; //wektor kierunku, od Alicji do królika
        player1.move(k); //przesuniêcie Alicji
    }
}
