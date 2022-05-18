#pragma once
#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>
class Napisy
{
friend class Game;
private:
	sf::Font font;
	sf::Text tekst[2];
public:
	Napisy();
	virtual ~Napisy();

	void update(int punkty, int zycia);
	void render(sf::RenderTarget* target);
};

