#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	const int windowwidth = 1920;
	const int windowheigh = 1080;
	sf::RenderWindow window(sf::VideoMode(windowwidth, windowheigh), "SFML works!");
	
	const int rect_num = 30;
	sf::RectangleShape rect[rect_num];

	float move[rect_num];
	for (int i = 0; i < rect_num;i++)
	{
		const int size_x = 50;
		const int size_y = 50;
		int rand_x = rand() % 1920;
		int rand_y = rand() % 1080;
		unsigned char rand_colorR = rand() % 255;
		unsigned char rand_colorG = rand() % 255;
		unsigned char rand_colorB = rand() % 255;
		unsigned char rand_color = rand() % 255;

		rect[i].sf::Transformable::setPosition(sf::Vector2f(rand_x, rand_y));
		rect[i].setSize(sf::Vector2f(size_x, size_y));
		rect[i].setFillColor(sf::Color(rand_colorR,rand_colorG,rand_colorB, rand_color));
		move[i] = rand()%2+0.5;
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
		for (int i = 0; i < rect_num;i++)
		{
			sf::Vector2f pos = rect[i].getPosition();
			pos.x += move[i];
			if (pos.x > windowwidth || pos.x < 0)
			{
				move[i] = -move[i];
			}
			rect[i].sf::Transformable::setPosition(pos.x,pos.y);
			

		}
		window.display();
	}
}