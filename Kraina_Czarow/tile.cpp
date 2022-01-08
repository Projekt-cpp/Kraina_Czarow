#include "tile.h"
#include "window.h"
#include "player.h"
#include "menu.h"

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
        while(!openfile.eof()) //dopoki rozne od END OF FILE
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
    Tile::loadMap("map1.txt"); //Zaladowanie mapy
    sf::RenderWindow window(sf::VideoMode(1200,800), "Kraina Czarow"); //Okno programu

    //Kamera
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1200.0f,800.0f));

    //Menu
    Menu menu(window.getSize().x, window.getSize().y);
    int choose;
    sf::Font font;
    font.loadFromFile("Fonts/Caveat.ttf");
    sf::Time second = sf::seconds(0.01f); //obsluguje czas

    //Postac
    sf::Texture txt;
    txt.loadFromFile("grafika/test_postac.gif");
    const int sprwidth = 32;
    sf::IntRect rect(0,96,sprwidth,48); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite player(txt,rect);
    player.scale(2,2);
    player.setPosition(950,1350);

    //Wprowadzenie
    sf::Text WelcomeText1;
    WelcomeText1.setFont(font);
    WelcomeText1.setCharacterSize(30);
    WelcomeText1.setFillColor(sf::Color::White);
    WelcomeText1.setPosition(200, 100);
    WelcomeText1.setString("Dawno dawno temu, byla sobie Alicja, ktorej przeznaczeniem bylo pokonac Czerwona Krolowa...");

    sf::Text WelcomeText2;
    WelcomeText2.setFont(font);
    WelcomeText2.setCharacterSize(30);
    WelcomeText2.setFillColor(sf::Color::White);
    WelcomeText2.setPosition(400, 200);
    WelcomeText2.setString("... jednak problemem bylo to, ze nie wiadomo gdzie jest, ow Alicja.");

    sf::Text WelcomeText3;
    WelcomeText3.setFont(font);
    WelcomeText3.setCharacterSize(30);
    WelcomeText3.setFillColor(sf::Color::White);
    WelcomeText3.setPosition(500, 300);
    WelcomeText3.setString("Znajdz ja i razem pokonajcie Krolowa.");


    //Pasek na gorze gry i informacje
    sf::RectangleShape line(sf::Vector2f(1200, 30));
    line.setPosition(0, 0);
    line.setFillColor(sf::Color(0, 0, 0));

    //Informacja
    sf::Texture info;
    info.loadFromFile("grafika/info.png");
    sf::Sprite informacje;
    informacje.setPosition(0,0);
    informacje.setTexture(info);

    sf::Clock dt; //Czas
    sf::Clock clock;

    window.setFramerateLimit(120); //120 fps , klatki na sekunde

    //Petla gry
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            Window::events_sfml(window);
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Left:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Right:
                    menu.MoveDown();
                    break;

                case  sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        choose = 1;
                        break;
                    case 1:
                        choose = 2;
                        break;
                    case 2:
                        window.close();
                        break;
                    }
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

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


        if (choose == 1) //gra
        {
            clock.restart();
            sf::Time czas = clock.getElapsedTime();
            if (czas.asSeconds() <= 5)
            {
                sf::Time czas = clock.getElapsedTime();
                window.clear();
                window.draw(WelcomeText1);
                window.display();

            }
            else if (czas.asSeconds()>5 && czas.asSeconds() <= 7)
            {
                window.clear();
                window.draw(WelcomeText2);
                window.display();
            }
            else if (czas.asSeconds() > 7 && czas.asSeconds() <= 10)
            {
                window.clear();
                window.draw(WelcomeText3);
                window.display();
            }
            else if (czas.asSeconds() >10)
            {
                view.setCenter(player.getPosition()); //ustawia kamere
                window.clear(sf::Color(128,128,128));
                window.setView(view);
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
        else if (choose == 2) //informacje o grze
        {
            window.clear();
            window.draw(informacje);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                choose = 1;
            }
            window.display();
        }
        else //ekran startowy
        {
            window.clear();
            menu.draw(window);
            window.display();
        }
    }

}

