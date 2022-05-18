#include "Napisy.h"

Napisy::Napisy()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}
	tekst[0].setFont(font);
	tekst[0].setFillColor(sf::Color::White);
	tekst[0].setString("PUNKTY  " + std::to_string(0));
	tekst[0].setPosition(sf::Vector2f(25.f, 25.f));
	tekst[1].setFont(font);
	tekst[1].setFillColor(sf::Color::White);
	tekst[1].setString("ZYCIA  " + std::to_string(3));
	tekst[1].setPosition(sf::Vector2f(25.f, 1000.f - 125.f));

}

Napisy::~Napisy()
{
}

void Napisy::update(int punkty, int zycia)
{
	tekst[0].setString("PUNKTY  " + std::to_string(punkty));
	tekst[1].setString("ZYCIA  " + std::to_string(zycia));
}

void Napisy::render(sf::RenderTarget* target)
{
	for (int i = 0; i < 2; i++)
	{
		target->draw(tekst[i]);
	}
}
