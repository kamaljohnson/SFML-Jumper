#include<iostream>
#include<SFML\Graphics.hpp>
#include "Player.h"

void main()
{
	Player player(40.0f);

	sf::RenderWindow window(sf::VideoMode(640, 480), "Jumper", sf::Style::Resize | sf::Style::Close);

	while (window.isOpen())	//the game loop
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
		//clearing the screen
		window.clear();

		//game logic
		player.move(window);

		//rendering the screen
		window.draw(player.body);
		window.display();
	}

}