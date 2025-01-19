#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	//window create
	const int windowwidth = 1920;
	const int windowheigh = 1080;
	sf::RenderWindow window(sf::VideoMode(windowwidth, windowheigh), "Player move!");
	
	//Player object create
	sf::RectangleShape Player;

	//set player size and color
	const float player_size_x = 30;
	const float player_size_y = 30;
	Player.setSize(sf::Vector2f(player_size_x, player_size_y));
	Player.setFillColor(sf::Color::Red);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(); 
		window.draw(Player);
		
		//move logic
		const float distance = 0.1f;
		float speed = 5.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Player.sf::Transformable::move(-distance*speed,0.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Player.sf::Transformable::move(distance*speed,0.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Player.sf::Transformable::move(0.0f,distance* speed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Player.sf::Transformable::move(0.0f,-distance* speed);
		}
		window.display();
	}
}