#include "game.h"
#include "tile.h"
#include "window.h"
#include "player.h"
#include "menu.h"
#include "collision.h"

std::vector<std::vector<sf::Vector2i> > mapa;
std::vector<std::vector<int> > colMapa;
sf::Texture tileTexture;
sf::Sprite tiles;

void Game::renderMap()
{
    sf::RenderWindow window(sf::VideoMode(1200,800), "Kraina Czarow"); //Okno programu

     //Mapy
    sf::Texture txt1;
    txt1.loadFromFile("grafika/lab1.png");
    sf::RectangleShape tlo1(sf::Vector2f(1200,800));
    tlo1.setTexture(&txt1);
    tlo1.setPosition(-1200, -1600);

    sf::Texture txt2;
    txt2.loadFromFile("grafika/lab2.png");
    sf::RectangleShape tlo2(sf::Vector2f(1200,800));
    tlo2.setTexture(&txt2);
    tlo2.setPosition(-1200, -800);

    sf::Texture txt3;
    txt3.loadFromFile("grafika/lab3.png");
    sf::RectangleShape tlo3(sf::Vector2f(1200,800));
    tlo3.setTexture(&txt3);
    tlo3.setPosition(-1200, 0);

    sf::Texture txt4;
    txt4.loadFromFile("grafika/lab4.png");
    sf::RectangleShape tlo4(sf::Vector2f(1200,800));
    tlo4.setTexture(&txt4);
    tlo4.setPosition(1200, -800);

    sf::Texture txt5;
    txt5.loadFromFile("grafika/lab5.png");
    sf::RectangleShape tlo5(sf::Vector2f(1200,800));
    tlo5.setTexture(&txt5);
    tlo5.setPosition(0,0);

    sf::Texture txt6;
    txt6.loadFromFile("grafika/lab6.png");
    sf::RectangleShape tlo6(sf::Vector2f(1200,800));
    tlo6.setTexture(&txt6);
    tlo6.setPosition(1200, 0);

    sf::Texture txt7;
    txt7.loadFromFile("grafika/lab7.png");
    sf::RectangleShape tlo7(sf::Vector2f(1200,800));
    tlo7.setTexture(&txt7);
    tlo7.setPosition(-1200, 800);

    sf::Texture txt8;
    txt8.loadFromFile("grafika/lab8.png");
    sf::RectangleShape tlo8(sf::Vector2f(1200,800));
    tlo8.setTexture(&txt8);
    tlo8.setPosition(1200, 800);

    sf::Texture txt9;
    txt9.loadFromFile("grafika/lab9.png");
    sf::RectangleShape tlo9(sf::Vector2f(1200,800));
    tlo9.setTexture(&txt9);
    tlo9.setPosition(0, 1600);

    sf::Texture txt10;
    txt10.loadFromFile("grafika/podwieczorek.png");
    sf::RectangleShape tlo10(sf::Vector2f(1200,800));
    tlo10.setTexture(&txt10);
    tlo10.setPosition(1200, 1600);

    sf::Texture txt11;
    txt11.loadFromFile("grafika/szachownica.png");
    sf::RectangleShape tlo11(sf::Vector2f(1200,800));
    tlo11.setTexture(&txt11);
    tlo11.setPosition(-1200, 1600);

    sf::Texture txt12;
    txt12.loadFromFile("grafika/walka.png");
    sf::RectangleShape tlo12(sf::Vector2f(1200,800));
    tlo12.setTexture(&txt12);
    tlo12.setPosition(-2400, 1600);

    sf::Texture txt13;
    txt13.loadFromFile("grafika/lab13.png");
    sf::RectangleShape tlo13(sf::Vector2f(1200,800));
    tlo13.setTexture(&txt13);
    tlo13.setPosition(0,-800);

    sf::Texture txt14;
    txt14.loadFromFile("grafika/lab14.png");
    sf::RectangleShape tlo14(sf::Vector2f(1200,800));
    tlo14.setTexture(&txt14);
    tlo14.setPosition(0,800);

    //Menu
    Menu menu(window.getSize().x, window.getSize().y);
    int choose;
    sf::Font font;
    font.loadFromFile("Fonts/Caveat.ttf");
    sf::Time second = sf::seconds(0.01f); //obsluguje czas

    //Postac
    sf::Texture txt;
    txt.loadFromFile("grafika/krolik.gif");
    const int sprwidth = 32;
    sf::IntRect rect(0,0,sprwidth,32); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite player(txt,rect);
    player.scale(2,2);
    player.setPosition(587,360);
    int playerHP = 30;

    sf::Texture txtA;
    txtA.loadFromFile("grafika/lab_alicja.gif");
    const int sprwidth1 = 32;
    sf::IntRect rect1(0,0,sprwidth1,48); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite player1(txtA,rect1);
    player1.scale(2,2);
    player1.setPosition(1000,2015);
    int playerHP1 = playerHP;

    //Smok
    sf::Texture txtS;
    txtS.loadFromFile("grafika/smok.png");
    sf::IntRect rectS(0,0,255,197); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite Zaberzwlok(txtS,rectS);
    Zaberzwlok.scale(2,2);
    Zaberzwlok.setPosition(-2300,1800);


    //Potka
    sf::Texture cart;
    cart.loadFromFile("grafika/potka.png");
    sf::IntRect kart(0, 0, 50, 70); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite carts(cart, kart);
    carts.scale(0.5, 0.5);
    carts.setPosition(500, 600);

    //Napoj
    sf::Texture drink;
    drink.loadFromFile("grafika/napoj.gif");
    sf::IntRect napoj(0, 0, 32, 32); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite drinks(drink, napoj);
    drinks.scale(1.5, 1.5);
    drinks.setPosition(-800, 1900);
    sf::Texture drink1;
    drink1.loadFromFile("grafika/napoj.gif");
    sf::IntRect napoj1(0, 0, 32, 32); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite drinks1(drink1, napoj1);
    drinks1.scale(1.5, 1.5);
    drinks1.setPosition(-1000, 2200);

    //Ciastko
    sf::Texture cake;
    cake.loadFromFile("grafika/ciastko.gif");
    sf::IntRect ciastko(0, 0, 32, 32); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite cakes(cake, ciastko);
    cakes.scale(1.5, 1.5);
    cakes.setPosition(-500, 2100);
    sf::Texture cake1;
    cake1.loadFromFile("grafika/ciastko.gif");
    sf::IntRect ciastko1(0, 0, 32, 32); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite cakes1(cake1, ciastko1);
    cakes1.scale(1.5, 1.5);
    cakes1.setPosition(-1000, 1700);

    //Pasek z informacjami
    sf::RectangleShape line(sf::Vector2f(1200, 30));
    line.setPosition(0, 0);
    line.setFillColor(sf::Color(0, 0, 0));

    //Informacja
    sf::Texture info;
    info.loadFromFile("grafika/instrukcja.png");
    sf::Sprite informacje;
    informacje.setPosition(20,0);
    informacje.setScale(0.9,0.9);
    informacje.setTexture(info);

    //Przeladowanie ekranu
    sf::Texture load;
    load.loadFromFile("grafika/ladowanie.jpg");

    sf::Sprite background;
    background.setPosition(20,0);
    //background.setScale(0.9,0.9);
    background.setTexture(load);


    sf::Clock dt; //Czas
    sf::Clock clock, clock1;

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
            Player::player_move(player,dt,rect,sprwidth,-3,0,0,32);

        else if(keyright==1)
            Player::player_move(player,dt,rect,sprwidth,3,0,0,64);

        else if(keyup==1)
            Player::player_move(player,dt,rect,sprwidth,0,-3,0,96);

        else if(keydown==1)
            Player::player_move(player,dt,rect,sprwidth,0,3,0,0);

        //Przesuniecie Alicji w labiryncie + animacja
        Player::move_alice(player1, player);

       //Zbieranie potek
        if (Collision::checkolison(player, carts)==true)
        {
            playerHP = 60;
            std::cout << playerHP;
            carts.setColor(sf::Color::Transparent);
        }

        //Wypicie napoju
        if (Collision::checkolison(player, drinks)==true)
        {
            player.setScale(1,1);
            drinks.setColor(sf::Color::Transparent);
            drinks.setPosition(2500,2500);
        }
        if (Collision::checkolison(player, drinks1)==true)
        {
            player.setScale(1,1);
            drinks1.setColor(sf::Color::Transparent);
            drinks1.setPosition(2500,2500);
        }

        //Zjedzenie ciastka
        if (Collision::checkolison(player, cakes)==true)
        {
            player.setScale(3,3);
            cakes.setColor(sf::Color::Transparent);
            cakes.setPosition(2500,2500);
        }
        if (Collision::checkolison(player, cakes1)==true)
        {
            player.setScale(3,3);
            cakes1.setColor(sf::Color::Transparent);
            cakes1.setPosition(2500,2500);
        }

        if (choose == 1) //gra w labiryncie
        {
           // window.clear();
            //window.draw(background);
            //window.display();
            /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                //czas=czas+30;
            }
            */
            sf::Vector2<float> pos= player.getPosition();
            sf::Vector2<float> scal= player.getScale();
            window.clear();
            //window.draw(rectangle); //pasek zycia
            //std::cout<<"Pozycja x: "<<pos.x<<", pozycja y: "<<pos.y<<std::endl;
            //std::cout<<scal.x<<std::endl;

            window.draw(tlo5);
            if (pos.x<=0 && pos.y>=0 && pos.x>=-1200 && pos.y<=800)
            {
                window.clear();
                sf::View view(sf::FloatRect(-1200,0, 1200,800));
                window.setView(view);
                window.draw(tlo3);
                window.draw(player);
                window.draw(carts);
            }
            else if (pos.x>=0 && pos.y>=0 && pos.x<=1200 && pos.y<=800)
            {
                window.clear();
                sf::View view(sf::FloatRect(0,0, 1200,800));
                window.setView(view);
                window.draw(tlo5);
                window.draw(player);
            }
            else if (pos.x>=1200 && pos.y>=0 && pos.x<=2400 && pos.y<=800)
            {
                window.clear();
                sf::View view(sf::FloatRect(1200,0, 1200,800));
                window.setView(view);
                window.draw(tlo6);
                window.draw(player);
                window.draw(carts);

            }
            else if (pos.x<=0 && pos.y>=-800 && pos.x>=-1200 && pos.y<=0)
            {
                window.clear();
                sf::View view(sf::FloatRect(-1200,-800, 1200,800));
                window.setView(view);
                window.draw(tlo2);
                window.draw(player);
                window.draw(carts);

            }
            else if (pos.x<=0 && pos.y>=-1600 && pos.x>=-1200 && pos.y<=-800)
            {
                window.clear();
                sf::View view(sf::FloatRect(-1200,-1600, 1200,800));
                window.setView(view);
                window.draw(tlo1);
                window.draw(player);
                window.draw(carts);

            }
            else if (pos.x<=0 && pos.y>=800 && pos.x>=-1200 && pos.y<=1600)
            {
                window.clear();
                sf::View view(sf::FloatRect(-1200,800, 1200,800));
                window.setView(view);
                window.draw(tlo7);
                window.draw(player);
                window.draw(carts);

            }
            else if (pos.x<=0 && pos.y>=1600 && pos.x>=-1200 && pos.y<=2400)
            {
                window.clear();
                sf::View view(sf::FloatRect(-1200,1600, 1200,800));
                window.setView(view);
                window.draw(tlo11); //szachownica
                window.draw(drinks);
                window.draw(drinks1);
                window.draw(cakes);
                window.draw(cakes1);
                window.draw(player);
            }
            else if (pos.x>=0&& pos.y>=1600 && pos.x<=1200 && pos.y<=2400)
            {
                window.clear();
                sf::View view(sf::FloatRect(0,1600, 1200,800));
                window.setView(view);
                window.draw(tlo9);
                window.draw(player);
                window.draw(player1);
                window.draw(carts);

            }
            else if (pos.x>=1200 && pos.y<=0 && pos.x<=2400 && pos.y>=-800)
            {
                window.clear();
                sf::View view(sf::FloatRect(1200,-800, 1200,800));
                window.setView(view);
                window.draw(tlo4);
                window.draw(player);
                window.draw(carts);

            }
            else if (pos.x>=1200 && pos.y>=800 && pos.x<=2400 && pos.y<=1600)
            {
                window.clear();
                sf::View view(sf::FloatRect(1200,800, 1200,800));
                window.setView(view);
                window.draw(tlo8);
                window.draw(player);
                window.draw(carts);

            }
            else if (pos.x>=0 && pos.y<=0 && pos.x<=1200 && pos.y>=-800)
            {
                window.clear();
                sf::View view(sf::FloatRect(0,-800, 1200,800));
                window.setView(view);
                window.draw(tlo13);
                window.draw(player);

            }
            else if (pos.x>=0 && pos.y>=800 && pos.x<=1200 && pos.y<=1600)
            {
                window.clear();
                sf::View view(sf::FloatRect(0,800, 1200,800));
                window.setView(view);
                window.draw(tlo14);
                window.draw(player);
                window.draw(carts);

            }
            else if (pos.x>=1200 && pos.y>=1600 && pos.x<=2400 && pos.y<=2400)
            {
                window.clear();
                sf::View view(sf::FloatRect(1200,1600, 1200,800));
                window.setView(view);
                window.draw(tlo10); //podwieczorek
                window.draw(player);
                window.draw(carts);

            }
            else if (scal.x==3 && pos.x<=-1200 && pos.y>=1600 && pos.x>=-2400 && pos.y<=2400)
            {
                window.clear();
                sf::View view(sf::FloatRect(-2400,1600, 1200,800));
                window.setView(view);
                window.draw(tlo12); //arena
                window.draw(player);
                window.draw(Zaberzwlok);
            }

            window.display();
            if (playerHP < 0)
            {
                choose == 3;
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

