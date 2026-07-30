#include <SFML/Graphics.hpp>
# include <iostream>
# include <vector>
# include <math.h>
using namespace std;
#pragma once

sf :: Vector2f  normalizevector(sf::Vector2f vector)
{
   float m = sqrt((vector.x * vector.x) + (vector.y * vector.y));
   sf::Vector2f normalizedvector;

   normalizedvector. x =vector.x / m;
   normalizedvector.y = vector.y / m;
   return normalizedvector;
}

int main()
{
    // ----------------initialize 

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "My First Game", sf::Style::Default, settings);

    // ----------------initialize
    vector<sf::RectangleShape> bullets;
  
    //bullet.setSize(sf::Vector2f(15.f, 4.f));
    //bullet.setRotation(-155.f);
    float bulletspeed = 0.5f;
    sf::Vector2f direction;
    //---------------load

    // ---------------enemy
	sf::Texture enemytexture;
	sf::Sprite enemysprite;

    if (enemytexture.loadFromFile("assets/enemy/textures/villain_sheet.png"))
    {
        enemysprite.setTexture(enemytexture);
        enemysprite.setPosition(sf::Vector2f(20.f, 20.f));
        //  X,y width and height of the texture to be used for the sprite
        int Xindex = 4;
        int Yindex = 3;
        enemysprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
        enemysprite.scale(sf::Vector2f(2, 2));
    }
    else
    {
        cout << "Error loading  enemy texture" << endl;
    }

    // -----------enemy 
    // -----------player

    sf::Texture playertexture;
    sf::Sprite playersprite;

    if (playertexture.loadFromFile("assets/player/textures/hero.png"))
	{
		playersprite.setTexture(playertexture);
        playersprite.setPosition(sf::Vector2f(1230.f, 620.f));
		//  X,y width and height of the texture to be used for the sprite
        int Xindex = 5;
		int Yindex = 2;
        playersprite.setTextureRect(sf::IntRect(Xindex * 64,Yindex*64 ,64,64));
        playersprite.scale(sf::Vector2f(2, 2));
	}
	else
	{
	cout << "Error loading player texture" << endl;
	}
    // -----------player
    //---------------load
    
    // -------calculate direction of the bullet
    sf::Vector2f enemyCenter = enemysprite.getPosition() + sf::Vector2f(64.f, 64.f);
    // -------calculate direction of the bullet
   

    while (window.isOpen())
    {
        // ----------------update 
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();   
        }

        //bullet.setPosition(bullet.getPosition() + direction *bulletspeed);

        sf::Vector2f position = playersprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
			playersprite.setPosition(position + sf::Vector2f(1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {    
            playersprite.setPosition(position + sf::Vector2f(-1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {     
            playersprite.setPosition(position + sf::Vector2f(0,-1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {    
            playersprite.setPosition(position + sf::Vector2f(0, 1));
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 5)));
            int i = bullets.size() - 1;
            bullets[i].setPosition(playersprite.getPosition());

            direction = enemyCenter - bullets[i].getPosition();   // no "sf::Vector2f" here
            direction = normalizevector(direction);
        }
        for (int i = 0; i < bullets.size(); i++)
        {
            bullets[i].setPosition(bullets[i].getPosition() + direction * bulletspeed );
        }


        // ----------------update

        //----------------- draw any thing here 
        window.clear(sf::Color::Black);
        window.draw(playersprite);
        window.draw(enemysprite);

        for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
		
        window.display();
        // -----------------draw any thing here 
    }

    return 0;
}


