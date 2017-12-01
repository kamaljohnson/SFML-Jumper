#include<iostream>
#include<SFML/Graphics.hpp>
#include "Player.h"

void main()
{
	Player player(10.0f);

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
		window.clear();

		player.move();

		window.draw(player.body);
		window.display();
	}

}
