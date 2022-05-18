#pragma once

#include <iostream>
#include <ctime>
#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "Pocisk.h"
#include "Menu.h"
#include "Napisy.h"


class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;
	std::vector<Enemy> enemies;

	Menu menu;
	bool czyNieMenu;
	bool czyZamknac;
	bool czyNowaGra;

	Napisy napisy;

	int punkty;
	int zycia;
	int poziomTrudnosci;

	void initVariables();
	void initOkno();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	const bool otwarta() const;
	void pollEv();

	void zakonczGre();

	void updateNieMenu();
	void update();
	void render();
};