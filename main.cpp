#include<iostream>
#include<SFML/Graphics.hpp>
#include "Player.h"

void main()
{
	Player player(40.0f);	//this is the player

	sf::RenderWindow window(sf::VideoMode(640, 480), "Jumper", sf::Style::Resize | sf::Style::Close);


	while (window.isOpen())
	{
		sf::Event evnt;

		while (window.pollEvent(evnt))
		{

			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.pos.x -= player.speed.x;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.pos.x += player.speed.x;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !player.isJumping)
		{
			player.speed.y = player.maxYspeed;
			player.isJumping = true;
		}
		if (player.isJumping)
		{
			player.Jump();
			if (player.speed.y <= -player.maxYspeed)	//this code must be changed to collision test
				player.isJumping = false;
		}

		window.clear();

		player.move();
		window.draw(player.body);

		window.display();
	}

}
