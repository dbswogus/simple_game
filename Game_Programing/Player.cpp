#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
Player::Player(sf::Vector2f pos, sf::Vector2f size, sf::Color color, float speed)
	: position{pos},size{size},color{color},speed{speed}
{
	shape.setSize(size);
	shape.setFillColor(color);
}
void Player::Update() // 플레이어 동작
{
	ProcessInput();
	shape.setPosition(position);
}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
sf::Vector2f Player::GetPosition()
{
	return position;
}
void Player::ProcessInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position.x += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		position.y += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		position.y -= speed;
	}
}