#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	this->menuTimerMax = 10;
	this->menuTimer = 0;
	this->czyPomoc = false;
	this->selectedItem = 0;
	this->liczba_opcji = LICZBA_OPCJI;
	this->menuPoziomTrudnosci = 3;

	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}
	////rysowanie elementow menu
	//menu[0].setFont(font);
	//menu[0].setFillColor(sf::Color::Green);
	//menu[0].setString("Wznow");
	//menu[0].setPosition(sf::Vector2f(width / 3, height / (LICZBA_OPCJI + 1) * 1));
	//menu[1].setFont(font);
	//menu[1].setFillColor(sf::Color::White);
	//menu[1].setString("Nowa Gra");
	//menu[1].setPosition(sf::Vector2f(width / 3, height / (LICZBA_OPCJI + 1) * 2));
	//menu[2].setFont(font);
	//menu[2].setFillColor(sf::Color::White);
	//menu[2].setString("Pomoc");
	//menu[2].setPosition(sf::Vector2f(width / 3, height / (LICZBA_OPCJI + 1) * 3));
	//menu[3].setFont(font);
	//menu[3].setFillColor(sf::Color::White);
	//menu[3].setString("Wyjscie");
	//menu[3].setPosition(sf::Vector2f(width / 3, height / (LICZBA_OPCJI + 1) * 4));
	zmienZPomoc();
}

Menu::~Menu()
{
}

void Menu::moveUp()
{
	if (selectedItem >= 0 && selectedItem < LICZBA_OPCJI)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem--;
		if (selectedItem < 0)	selectedItem = LICZBA_OPCJI - 1;
		menu[selectedItem].setFillColor(sf::Color::Green);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}
}

void Menu::moveDown()
{
	if (selectedItem >= 0 && selectedItem < LICZBA_OPCJI)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem++;
		if (selectedItem >= LICZBA_OPCJI) selectedItem = 0;
		menu[selectedItem].setFillColor(sf::Color::Green);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}
}

void Menu::zmienNaPomoc()
{
	this->czyPomoc = true;
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("A, Strz. w lewo - ruch w lewo\nD, Strz. w prawo - ruch w prawo\nSpacja - strzelanie");
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Jestes zielonym prostokatem.\nStrzelaj w kwadraciki, zeby zbierac punkty.\nUnikaj ich strzalow i nie daj im sie dostac na koniec planszy");
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Niebieski - 10 pkt; Fioletowy - 20 pkt; Zolty - 30 pky.");
	menu[3].setFillColor(sf::Color::Red);
	menu[3].setString("Pamietaj, ze nowy poziom trudnosci zaczyna sie dopiero od\nustawienia nowej gry!");
	menu[4].setFillColor(sf::Color::Green);
	menu[4].setString("Wroc do menu");
	this->liczba_opcji = 5;
}

void Menu::zmienZPomoc()
{
	this->czyPomoc = false;
	this->liczba_opcji = LICZBA_OPCJI;
	for (int i = 0; i < LICZBA_OPCJI; i++)
	{
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		menu[i].setPosition(sf::Vector2f(1200 / 5, 1000 / (LICZBA_OPCJI + 1) * (i + 1)));
		switch (i)
		{
		case 0: menu[i].setString("Wznow");
			break;
		case 1: menu[i].setString("Nowa Gra");
			break;
		case 2: menu[i].setString("Pomoc");
			break;
		case 3: switch (menuPoziomTrudnosci)
				{
				case 1:menu[i].setString("Zmien poziom trudnosci : Trudny");
					break;
				case 2:menu[i].setString("Zmien poziom trudnosci : Sredni");
					break;
				case 3:menu[i].setString("Zmien poziom trudnosci : Latwy");
					break;
				default:menu[i].setString("Zmien poziom trudnosci : BLAD");
					break;
				}
			break;
		case 4: menu[i].setString("Wyjscie");
			break;
		default:
			break;
		}
		if(i == selectedItem) menu[i].setFillColor(sf::Color::Green);
	}
}

void Menu::update(bool &czyNieMenu, bool& czyZamknac, bool& czyNowaGra, int& poziomTrudnosci)
{
	menuTimer++;
	if (czyPomoc)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) && menuTimer >= menuTimerMax)
		{
			menuTimer = 0;
			zmienZPomoc();
		}
	}
	else
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && menuTimer >= menuTimerMax)
		{
			menuTimer = 0;
			moveUp();
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && menuTimer >= menuTimerMax)
		{
			menuTimer = 0;
			moveDown();
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) && menuTimer >= menuTimerMax)
		{
			menuTimer = 0;
			switch (selectedItem)
			{
			case 0: czyNieMenu = true;
					break;
			case 1: czyNowaGra = true;
					break;
			case 2: zmienNaPomoc();
					break;
			case 3: if(menuPoziomTrudnosci >=1 && menuPoziomTrudnosci < 3)	menuPoziomTrudnosci++;
					else menuPoziomTrudnosci =1;
					switch (menuPoziomTrudnosci)
						{
						case 1:menu[3].setString("Zmien poziom trudnosci : Trudny");
								break;
						case 2:menu[3].setString("Zmien poziom trudnosci : Sredni");
								break;
						case 3:menu[3].setString("Zmien poziom trudnosci : Latwy");
								break;
						default:menu[3].setString("Zmien poziom trudnosci : BLAD");
								break;
						}
					break;
			case 4: czyZamknac = true;
					break;

			default:
				break;
			}
		}
	}
	
}

void Menu::render(sf::RenderTarget* target)
{
	for (int i = 0; i < liczba_opcji; i++)
	{
		target->draw(menu[i]);
	}
}
