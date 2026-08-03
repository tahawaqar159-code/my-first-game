#include "player.h"
# include <iostream>
#include "math.h"

using namespace std;

void player::Initialize()
{
}

void player::Load()
{

	if (texture.loadFromFile("assets/player/textures/hero.png"))
	{
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(1230.f, 620.f));
		//  X,y width and height of the texture to be used for the sprite
		int Xindex = 5;
		int Yindex = 2;
		sprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
		sprite.scale(sf::Vector2f(2, 2));
	}
	else
	{
		cout << "Error loading player texture" << endl;
	}
}

void player::Update(enemy& myenemy)
{
	sf::Vector2f position = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.setPosition(position + sf::Vector2f(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.setPosition(position + sf::Vector2f(-1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.setPosition(position + sf::Vector2f(0, -1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.setPosition(position + sf::Vector2f(0, 1));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 5)));
		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());


	}

	for (int i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f direction = myenemy.sprite.getPosition() - bullets[i].getPosition();
		direction = math::normalizevector(direction);
		bullets[i].setPosition(bullets[i].getPosition() + direction * bulletspeed);
	}

}

void player::Draw (sf::RenderWindow & window)
{

	window.draw(sprite);

	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}

