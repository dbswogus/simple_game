#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:
	Player(sf::Vector2f pos, sf::Vector2f size, sf::Color color, float speed);

	void Update(); // 플레이어 동작
	void Draw(sf::RenderWindow& window); //플레이어 그리기
	sf::Vector2f GetPosition();
private:
	void ProcessInput(); //키보드 입력

	
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape shape;
	float speed;
	sf::Color color;
};