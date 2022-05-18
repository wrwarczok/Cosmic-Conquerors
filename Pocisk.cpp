#include "Pocisk.h"
#include <iostream>

void Pocisk::initShape(float x, float y)
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setRadius(2.5f);
	this->shape.setPosition(x, y);
}

void Pocisk::initVariables(float movSp)
{
	this->movementSpeed = movSp;
}

Pocisk::Pocisk(float x, float y, float movSp)
{
	initShape(x, y);
	initVariables(movSp);
}

Pocisk::~Pocisk()
{
	
}

void Pocisk::update()
{
	this->shape.move(0.f, movementSpeed);
//	std::cout<<"\nPocisk x="<< this->shape.getPosition().x << " movSp:" << this->movementSpeed << ' ' << rand();
}

void Pocisk::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
