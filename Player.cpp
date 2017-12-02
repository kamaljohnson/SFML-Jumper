#include "Player.h"
#include<SFML/Graphics.hpp>


Player::Player(float size)
{
	body.setSize(sf::Vector2f(size, size));
	texture.loadFromFile("texture1.png");
	body.setTexture(&texture);
	pos = sf::Vector2f(150.0f, 200.0f);
	speed = sf::Vector2f(0.0f, 0.0f);
	isJumping = false;
}


Player::~Player()
{

}
