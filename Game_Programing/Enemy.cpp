#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"
#include "Player.h"
Enemy::Enemy(float size, float speed,  sf::Color enemyColor,sf::Vector2f enemyPosition,Player* player)
	:size{ size }, enemySpeed{ speed }, enemyColor{enemyColor} , enemyPosition{enemyPosition},player{player}
{
	enemyShape.setFillColor(enemyColor);
	enemyShape.setRadius(size);
	enemyShape.setOutlineColor(sf::Color::Blue);
	enemyShape.setOutlineThickness(1.0f);
	enemyShape.setPosition(enemyPosition);
}
Enemy::Enemy()
{
}
void Enemy::MoveToPlayer()
{
	float enemyToPlayerX = player->GetPosition().x - enemyPosition.x;
	float enemyToPlayerY = player->GetPosition().y - enemyPosition.y;

	float length = sqrt(enemyToPlayerX * enemyToPlayerX + enemyToPlayerY * enemyToPlayerY);

	enemyToPlayerX /= length;
	enemyToPlayerY /= length;

	enemyPosition.x += enemyToPlayerX * enemySpeed;
	enemyPosition.y += enemyToPlayerY * enemySpeed;
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(enemyShape);
}
void Enemy::Update()
{
	MoveToPlayer();
	enemyShape.sf::Transformable::setPosition(enemyPosition);
}