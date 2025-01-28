#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(sf::Vector2f position, float speed, Player* player)
	:bulletPosition{position}, bulletSpeed{speed}, player{player}
{
	bulletShape.setFillColor(sf::Color::Green);
	bulletShape.setRadius(4.0f);
	bulletShape.setPosition(position);
	bulletShape.setPosition(player->GetPosition());
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(bulletShape);
}

void Bullet::Update(float dt)
{
	TriggerBullet(dt);
	bulletShape.sf::Transformable::setPosition(bulletPosition);
}

sf::Vector2f Bullet::GetPos()
{
	return bulletPosition;
}

void Bullet::TriggerBullet(float dt)
{
	bulletPosition.x += bulletSpeed*dt;
}
