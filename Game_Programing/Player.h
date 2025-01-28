#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:
	Player(sf::Vector2f pos, sf::Vector2f size, sf::Color color, float speed);

	void Update(float dt); // �÷��̾� ����
	void Draw(sf::RenderWindow& window); //�÷��̾� �׸���
	sf::Vector2f GetPosition();
private:
	void ProcessInput(float dt); //Ű���� �Է�

	
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape shape;
	float speed;
	sf::Color color;
};