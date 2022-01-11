#include "tile.h"
#include "window.h"
#include "player.h"
#include "menu.h"

std::vector<std::vector<sf::Vector2i> > mapa;
std::vector<sf::Vector2i> tempMap;
sf::Texture tileTexture;
sf::Sprite tiles;
int choose;
int checkolison(sf::Sprite& a, sf::Sprite& b)
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
void Tile::loadMap(const char* filename)
{
    std::ifstream openfile(filename);
    tempMap.clear();
    mapa.clear();

    if (openfile.is_open())
    {
        std::string tileLocation;
        openfile >> tileLocation;
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);
        while (!openfile.eof()) //dopoki rozne od END OF FILE
        {
            std::string str, value;
            std::getline(openfile, str);
            std::stringstream stream(str);

            while (std::getline(stream, value, ' '))
            {
                if (value.length() > 0)
                {
                    std::string xx = value.substr(0, value.find(','));
                    std::string yy = value.substr(value.find(',') + 1);

                    int x, y, i, j;

                    for (i = 0; i < xx.length(); i++)
                    {
                        if (!isdigit(xx[i]))
                            break;
                    }
                    for (j = 0; j < yy.length(); j++)
                    {
                        if (!isdigit(yy[j]))
                            break;
                    }
                    x = (i == xx.length()) ? atoi(xx.c_str()) : -1;
                    y = (j == yy.length()) ? atoi(yy.c_str()) : -1;

                    tempMap.push_back(sf::Vector2i(x, y));
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
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Kraina Czarow"); //Okno programu

    //Kamera
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1200.0f, 800.0f));

    //Menu
    Menu menu(window.getSize().x, window.getSize().y);
   
    sf::Font font;
    font.loadFromFile("Fonts/Caveat.ttf");
    sf::Time second = sf::seconds(0.01f); //obsluguje czas

    //Postac
    sf::Texture txt;
    txt.loadFromFile("grafika/krolik.gif");
    const int sprwidth = 32;
    sf::IntRect rect(0, 0, sprwidth, 32); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite player(txt, rect);
    player.scale(2, 2);
    player.setPosition(950, 1350);
    int playerHP = 30;
    
    
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


    //karty mocy
    sf::Texture cart;
    cart.loadFromFile("grafika/potka.png");
    sf::IntRect kart(0, 0, 50, 70); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite carts(cart, kart);
    carts.scale(0.5, 0.5);
    carts.setPosition(500, 600);

    //pasek z informacjami
    
    sf::RectangleShape rectangle(sf::Vector2f(1200, 10)); // tworzymy prostokąt
    rectangle.setPosition(0,0); // 
    rectangle.setFillColor(sf::Color::Black);
    
    //Informacja
    sf::Texture info;
    info.loadFromFile("grafika/instrukcja.png");
    sf::Sprite informacje;
    informacje.setPosition(20, 0);
    informacje.setScale(0.9, 0.9);
    informacje.setTexture(info);

    //Przeladowanie ekranu
    sf::Texture load;
    load.loadFromFile("grafika/load_ss.jpg");

    sf::Sprite background;
    background.setTexture(load);


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
                        clock.restart();
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

        int keyleft = 0, keyright = 0, keyup = 0, keydown = 0;

        //Stan klawiatury
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            keyleft = 1;
        else keyleft = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            keyright = 1;
        else keyright = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            keyup = 1;
        else keyup = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            keydown = 1;
        else keydown = 0;

        //Przesuniecie postaci + animacja
        if (keyleft == 1)
            Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

        if (keyright == 1)
            Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

        if (keyup == 1)
            Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

        if (keydown == 1)
            Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

        //sf::Time czas = clock.getElapsedTime();

        //zbieranie kart mocy
        if (checkolison(player, carts)==true) 
        {
            playerHP = 60;
            std::cout << playerHP;
            carts.setColor(sf::Color::Transparent);
        }
        
        if (choose == 1) //gra
        {
           
            sf::Time czas = clock.getElapsedTime();
            if (czas.asSeconds() <= 5)
            {
                window.clear();
                window.draw(background);
                window.draw(WelcomeText1);
                window.display();
                //clock.restart();
            }
            else if (czas.asSeconds() > 5 && czas.asSeconds() <= 7)
            {
                window.clear();
                window.draw(background);
                window.draw(WelcomeText2);
                window.display();
            }
            else if (czas.asSeconds() > 7 && czas.asSeconds() <= 10)
            {
                window.clear();
                window.draw(background);
                window.draw(WelcomeText3);
                window.display();
            }
            else if (czas.asSeconds() > 10)
            {
               
                view.setCenter(player.getPosition()); //ustawia kamere
                window.clear(sf::Color(50, 255, 100));
                window.draw(rectangle);
                window.setView(view);
                for (int i = 0; i < mapa.size(); i++)
                {
                    for (int j = 0; j < mapa[i].size(); j++)
                    {
                        if (mapa[i][j].x != -1 && mapa[i][j].y != -1)
                        {
                            tiles.setPosition(j * 50, i * 50);
                            tiles.setTextureRect(sf::IntRect(mapa[i][j].x * 50, mapa[i][j].y * 50, 50, 50));
                            window.draw(tiles); //Narysuj kafelki
                            
                        }
                    }
                }
               
                window.draw(carts);
                std::cout << playerHP << std::endl;
                window.draw(player);
                window.display();
                sf::Vector2<float> pos = player.getPosition();
                if (playerHP < 0) 
                {
                    choose == 3;
                }
                
            }


        }
        else if (choose == 2) //informacje o grze
        {
            window.clear();
            window.draw(informacje);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                choose = 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                
            }
            window.display();
        }
        else if (choose == 3) //koniec gry
        {
            window.close();
        }
        else //ekran startowy
        {
            window.clear();
            menu.draw(window);
            window.display();
        }
    }
}