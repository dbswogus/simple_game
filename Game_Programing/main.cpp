#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Enemy.h"
int main()
{
	const int windowwidth = 1920;
	const int windowheigh = 1080;
	sf::RenderWindow window(sf::VideoMode(windowwidth, windowheigh), "Player move!");

	//player
	sf::Vector2f playerStartPosition = sf::Vector2f(50.0f, 50.0f);
	sf::Vector2f playerSize = sf::Vector2f(20.0f, 20.0f);
	sf::Color playerColor = sf::Color::Red;
	float playerSpeed = 2.25f;

	Player player{ playerStartPosition,playerSize,playerColor,playerSpeed };

	//enemies
	const int enemyNum = 10;
	Enemy enemies[enemyNum];
	float enemySize = 15.0f;
	sf::Color enemyColor = sf::Color::Magenta;
	Player* playerPtr = &player;
	
	for (int i = 0;i < enemyNum;i++)
	{
		float enemySpeed = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) + 1.0f;
		sf::Vector2f enemyStartPosition = sf::Vector2f(windowwidth - 100, rand() % windowheigh);
		enemies[i] = Enemy{ enemySize,enemySpeed,enemyColor,enemyStartPosition,playerPtr };
	}
	
	//window
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//player and enemies move logic
		player.Update();
		for (int i = 0;i < enemyNum;i++)
		{
			enemies[i].Update();
		}

		window.clear();

		for (int i = 0;i < enemyNum;i++)
		{
			enemies[i].Draw(window);
		}
		player.Draw(window);
		
		window.display();
	}
}