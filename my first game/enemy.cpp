#include "enemy.h"
# include <iostream>

using namespace std;

void enemy::Initialize()
{


}

void enemy::Load()
{

    if (texture.loadFromFile("assets/enemy/textures/villain_sheet.png"))
    {
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(20.f, 20.f));
        //  X,y width and height of the texture to be used for the sprite
        int Xindex = 4;
        int Yindex = 3;
        sprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
        sprite.scale(sf::Vector2f(2, 2));
    }
    else
    {
        cout << "Error loading  enemy texture" << endl;
    }
}

void enemy::Update()
{
}


void enemy::Draw(sf::RenderWindow& window)
{

    window.draw(sprite);
}
