#include "Menu.h"

Menu::Menu(float width, float height)
{

	if (!font.loadFromFile("Fonts/MoonDance-Regular.ttf"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Start");
	menu[0].setPosition(sf::Vector2f(400, 390));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Informacje");
	menu[1].setPosition(sf::Vector2f(600, 390));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Zakoncz");
	menu[2].setPosition(sf::Vector2f(800, 390));

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}
void Menu::draw(sf::RenderWindow& window)
{

	sf::Texture tlo;
	tlo.loadFromFile("grafika/Menu.png");
	sf::Sprite wejscie;
	wejscie.setPosition(0, 0);
	wejscie.setTexture(tlo);
	window.draw(wejscie);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}

}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}
