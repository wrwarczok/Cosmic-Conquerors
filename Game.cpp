#include "Game.h"
void Game::initVariables()
{
	this->endGame = false;
	this->punkty = 0;
	this->poziomTrudnosci = 3;
	this->zycia = poziomTrudnosci;
	this->czyNieMenu = false;
	this->czyZamknac = false;
	this->czyNowaGra = false;
}

void Game::initOkno()
{
	this->videoMode = sf::VideoMode(1200, 1000);
	this->window = new sf::RenderWindow(this->videoMode, "Na co sie gapisz?", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++) {
			int initPunkty;
			switch (j)
			{
			case 0:
				initPunkty = 30;
				break;
			case 1:
			case 2:
				initPunkty = 20;
				break;
			case 3:
			case 4:
				initPunkty = 10;
				break;
			}
			this->enemies.push_back(Enemy(initPunkty, i, j));
		}
	}
}

Game::Game()
{
	this->initVariables();
	this->initOkno();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::otwarta() const
{
	return this->window->isOpen();
}

void Game::pollEv()
{
	while (this->window->pollEvent(this->sfmlEvent)) {
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
			{
				menu.zmienZPomoc();
				czyNieMenu = !czyNieMenu;
			}
			if (this->sfmlEvent.key.code == sf::Keyboard::F1)
			{
				menu.zmienNaPomoc();
				czyNieMenu = false;
			}
			break;
		}
	}
}

void Game::zakonczGre()
{
	for(auto& e : this->enemies)
	{
		e.pociski.clear();
	}
	this->enemies.clear();
	this->player.pociski.clear();
	this->player.shape.setPosition(50.f, 950.f);
	this->initVariables();
	this->initEnemies();
}

void Game::updateNieMenu()
{
	this->player.update(this->window);
	if (this->enemies.size() == 0)
	{
		int nadpiszPunkty = punkty;
		int nadpiszZycia = zycia;
		zakonczGre();
		this->punkty = nadpiszPunkty;
		this->zycia = nadpiszZycia;
	}
	else
	{
		for (int i = 0; i < this->enemies.size(); i++)
		{
			enemies[i].update(poziomTrudnosci);
			if (this->enemies[i].shape.getPosition().y >= 900.f) 
			{
				zakonczGre();
			}
			for (int j = 0; j < this->enemies[i].pociski.size(); j++)
			{
				if (player.shape.getGlobalBounds().contains(enemies[i].pociski[j].shape.getPosition()))
				{
					this->enemies[i].pociski.erase(this->enemies[i].pociski.begin() + j);
					if (this->zycia > 0)
					{
						zycia--;
					}
					else
					{
						zakonczGre();
					}
				}
			}

			for (int j = 0; j < this->player.pociski.size(); j++)
			{
				if (enemies[i].shape.getGlobalBounds().contains(player.pociski[j].shape.getPosition()))
				{
					this->punkty += this->enemies[i].getPunkty();
					this->enemies.erase(this->enemies.begin() + i);
					this->player.pociski.erase(this->player.pociski.begin() + j);
				}
				else
				if (this->player.pociski[j].shape.getGlobalBounds().top >= this->window->getSize().y)
				{
					this->player.pociski.erase(this->player.pociski.begin() + j);
				}
			}
		}
	}
	this->napisy.update(this->punkty, this->zycia);
}

void Game::update()
{
	pollEv();

	if(this->czyNieMenu) updateNieMenu();
	else
	{
		this->menu.update(this->czyNieMenu, this->czyZamknac, this->czyNowaGra, this->poziomTrudnosci);
		if(czyZamknac) this->window->close();
	}

	if (this->czyNowaGra) {
		zakonczGre();
		this->poziomTrudnosci = this->menu.getPoziomTrudnosci();
		this->zycia = poziomTrudnosci;
		this->napisy.update(this->punkty, this->zycia);
	}
}

void Game::render()
{
	this->window->clear();

	this->napisy.render(this->window);

	if (this->czyNieMenu)
	{
		this->player.render(this->window);

		for (auto i : this->enemies)
		{
			i.render(this->window);
		}

	}
	else
	{
		this->menu.render(this->window);
	}
		this->window->display();
}
