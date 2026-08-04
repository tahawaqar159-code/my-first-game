#include "player.h"
# include <iostream>
#include "math.h"

using namespace std;

void player::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(2);

	size = sf::Vector2i(64, 64);

}

void player::Load()
{

	if (texture.loadFromFile("assets/player/textures/hero.png"))
	{
		sprite.setTexture(texture);
		//  X,y width and height of the texture to be used for the sprite
		int Xindex = 5;
		int Yindex = 2;
		sprite.setTextureRect(sf::IntRect(Xindex * size.x, Yindex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(10.f, 10.f));
		
		sprite.scale(sf::Vector2f(2, 2));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
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
	boundingRectangle.setPosition(sprite.getPosition());
	if (math::checkCollision(sprite.getGlobalBounds(), myenemy.sprite.getGlobalBounds()))
	{
		cout << "Player and enemy collided!" << endl;
	}
}

void player::Draw (sf::RenderWindow & window)
{

	window.draw(sprite);
	window.draw(boundingRectangle);

	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}

