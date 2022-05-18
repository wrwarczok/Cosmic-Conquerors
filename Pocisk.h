#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Pocisk
{
friend class Game;
friend class Player;
private:
	sf::CircleShape shape;

	float movementSpeed;
	
	void initShape(float x, float y);
	void initVariables(float movSp);
public:
	Pocisk(float x, float y, float movSp);
	virtual ~Pocisk();


	void update();

	void render(sf::RenderTarget* target);
};

