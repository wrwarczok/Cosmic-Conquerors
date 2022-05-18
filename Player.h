#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Pocisk.h"


class Player
{
friend class Game;
private:
	sf::RectangleShape shape;
	std::vector<Pocisk> pociski;
	 
	float movementSpeed;
	int pociskTimer;
	int pociskTimerMax;


	void initVariables();
	void initShape();
public:
	Player(float x = 50.f, float y = 950.f);
	virtual ~Player();

	void updateWindowCollision( const sf::RenderTarget* target);
	void updateInput();
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

