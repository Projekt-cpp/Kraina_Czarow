#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>

class Collision
{
public:
    static int checkolison(sf::Sprite& a, sf::Sprite& b); //zbiera potki i atak
};


#endif // COLLLISION_H
