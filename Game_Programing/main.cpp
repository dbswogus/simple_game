#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	
	sf::RectangleShape shape(sf::Vector2f(50,50));
	float move_pos = 1920;
	float move_pos_y = 0;
	float move_direct = -1.0f;
	shape.setFillColor(sf::Color::Green);
	
	sf::CircleShape circle(25.0f);
	circle.setFillColor(sf::Color::Red);
	float move_pos_c = 0;
	float move_pos_c_y = 0;
	float move_direct_c = 1.0f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		shape.sf::Transformable::setPosition(sf::Vector2f(move_pos,move_pos_y));
		circle.sf::Transformable::setPosition(sf::Vector2f(move_pos_c, move_pos_c_y));
		move_pos += move_direct;
		move_pos_c += move_direct_c;
		if (move_pos == 0 || move_pos == 1920)
		{
			move_direct = -move_direct;
			move_pos_y += 50;
		}
		if (move_pos_c == 0 || move_pos_c == 1920)
		{
			move_direct_c = -move_direct_c;
			move_pos_c_y += 50;
		}
		window.clear();
		window.draw(shape);
		window.draw(circle);
		window.display();
	}
}