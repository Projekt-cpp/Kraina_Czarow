#include "player.h"
#include "window.h"

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
