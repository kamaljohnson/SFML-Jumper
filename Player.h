#pragma once
#include<SFML/Graphics.hpp>

class Player
{
public:
	Player(float size);
	~Player();
	void Jump()
	{
		pos.y -= speed.y;
		speed.y -= gravity;
	}
	void move()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			pos.x -= speed.x;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			pos.x += speed.x;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !isJumping)
		{
			speed.y = maxYspeed;
			isJumping = true;
		}
		if (isJumping)
		{
			Jump();
			if (speed.y <= -maxYspeed)	//this code must be changed to collision test
				isJumping = false;
		}

		body.setPosition(pos);
	}

public:
	sf::RectangleShape body;
	sf::Vector2f pos;
	sf::Vector2f speed = sf::Vector2f(0.1f, 0.1f);
	bool isJumping;
	float maxXspeed = 1.0f;
	float maxYspeed = 0.50f;
private:
	sf::Texture texture;
	float jumpSpeed = 10.0f;
	float gravity = 0.001f;
};

