#include <string>
#include "game.h"
#include "tile.h"
#include "window.h"
#include "player.h"
#include "menu.h"
#include "collision.h"
#include <conio.h>
#include <cmath>
#include <sstream>
#include <windows.h>

template <typename T>
std::string to_stream(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}
int choose;
std::vector<std::vector<sf::Vector2i> > mapa;
std::vector<std::vector<int> > colMapa;
sf::Texture tileTexture;
sf::Sprite tiles;

void Game::renderMap()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Kraina Czarow"); //Okno programu
    int smokHP = 1000;
    int w1HP = 30;
    int w2HP = 30;
    int w3HP = 30;
    int w4HP = 30;
    int w5HP = 30;
    //Przegrana
    sf::Texture load2;
    load2.loadFromFile("grafika/loose.jpg");
    sf::Sprite background2;
    background2.setPosition(-120, 395); //0,800
    background2.setScale(2.4, 2.4);
    background2.setTexture(load2);

    //Wygrana
    sf::Texture load1;
    load1.loadFromFile("grafika/win.jpg");
    sf::Sprite background1;
    background1.setPosition(-2520, 1130); //-2400, 1600
    background1.setScale(2.4, 2.4);
    background1.setTexture(load1);
    //Mapy
    sf::Texture txt1;
    txt1.loadFromFile("grafika/lab1.png");
    sf::RectangleShape tlo1(sf::Vector2f(1200, 800));
    tlo1.setTexture(&txt1);
    tlo1.setPosition(-1200, -1600);

    sf::Texture txt2;
    txt2.loadFromFile("grafika/lab2.png");
    sf::RectangleShape tlo2(sf::Vector2f(1200, 800));
    tlo2.setTexture(&txt2);
    tlo2.setPosition(-1200, -800);

    sf::Texture txt3;
    txt3.loadFromFile("grafika/lab3.png");
    sf::RectangleShape tlo3(sf::Vector2f(1200, 800));
    tlo3.setTexture(&txt3);
    tlo3.setPosition(-1200, 0);

    sf::Texture txt4;
    txt4.loadFromFile("grafika/lab4.png");
    sf::RectangleShape tlo4(sf::Vector2f(1200, 800));
    tlo4.setTexture(&txt4);
    tlo4.setPosition(1200, -800);

    sf::Texture txt5;
    txt5.loadFromFile("grafika/lab5.png");
    sf::RectangleShape tlo5(sf::Vector2f(1200, 800));
    tlo5.setTexture(&txt5);
    tlo5.setPosition(0, 0);

    sf::Texture txt6;
    txt6.loadFromFile("grafika/lab6.png");
    sf::RectangleShape tlo6(sf::Vector2f(1200, 800));
    tlo6.setTexture(&txt6);
    tlo6.setPosition(1200, 0);

    sf::Texture txt7;
    txt7.loadFromFile("grafika/lab7.png");
    sf::RectangleShape tlo7(sf::Vector2f(1200, 800));
    tlo7.setTexture(&txt7);
    tlo7.setPosition(-1200, 800);

    sf::Texture txt8;
    txt8.loadFromFile("grafika/lab8.png");
    sf::RectangleShape tlo8(sf::Vector2f(1200, 800));
    tlo8.setTexture(&txt8);
    tlo8.setPosition(1200, 800);

    sf::Texture txt9;
    txt9.loadFromFile("grafika/lab9.png");
    sf::RectangleShape tlo9(sf::Vector2f(1200, 800));
    tlo9.setTexture(&txt9);
    tlo9.setPosition(0, 1600);

    sf::Texture txt10;
    txt10.loadFromFile("grafika/podwieczorek.png");
    sf::RectangleShape tlo10(sf::Vector2f(1200, 800));
    tlo10.setTexture(&txt10);
    tlo10.setPosition(1200, 1600);

    sf::Texture txt11;
    txt11.loadFromFile("grafika/szachownica.png");
    sf::RectangleShape tlo11(sf::Vector2f(1200, 800));
    tlo11.setTexture(&txt11);
    tlo11.setPosition(-1200, 1600);

    sf::Texture txt12;
    txt12.loadFromFile("grafika/walka.png");
    sf::RectangleShape tlo12(sf::Vector2f(1200, 800));
    tlo12.setTexture(&txt12);
    tlo12.setPosition(-2400, 1600);

    sf::Texture txt13;
    txt13.loadFromFile("grafika/lab13.png");
    sf::RectangleShape tlo13(sf::Vector2f(1200, 800));
    tlo13.setTexture(&txt13);
    tlo13.setPosition(0, -800);

    sf::Texture txt14;
    txt14.loadFromFile("grafika/lab14.png");
    sf::RectangleShape tlo14(sf::Vector2f(1200, 800));
    tlo14.setTexture(&txt14);
    tlo14.setPosition(0, 800);

    //Pociski
    sf::Texture fire;
    fire.loadFromFile("grafika/fireball.png");
    sf::IntRect firee(0, 0, 300, 300);
    sf::Sprite fireball(fire, firee);
    sf::Vector2f v(5, 1);
    sf::Vector2f gravity(0, 1);
    const int W = 1200;
    const int H = 800;
    int radius = 50.f;
    float x = W / 2 - radius;
    float y = H / 2 - radius;
    // sf::CircleShape fireball(radius * 0.5);
    fireball.setPosition(-2100, 2000);
    fireball.scale(1, 1);

    sf::Texture fire1;
    fire1.loadFromFile("grafika/fireball.png");
    sf::IntRect firee1(0, 0, 300, 300);
    sf::Sprite fireball1(fire1, firee1);
    sf::Vector2f v1(7, 1);
    sf::Vector2f gravity1(0, 1);
    const int W1 = 1500;
    const int H1 = 1000;
    int radius1 = 100.f;
    float x1 = W1 / 2 - radius1;
    float y1 = H1 / 2 - radius1;
    // sf::CircleShape fireball(radius * 0.5);
    fireball1.setPosition(-2100, 2000);
    fireball1.scale(0.7, 0.7);

    //Potki na zycie
    sf::Texture pot;
    pot.loadFromFile("grafika/potka.png"); //jest
    sf::IntRect poth(0, 0, 50, 70);
    sf::Sprite potion(pot, poth);
    potion.scale(0.5, 0.5);
    potion.setPosition(-700, -700);

    sf::Texture pot2;
    pot2.loadFromFile("grafika/potka.png");
    sf::IntRect poth2(0, 0, 50, 70);
    sf::Sprite potion2(pot2, poth2);
    potion2.scale(0.5, 0.5);
    potion2.setPosition(1650, 100);

    sf::Texture pot3;
    pot3.loadFromFile("grafika/potka.png"); //jest
    sf::IntRect poth3(0, 0, 50, 70);
    sf::Sprite potion3(pot3, poth3);
    potion3.scale(0.5, 0.5);
    potion3.setPosition(500, -500);

    sf::Texture pot4;
    pot4.loadFromFile("grafika/potka.png"); //jest
    sf::IntRect poth4(0, 0, 50, 70);
    sf::Sprite potion4(pot4, poth4);
    potion4.scale(0.5, 0.5);
    potion4.setPosition(-700, 1050);

    sf::Texture pot5;
    pot5.loadFromFile("grafika/potka.png"); //jest
    sf::IntRect poth5(0, 0, 50, 70);
    sf::Sprite potion5(pot5, poth5);
    potion5.scale(0.5, 0.5);
    potion5.setPosition(750, 1200);

    //Menu
    Menu menu(window.getSize().x, window.getSize().y);
    
    sf::Font font;
    font.loadFromFile("Fonts/Caveat.ttf");
    sf::Time second = sf::seconds(0.01f); //obsluguje czas

    //Karty
    sf::Texture woj;
    woj.loadFromFile("grafika/woj_karta.gif");
    const int width = 32;
    sf::IntRect wojo(0, 0, width, 48);
    sf::Sprite warrior(woj, wojo);
    warrior.scale(2, 2);
    warrior.setPosition(-700, -400);
    sf::Texture woj2;
    woj2.loadFromFile("grafika/woj_karta.gif");
    const int width2 = 32;
    sf::IntRect wojo2(0, 0, width2, 48);
    sf::Sprite warrior2(woj2, wojo2);
    warrior2.scale(2, 2);
    warrior2.setPosition(1750, 250);
    sf::Texture woj3;
    woj3.loadFromFile("grafika/woj_karta.gif");
    const int width3 = 32;
    sf::IntRect wojo3(0, 0, width3, 48);
    sf::Sprite warrior3(woj3, wojo3);
    warrior3.scale(2, 2);
    warrior3.setPosition(1750, 1100);
    sf::Texture woj4;
    woj4.loadFromFile("grafika/woj_karta.gif");
    const int width4 = 32;
    sf::IntRect wojo4(0, 0, width4, 48);
    sf::Sprite warrior4(woj4, wojo4);
    warrior4.scale(2, 2);
    warrior4.setPosition(-700, 1050);
    sf::Texture woj5;
    woj5.loadFromFile("grafika/woj_karta.gif");
    const int width5 = 32;
    sf::IntRect wojo5(0, 0, width5, 48);
    sf::Sprite warrior5(woj5, wojo5);
    warrior5.scale(2, 2);
    warrior5.setPosition(750, 1000);

    //Postac
    sf::Texture txt;
    txt.loadFromFile("grafika/krolik.gif");
    const int sprwidth = 32;
    sf::IntRect rect(0, 0, sprwidth, 32); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite player(txt, rect);
    player.scale(2, 2);
    player.setPosition(587, 360);
    int playerHP = 30;

    sf::Texture txtA;
    txtA.loadFromFile("grafika/lab_alicja.gif");
    const int sprwidth1 = 32;
    sf::IntRect rect1(0, 0, sprwidth1, 48); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite player1(txtA, rect1);
    player1.scale(2, 2);
    player1.setPosition(1000, 2015);

    sf::Texture txtAw; //Alicja na arene
    txtAw.loadFromFile("grafika/woj_alicja.gif");
    const int sprwidth1w = 32;
    sf::IntRect rect1w(0, 96, sprwidth1w, 48); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite player1w(txtAw, rect1w);
    player1w.scale(3, 3);
    player1w.setPosition(-1270, 2016);
    int playerHP1w = playerHP;

    //Smok
    sf::Texture txtS;
    txtS.loadFromFile("grafika/smok.png");
    sf::IntRect rectS(0, 0, 255, 197); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite Zaberzwlok(txtS, rectS);
    Zaberzwlok.scale(2, 2);
    Zaberzwlok.setPosition(-2300, 1800);

    //Kapelusznik
    sf::Texture txtK;
    txtK.loadFromFile("grafika/kapelusznik.gif");
    sf::IntRect rectK(0, 0, 36, 52); //Definicja prostokata, pierwszego sprite'a
    sf::Sprite Kapelusznik(txtK, rectK);
    Kapelusznik.scale(2, 2);
    Kapelusznik.setPosition(2012, 1761);

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
    informacje.setPosition(20, 0);
    informacje.setScale(0.9, 0.9);
    informacje.setTexture(info);

    //Przeladowanie ekranu
    sf::Texture load;
    load.loadFromFile("grafika/ladowanie.jpg");

    sf::Sprite background;
    background.setPosition(20, 0);
    //background.setScale(0.9,0.9);
    background.setTexture(load);

    //Text z hp
    int HP = 50;
    int HPMax = 50;
    sf::Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(42);
    hpText.setFillColor(sf::Color::Red);
    hpText.setString(to_stream(HP));

    //Text z hpsmoka
    int HPs = 50;
    int HPMaxs = 50;
    sf::Text hpTexts;
    hpTexts.setFont(font);
    hpTexts.setCharacterSize(42);
    hpTexts.setFillColor(sf::Color::Red);
    hpTexts.setString(to_stream(smokHP));

    //Text kapelusznika
    sf::Text Text;
    Text.setFont(font);
    Text.setCharacterSize(32);
    Text.setFillColor(sf::Color::Black);
    Text.setString("Biegnij szukac Alicji!");
    Text.setPosition(2012, 1700);

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

        //Ruch pociskow
        fireball.move(v);
        v.y = v.x + gravity.y;
        sf::FloatRect circle = fireball.getGlobalBounds();
        sf::Vector2f p = fireball.getPosition();
        if (p.x + 60 > -1100)
        {
            v.x *= -1;
        }
        if (p.x < -2100)
        {
            v.x *= -1;
        }
        if (p.y + 60 > -2100)
        {
            v.y *= -1;
        }
        if (p.y < 1600)
        {
            v.y *= -1;
        }
        //Ruch pociskow
        fireball1.move(v1);
        v1.y = v1.x + gravity1.y;
        sf::FloatRect circle1 = fireball1.getGlobalBounds();
        sf::Vector2f p1 = fireball1.getPosition();
        if (p1.x > -1000)
        {
            v1.x *= -1;
        }
        if (p1.x < -2100)
        {
            v1.x *= -1;
        }
        if (p1.y > -2100)
        {
            v1.y *= -1;
        }
        if (p1.y < 1600)
        {
            v1.y *= -1;
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

        hpText.setPosition(player.getPosition().x, player.getPosition().y - hpText.getGlobalBounds().height);
        hpTexts.setPosition(-2000, 1750);

        //Przesuniecie Alicji w labiryncie + animacja
        Player::move_alice(player1, player);

        //Ruch wroga (kart)
        Player::move_alice(warrior, player);
        Player::move_alice(warrior2, player);
        Player::move_alice(warrior3, player);
        Player::move_alice(warrior4, player);
        Player::move_alice(warrior5, player);

        //Atak smoka
        
        if (Collision::checkolison(player, Zaberzwlok) == true)
        {
            Sleep(150);
            HP -= 1;
        }
        //Taka kart
        if (Collision::checkolison(player, warrior) == true)
        {
            Sleep(300);
            HP -= 1;
        }
        if (Collision::checkolison(player, warrior2) == true)
        {
            Sleep(300);
            HP -= 1;
        }
        if (Collision::checkolison(player, warrior3) == true)
        {
            Sleep(300);
            HP -= 1;
        }
        if (Collision::checkolison(player, warrior4) == true)
        {
            Sleep(300);
            HP -= 1;
        }
        if (Collision::checkolison(player, warrior5) == true)
        {
            Sleep(300);
            HP -= 1;
        }
        //Zbieranie potek
        if (Collision::checkolison(player, potion) == true)
        {

            HP += 5;
            potion.setPosition(5000, 5000);
            // hpText.setString(std::to_string(HP));
        }
        if (Collision::checkolison(player, potion2) == true)
        {

            HP += 5;
            potion2.setPosition(5000, 5000);
            //hpText.setString(std::to_string(HP));
        }
        if (Collision::checkolison(player, potion3) == true)
        {

            HP += 5;
            potion3.setPosition(5000, 5000);
            //hpText.setString(std::to_string(HP));
        }
        if (Collision::checkolison(player, potion4) == true)
        {

            HP += 5;
            potion4.setPosition(5000, 5000);
            //hpText.setString(std::to_string(HP));
        }
        if (Collision::checkolison(player, potion5) == true)
        {

            HP += 5;
            potion5.setPosition(5000, 5000);

        }
        hpText.setString(to_stream(HP));

        //Wypicie napoju
        if (Collision::checkolison(player, drinks) == true)
        {
            player.setScale(1, 1);
            player1.setScale(1, 1);
            drinks.setColor(sf::Color::Transparent);
            drinks.setPosition(2500, 2500);
        }
        if (Collision::checkolison(player, drinks1) == true)
        {
            player.setScale(1, 1);
            player1.setScale(1, 1);
            drinks1.setColor(sf::Color::Transparent);
            drinks1.setPosition(2500, 2500);
        }

        //Zjedzenie ciastka
        if (Collision::checkolison(player, cakes) == true)
        {
            player.setScale(3, 3);
            player1.setScale(3, 3);
            cakes.setColor(sf::Color::Transparent);
            cakes.setPosition(2500, 2500);
        }
        if (Collision::checkolison(player, cakes1) == true)
        {
            player.setScale(3, 3);
            player1.setScale(3, 3);
            cakes1.setColor(sf::Color::Transparent);
            cakes1.setPosition(2500, 2500);
        }


        if (choose == 1) //gra w labiryncie
        {
            sf::Time czas = clock.getElapsedTime();
            if (czas.asSeconds() <= 2)
            {
                window.clear();
                window.draw(background);
                window.display();
            }
            else if (czas.asSeconds() > 2)
            {
                sf::Vector2<float> pos = player.getPosition();
                sf::Vector2<float> scal = player.getScale();
                window.clear();

                window.draw(tlo5);
                if (pos.x <= 0 && pos.y >= 0 && pos.x >= -1200 && pos.y <= 800)
                {
                    window.clear();
                    sf::View view(sf::FloatRect(-1200, 0, 1200, 800));
                    window.setView(view);
                    window.draw(tlo3);
                    window.draw(hpText);
                    window.draw(player);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x >= 0 && pos.y >= 0 && pos.x <= 1200 && pos.y <= 800)
                {
                    window.clear();
                    sf::View view(sf::FloatRect(0, 0, 1200, 800));
                    window.setView(view);
                    window.draw(tlo5);
                    window.draw(hpText);
                    window.draw(player);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x >= 1200 && pos.y >= 0 && pos.x <= 2400 && pos.y <= 800)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        w2HP -= 1;

                    }
                    window.clear();
                    sf::View view(sf::FloatRect(1200, 0, 1200, 800));
                    window.setView(view);
                    window.draw(tlo6);
                    window.draw(hpText);
                    window.draw(potion2);
                    window.draw(player);
                    window.draw(warrior2);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                    //Zabicie przeciwnika
                    if (w2HP <= 0)
                    {
                        warrior2.setPosition(5000, 5000);
                    }

                }
                else if (pos.x <= 0 && pos.y >= -800 && pos.x >= -1200 && pos.y <= 0)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        w1HP -= 1;

                    }

                    //Zabicie przeciwnika
                    if (w1HP <= 0)
                    {
                        warrior.setPosition(5000, 5000);
                    }
                    window.clear();
                    sf::View view(sf::FloatRect(-1200, -800, 1200, 800));
                    window.setView(view);
                    window.draw(tlo2);
                    window.draw(player);
                    window.draw(hpText);
                    window.draw(potion);
                    window.draw(warrior);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x <= 0 && pos.y >= -1600 && pos.x >= -1200 && pos.y <= -800)
                {
                    window.clear();
                    sf::View view(sf::FloatRect(-1200, -1600, 1200, 800));
                    window.setView(view);
                    window.draw(tlo1);
                    window.draw(hpText);
                    window.draw(player);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x <= 0 && pos.y >= 800 && pos.x >= -1200 && pos.y <= 1600)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        w4HP -= 1;

                    }
                    //Zabicie przeciwnika
                    if (w4HP <= 0)
                    {
                        warrior4.setPosition(5000, 5000);
                    }

                    window.clear();
                    sf::View view(sf::FloatRect(-1200, 800, 1200, 800));
                    window.setView(view);
                    window.draw(tlo7);
                    window.draw(potion4);
                    window.draw(hpText);
                    window.draw(player);
                    window.draw(warrior4);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x <= 0 && pos.y >= 1600 && pos.x >= -1200 && pos.y <= 2400)
                {
                    window.clear();
                    sf::View view(sf::FloatRect(-1200, 1600, 1200, 800));
                    window.setView(view);
                    window.draw(tlo11); //szachownica
                    window.draw(drinks);
                    window.draw(drinks1);
                    window.draw(cakes);
                    window.draw(cakes1);
                    window.draw(hpText);
                    window.draw(player);
                    window.draw(player1);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x >= 0 && pos.y >= 1600 && pos.x <= 1200 && pos.y <= 2400)
                {
                    window.clear();
                    sf::View view(sf::FloatRect(0, 1600, 1200, 800));
                    window.setView(view);
                    window.draw(tlo9);
                    window.draw(player);
                    window.draw(hpText);
                    window.draw(player1);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x >= 1200 && pos.y <= 0 && pos.x <= 2400 && pos.y >= -800)
                {
                    window.clear();
                    sf::View view(sf::FloatRect(1200, -800, 1200, 800));
                    window.setView(view);
                    window.draw(tlo4);
                    window.draw(hpText);
                    window.draw(player);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x >= 1200 && pos.y >= 800 && pos.x <= 2400 && pos.y <= 1600)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        w3HP -= 1;

                    }
                    //Zabicie przeciwnika
                    if (w3HP <= 0)
                    {
                        warrior3.setPosition(5000, 5000);
                    }

                    window.clear();
                    sf::View view(sf::FloatRect(1200, 800, 1200, 800));
                    window.setView(view);
                    window.draw(tlo8);
                    window.draw(hpText);
                    window.draw(player);
                    window.draw(warrior3);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x >= 0 && pos.y <= 0 && pos.x <= 1200 && pos.y >= -800)
                {
                    window.clear();
                    sf::View view(sf::FloatRect(0, -800, 1200, 800));
                    window.setView(view);
                    window.draw(tlo13);
                    window.draw(potion3);
                    window.draw(hpText);
                    window.draw(player);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x >= 0 && pos.y >= 800 && pos.x <= 1200 && pos.y <= 1600)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        w5HP -= 1;

                    }

                    std::cout << w5HP << std::endl;
                    //Zabicie przeciwnika
                    if (w5HP <= 0)
                    {
                        std::cout << w5HP << std::endl;
                        warrior5.setPosition(5000, 5000);
                    }
                    window.clear();
                    sf::View view(sf::FloatRect(0, 800, 1200, 800));
                    window.setView(view);
                    window.draw(tlo14);
                    window.draw(potion5);
                    window.draw(hpText);
                    window.draw(player);
                    window.draw(warrior5);

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (pos.x >= 1200 && pos.y >= 1600 && pos.x <= 2400 && pos.y <= 2400)
                {
                    window.clear();
                    sf::View view(sf::FloatRect(1200, 1600, 1200, 800));
                    window.setView(view);
                    window.draw(tlo10); //podwieczorek
                    window.draw(hpText);
                    window.draw(player);
                    window.draw(Kapelusznik);
                    if (Collision::checkolison(player, Kapelusznik) == true)
                    {
                        window.draw(Text);
                    }
                    if (keyleft == 1)
                        Player::player_move(player, dt, rect, sprwidth, -3, 0, 0, 32);

                    else if (keyright == 1)
                        Player::player_move(player, dt, rect, sprwidth, 3, 0, 0, 64);

                    else if (keyup == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, -3, 0, 96);

                    else if (keydown == 1)
                        Player::player_move(player, dt, rect, sprwidth, 0, 3, 0, 0);

                }
                else if (scal.x == 3 && pos.x <= -1200 && pos.y >= 1600 && pos.x >= -2400 && pos.y <= 2400)
                {
                hpText.setPosition(player1w.getPosition().x, player1w.getPosition().y - hpText.getGlobalBounds().height);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        smokHP -= 8;

                    }
                    if (Collision::checkolison(player1w, fireball) == true)
                    {
                        Sleep(50);
                        HP -= 1;;
                    }
                    hpTexts.setString(to_stream(smokHP));
                    hpText.setString(to_stream(HP));
                    window.clear();
                    sf::View view(sf::FloatRect(-2400, 1600, 1200, 800));
                    window.setView(view);
                    window.draw(tlo12); //arena
                    window.draw(player1w);
                    window.draw(Zaberzwlok);
                    window.draw(fireball);
                    window.draw(hpTexts);
                    window.draw(hpText);
                    if (smokHP <= 500)
                    {
                        window.draw(fireball1);

                    }

                    //Przesuniecie postaci + animacja
                    if (keyleft == 1)
                        Player::player_move(player1w, dt, rect1w, sprwidth1w, -3, 0, 0, 48);

                    else if (keyright == 1)
                        Player::player_move(player1w, dt, rect1w, sprwidth1w, 3, 0, 0, 96);

                    else if (keyup == 1)
                        Player::player_move(player1w, dt, rect1w, sprwidth1w, 0, -3, 0, 144);

                    else if (keydown == 1)
                        Player::player_move(player1w, dt, rect1w, sprwidth1w, 0, 3, 0, 0);
                }
                if (smokHP <= 0)
                {
                    choose = 5;
                }
                else if (HP <= 0)
                {
                    choose = 6;
                }
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
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {

            }
            window.display();
        }
        else if (choose == 5) //koniec gry
        {
            window.clear();
            window.draw(background1);
            window.display();
        }
        else if (choose == 6)
        {
            window.clear();
            window.draw(background2);
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

