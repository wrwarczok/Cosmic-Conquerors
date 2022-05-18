#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Pocisk.h"

class Enemy
{
friend class Game;
private:
	std::vector<Pocisk> pociski;
	sf::RectangleShape shape;

	int   punkty; 
	float currentRelativePos;
	float maxRelativePos;
	int   kierunekInt;
	float movementSpeed;
	
	int pociskEnemyTimer;
	int pociskEnemyTimerMax;

	void initShape(int initPunkty);
	void initVariables(int initPunkty);
public:
	Enemy(int initPunkty, int i, int j);
	virtual ~Enemy();
	int getPunkty();

	void update(int poziomTrudnosci);
	void updatePociski(int poziomTrudnosci);

	void render(sf::RenderTarget* target);

};

