#include "Player.h"
#include <iostream>

void Player::initVariables()
{
	this->movementSpeed = 10.f;
	this->pociskTimer = 60;
	this->pociskTimerMax = 60;

}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(90.f, 30.f));
}


Player::Player(float x, float y)
{
	this->initVariables();
	this->initShape();

	this->shape.setPosition(x, y);

}

Player::~Player()
{
	pociski.clear();
}

void Player::updateWindowCollision(const sf::RenderTarget* target)
{
	sf::Vector2f playerPos = this->shape.getPosition();
	if (this->shape.getGlobalBounds().left <= 0.f)
	{
		this->shape.setPosition(0.f, playerPos.y);
	}
	else 
	if ((this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x))
	{
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, playerPos.y);
	}
	for (int i =0; i < this->pociski.size(); i++)
	{
		if (pociski[i].shape.getGlobalBounds().top <= 0.f)
		{
			this->pociski.erase(this->pociski.begin() + i);
		}
	}
}

void Player::updateInput()
{
	//inputy (wreszcie)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	// else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pociskTimer >= pociskTimerMax)
	{
		this->pociski.push_back( Pocisk(this->shape.getPosition().x + (this->shape.getSize().x/2), this->shape.getPosition().y, -10.f));
		pociskTimer = 0;
	}
}

void Player::update(const sf::RenderTarget* target)
{
	this->updateInput();
	this->updateWindowCollision(target);
	this->pociskTimer++;
	for (auto& i : this->pociski)
	{
		i.update();
	}
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	for (auto i : this->pociski)
	{
		i.render(target);
	}
}
