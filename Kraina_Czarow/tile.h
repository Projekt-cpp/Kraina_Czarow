#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>

class Tile
{
public:
    static void loadMap(const char *filename);
    static void renderMap();
};


#endif // TILE_H
