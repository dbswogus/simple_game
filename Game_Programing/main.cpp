#include <SFML/Graphics.hpp>
#include <iostream>

void Player_Move(sf::Vector2f& current_position)
{
	const float speed = 1.25f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		current_position.x -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		current_position.x += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		current_position.y += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		current_position.y -= speed;
	}
}
void Enemy_Move(sf::Vector2f player_pos, sf::Vector2f* enemy_pos, int enemy_num, float* speed)
{
	for (int j = 0; j < enemy_num; j++)
	{
		float enemyToPlayerX = player_pos.x - enemy_pos[j].x;
		float enemyToPlayerY = player_pos.y - enemy_pos[j].y;

		float length = sqrt(enemyToPlayerX * enemyToPlayerX + enemyToPlayerY * enemyToPlayerY);
		
		enemyToPlayerX /= length;
		enemyToPlayerY /= length;

		enemy_pos[j].x += enemyToPlayerX * speed[j];
		enemy_pos[j].y += enemyToPlayerY * speed[j];
	}
	
}
int main()
{
	//window create
	const int windowwidth = 1920;
	const int windowheigh = 1080;
	sf::RenderWindow window(sf::VideoMode(windowwidth, windowheigh), "Player move!");
	
	//Player object create
	sf::RectangleShape Player;

	//set player size and color
	const float player_size_x = 20;
	const float player_size_y = 20;
	Player.setSize(sf::Vector2f(player_size_x, player_size_y));
	Player.setFillColor(sf::Color::Red);


	//Enemy object create and set speed
	const int enemy_num = 10;
	sf::CircleShape* Enemy= new sf::CircleShape[enemy_num];
	float enemy_speed[enemy_num];
	for (int i = 0;i < enemy_num;i++)
	{
		float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		if (r < 0.3f)
		{
			r = 0.3f;
		}
		enemy_speed[i] = r;
	}
	//set enemy size and color and start position
	float enemy_size = 15.0f;
	sf::Vector2f* enemy_pos = new sf::Vector2f[ enemy_num ]; //heap 

	for (int i = 0; i < enemy_num;i++) 
	{
		
		enemy_pos[i].x = windowwidth - 100;
		enemy_pos[i].y = rand() % windowheigh;

		Enemy[i] = sf::CircleShape{ enemy_size };
		Enemy[i].setFillColor(sf::Color::Magenta);
		Enemy[i].setOutlineColor(sf::Color::Blue);
		Enemy[i].setOutlineThickness(1.0f);
	}


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Player move logic
		sf::Vector2f player_position = Player.sf::Transformable::getPosition();
		Player_Move(player_position);
		Player.sf::Transformable::setPosition(player_position);

		//enemy following player 
		Enemy_Move(player_position, enemy_pos, enemy_num, enemy_speed);
		for (int i = 0; i < enemy_num; i++)
		{
			Enemy[i].sf::Transformable::setPosition(enemy_pos[i]);
		}
		
		//fps
		window.clear();
		for (int i = 0;i < enemy_num;i++)
		{
			window.draw(Enemy[i]);
		}
		window.draw(Player);
		window.display();
	}
	
	delete[] enemy_pos;
	delete[] Enemy;
}