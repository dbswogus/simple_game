#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

	int move_pos_rand_x = rand() % 1920;
	int move_pos_rand_y = rand() % 1080;
	const int rect_num = 30;
	sf::RectangleShape rect[rect_num];
	for (int i = 0; i < rect_num;i++)
	{
		int rand_x = rand() % 1920;
		int rand_y = rand() % 1080;
		const int size_x = 50;
		const int size_y = 50;
		rect[i].sf::Transformable::setPosition(sf::Vector2f(rand_x, rand_y));
		rect[i].setSize(sf::Vector2f(size_x, size_y));
		//rect[i].setFillColor(sf::Color(rand() % 255));
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i < rect_num;i++)
		{
			window.draw(rect[i]);
		}
		window.display();
	}
}