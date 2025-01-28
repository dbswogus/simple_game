#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
int main()
{
	const int windowwidth = 1920;
	const int windowheigh = 1080;
	sf::RenderWindow window(sf::VideoMode(windowwidth, windowheigh), "Player move!");
	window.setFramerateLimit(60);
	//player
	sf::Vector2f playerStartPosition = sf::Vector2f(50.0f, 50.0f);
	sf::Vector2f playerSize = sf::Vector2f(20.0f, 20.0f);
	sf::Color playerColor = sf::Color::Red;
	float playerSpeed = 1750.0f;

	Player player{ playerStartPosition,playerSize,playerColor,playerSpeed };

	//enemies
	std::vector<Enemy*> enemies;
	float enemySize = 15.0f;
	sf::Color enemyColor = sf::Color::Magenta;
	Player* playerPtr = &player;
	
	for (int i = 0;i < 10;i++)
	{
		float enemySpeed = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX))+1)*700.0f;
		sf::Vector2f enemyStartPosition = sf::Vector2f(windowwidth - 100, rand() % windowheigh);
		
		Enemy* enemy = new Enemy{ enemySize,enemySpeed,enemyColor,enemyStartPosition,playerPtr };
		enemies.push_back(enemy);
	}
	
	//bullet
	std::vector<Bullet> bullets;
	sf::Clock time;
	
	float bulletTime = 1.0f;
	float dtP = 0.0f;
	
	
	//window
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		float dt = time.restart().asSeconds();
		dtP += dt;
		if (dtP > bulletTime)
		{
			dtP = 0.0f;
			//ÃÑ¾Ë °´Ã¼ »ý¼º
			bullets.push_back({ player.GetPosition(), 700, playerPtr });
		}
		//¸Ê ¹ÛÀ¸·Î ³ª°£ °´Ã¼ »èÁ¦
		for (int i = 0;i < bullets.size();i++)
		{
			if (bullets[i].GetPos().x > windowwidth)
			{
				bullets.erase(bullets.begin() + i);
				std::cout<<"Áö¿öÁü"<<std::endl;
			}
		}
		//player and enemies move logic
		player.Update(dt);
		for (int i = 0;i < enemies.size();i++)
		{
			enemies[i]->Update(dt);
		}
		for(int i =0; i < bullets.size();i++)
		{
			bullets[i].Update(dt);
		}
		window.clear();

		for (int i = 0;i < enemies.size();i++)
		{
			enemies[i]->Draw(window);
		}
		player.Draw(window);
		for (int i = 0;i < bullets.size();i++) 
		{
			bullets[i].Draw(window);
		}
		window.display();
	}
	for (int i = 0; i < enemies.size();i++)
	{
		delete enemies[i];
	}
}