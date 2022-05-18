#pragma once
#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>

#define LICZBA_OPCJI 5

class Menu
{
//friend class Game;
private:
	sf::Font font;
	sf::Text menu[LICZBA_OPCJI];//maksymalna liczba poziomow
	int selectedItem;
	
	int menuTimer;
	int menuTimerMax;

	bool czyPomoc;
	int liczba_opcji;

	int menuPoziomTrudnosci;

public:
	Menu();
	virtual ~Menu();

	void moveUp();//przesun do gory
	void moveDown();//przesun w dol
	void zmienNaPomoc();
	void zmienZPomoc();

	int getPoziomTrudnosci() { return menuPoziomTrudnosci; }//zwroc poziom menu

	void update(bool &czyNieMenu, bool& czyZamknac, bool& czyNowaGra, int& poziomTrudnosci);
	void render(sf::RenderTarget* target);
};

