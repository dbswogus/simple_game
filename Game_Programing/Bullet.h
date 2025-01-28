#include <SFML/Graphics.hpp >
#pragma once

class Player;

class Bullet 
{
public:
	Bullet(sf::Vector2f position,  float speed, Player* player);
	void Draw(sf::RenderWindow& window);
	void Update(float dt);
	sf::Vector2f GetPos();
private:
	void TriggerBullet(float dt);

private:
	sf::Vector2f bulletPosition;
	sf::CircleShape bulletShape;
	sf::Color bulletColor;
	float bulletSpeed;
	Player* player;
};