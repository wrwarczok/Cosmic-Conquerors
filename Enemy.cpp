#include "Enemy.h"
#include <iostream>

void Enemy::initShape(int initPunkty)
{
	sf:: Color color(sf::Color::White);
	switch (initPunkty) {
	case 10:
		color.r = 0;
		color.g = 255;
		color.b = 255;
		break;
	case 20:
		color.r = 255;
		color.g = 0;
		color.b = 255;
		break;
	case 30:
		color.r = 255;
		color.g = 255;
		color.b = 0;
		break;
	default:
		color.r = 255;
		color.g = 0;
		color.b = 0;
	}
	this->shape.setFillColor(color);
	this->shape.setSize(sf::Vector2f(40.f, 40.f));
}

void Enemy::initVariables(int initPunkty)
{
	this->punkty = initPunkty;
	this->movementSpeed = 5.f;
	this->currentRelativePos = 0.f;
	this->maxRelativePos = 600.f;
	this->kierunekInt = 1;
	this->pociskEnemyTimerMax = 1*60; //sek*fps
	this->pociskEnemyTimer = pociskEnemyTimerMax;
}

Enemy::Enemy(int initPunkty, int i, int j)
{
	this->initShape(initPunkty);
	this->initVariables(initPunkty);

	this->shape.setPosition(50 * i + 55, 50 * j + 155);
}

Enemy::~Enemy()
{
	pociski.clear();
}

int Enemy::getPunkty()
{
	return this->punkty;
}

void Enemy::update(int poziomTrudnosci)
{
	if (this->currentRelativePos <= 0)
	{
		kierunekInt = 1;
		this->shape.move(0.f, 25.f);
	}
	else
	if (this->currentRelativePos >= maxRelativePos)
	{
		kierunekInt = -1;
		this->shape.move(0.f, 25.f);
	}
	this->shape.move(kierunekInt*this->movementSpeed, 0.f);
	this->currentRelativePos += kierunekInt*this->movementSpeed;

	updatePociski(poziomTrudnosci);
}

void Enemy::updatePociski(int poziomTrudnosci)
{
	pociskEnemyTimer++;
	if (pociskEnemyTimer >= pociskEnemyTimerMax) 
	{
		if (!(rand()%(300*poziomTrudnosci)))
		{
			this->pociski.push_back(Pocisk(this->shape.getPosition().x + (this->shape.getSize().x / 2), this->shape.getPosition().y, 5.f));
			pociskEnemyTimer = 0;
		}
	}

	for (auto& i : this->pociski)
	{
		i.update();
	}
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);

	for (auto i : this->pociski)
	{
		i.render(target);
	}
}
