#include "enemy.h"
# include <iostream>

using namespace std;

void enemy::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(2);

    size = sf::Vector2i(64, 64);
}

void enemy::Load()
{

    if (texture.loadFromFile("assets/enemy/textures/villain_sheet.png"))
    {
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1230.f, 520.f));
        //  X,y width and height of the texture to be used for the sprite
        int Xindex = 4;
        int Yindex = 3;
        sprite.setTextureRect(sf::IntRect(Xindex * size.x, Yindex * size.y, size.x, size.y));
        sprite.scale(sf::Vector2f(2, 2));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
    {
        cout << "Error loading  enemy texture" << endl;
    }
}

void enemy::Update()
{
    boundingRectangle.setPosition(sprite.getPosition());
}


void enemy::Draw(sf::RenderWindow& window)
{

    window.draw(sprite);
    window.draw(boundingRectangle);
}
