#include "collision.h"
#include "window.h"
#include "player.h"
#include "tile.h"
#include "game.h"

int Collision::checkolison(sf::Sprite& a, sf::Sprite& b)
{
    sf::FloatRect shape1 = a.getGlobalBounds();
    sf::FloatRect shape2 = b.getGlobalBounds();
    if(a.getPosition().x<b.getPosition().x+shape2.width)
        if(a.getPosition().x+shape1.width>b.getPosition().x)
            if(a.getPosition().y<b.getPosition().y+shape2.height)
                if (a.getPosition().y + shape1.height > b.getPosition().y)
                {
                return 1;
                }
}
