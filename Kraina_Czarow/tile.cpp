#include "tile.h"
#include "window.h"
#include "player.h"

std::vector<std::vector<sf::Vector2i> > mapa;
std::vector<sf::Vector2i> tempMap;
sf::Texture tileTexture;
sf::Sprite tiles;

void Tile::loadMap(const char *filename)
{
    std::ifstream openfile(filename);
    tempMap.clear();
    mapa.clear();

    if(openfile.is_open())
    {
        std::string tileLocation;
        openfile>>tileLocation;
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);
        while(!openfile.eof()) //dopóki ró¿ne od END OF FILE
        {
            std::string str,value;
            std::getline(openfile,str);
            std::stringstream stream(str);

            while(std::getline(stream,value,' '))
            {
                if(value.length()>0)
                {
                    std::string xx = value.substr(0, value.find(','));
                    std::string yy = value.substr(value.find(',')+1);

                    int x,y,i,j;

                    for(i=0; i<xx.length(); i++)
                    {
                        if(!isdigit(xx[i]))
                            break;
                    }
                    for(j=0; j<yy.length(); j++)
                    {
                        if(!isdigit(yy[j]))
                            break;
                    }
                    x=(i==xx.length())?atoi(xx.c_str()):-1;
                    y=(j==yy.length())?atoi(yy.c_str()):-1;

                    tempMap.push_back(sf::Vector2i(x,y));
                }
            }
            mapa.push_back(tempMap);
            tempMap.clear();
        }
    }
}

void Tile::renderMap()
{
    Tile::loadMap("map1.txt"); //Za³¹dowanie mapy
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

        window.clear(sf::Color(50,255,100));
        for(int i=0; i<mapa.size(); i++)
        {
            for(int j=0; j<mapa[i].size(); j++)
            {
                if(mapa[i][j].x != -1 && mapa[i][j].y != -1)
                {
                    tiles.setPosition(j*50, i*50);
                    tiles.setTextureRect(sf::IntRect(mapa[i][j].x*50, mapa[i][j].y*50, 50, 50));
                    window.draw(tiles); //Narysuj kafelki
                }
            }
        }
        window.draw(player);
        window.display();
    }
}

