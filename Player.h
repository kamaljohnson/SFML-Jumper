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

