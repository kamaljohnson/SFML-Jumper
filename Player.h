#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Player
{
public:
	sf::RectangleShape body;
	sf::Vector2f pos;
	sf::Vector2f speed;
	bool isJumping;
	float maxYspeed = 0.3f;
	float maxXspeed = 0.3f;
private:
	sf::Texture texture;
	float jumpSpeed = 10.0f;
	float gravity = 0.0005f;
	float accn = 0.0002f;
	float friction = 0.0003f;
public:
	Player(float size);
	~Player();
	void move(sf::RenderWindow &window)
	{
		if (isColliding(sf::Vector2f(100.0f, 280.0f), sf::Vector2f(100.0f, 100.0f), window))
		{

		}
		pos.x += speed.x;
		pos.y -= speed.y;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			if (speed.x > -maxXspeed)
				speed.x -= accn;
		}
		else
		{
			if (speed.x < 0)
				speed.x += friction;	//friction = getFriction() 
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			if (speed.x < maxXspeed)
				speed.x += accn;
		}
		else
		{
			if (speed.x > 0)
				speed.x -= friction;
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))&& !isJumping)
		{
			speed.y = maxYspeed;
			isJumping = true;
		}
		if (isJumping)
		{
			Jump();
			if (speed.y <= -maxYspeed)	//this code must be changed to collision test
			{
				speed.y = 0;
				isJumping = false;
			}
		}
		body.setPosition(pos);
	}
private:
	void Jump()
	{
		speed.y -= gravity;
	}
	bool isColliding(sf::Vector2f pos1, sf::Vector2f size, sf::RenderWindow &window)
	{
		sf::Vector2f pos2 = pos1 + size;
		sf::RectangleShape rect(size);
		rect.setPosition(pos1);
		rect.setFillColor(sf::Color::Blue);
		window.draw(rect);
		//pos1 is the top left cornner one and pos2 is the bottom right one 
		float lx, sx, ly, sy;
		if (pos1.x > pos2.x)
		{
			lx = pos1.x;
			sx = pos2.x;
		}
		else
		{
			lx = pos2.x;
			sx = pos1.x;
		}
		if (pos1.y > pos2.y)
		{
			ly = pos1.y;
			sy = pos2.y;
		}
		else
		{
			ly = pos2.y;
			sy = pos1.y;
		}
		sf::Vector2f s = body.getSize();
		if (pos.x < lx && pos.x + s.x > sx && pos.y < ly && pos.y + s.y > sy)
		{
			rect.setFillColor(sf::Color::Cyan);
			window.draw(rect);
			return(true);
		}
		else
			return(false);
	}
};

