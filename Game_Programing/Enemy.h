#pragma once
#include <SFML/Graphics.hpp>

class Player;

class Enemy {
public:
	Enemy(float size, float speed, sf::Color enemyColor, sf::Vector2f enemyPosition, Player* player);
	Enemy();
	void Draw(sf::RenderWindow& window);
	void Update(float dt);
private:
	void MoveToPlayer(float dt);

private:
	sf::CircleShape enemyShape;
	float enemySpeed;
	float size;
	sf::Color enemyColor;
	sf::Vector2f enemyPosition;
	Player* player;
};