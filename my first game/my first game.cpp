
# include <vector>
# include <math.h>
using namespace std;
#pragma once

# include "player.h"
# include "enemy.h"

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
    // ----------------------------------initialize ------------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "My First Game", sf::Style::Default, settings);

    // ----------------------------------initialize ------------------------------------------
    vector<sf::RectangleShape> bullets;
  
    //bullet.setSize(sf::Vector2f(15.f, 4.f));
    //bullet.setRotation(-155.f);
    float bulletspeed = 0.5f;
    
    player myplayer;
    enemy myenemy;
    // ----------------------------------initialize ------------------------------------------
    myplayer.Initialize();
    myenemy.Initialize();
    // ----------------------------------initialize ------------------------------------------

       //---------------------------------------load--------------------------------------
    myplayer.Load();
    myenemy.Load(); 
    //---------------------------------------load--------------------------------------
    // --------------------------------------enemy--------------------------------------
	sf::Texture enemytexture;
	sf::Sprite enemysprite;

    // --------------------------------------enemy-------------------------------------- 
    //---------------------------------------player--------------------------------------

 
    // --------------------------------------player--------------------------------------
    //---------------------------------------load--------------------------------------
    
    // --------------------------------------calculate direction of the bullet--------------------------------------
    sf::Vector2f enemyCenter = enemysprite.getPosition() + sf::Vector2f(64.f, 64.f);
    // --------------------------------------calculate direction of the bullet--------------------------------------
   

    while (window.isOpen())
    {
        // --------------------------------------update --------------------------------------
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();   
        }

        myplayer.Update();
        myenemy.Update();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 5)));
            int i = bullets.size() - 1;
            bullets[i].setPosition(myplayer.sprite.getPosition());

            
        }

        for (int i = 0; i < bullets.size(); i++)
        {
            sf::Vector2f direction =myenemy.sprite.getPosition() - bullets[i].getPosition();
            direction = normalizevector(direction);
            bullets[i].setPosition(bullets[i].getPosition() + direction * bulletspeed );
        }
      
        //--------------------------------------update--------------------------------------

        //-------------------------------------- draw any thing here --------------------------------------
        window.clear(sf::Color::Black);

        myenemy.Draw(window);
        myplayer.Draw(window);

        window.draw(myenemy.sprite);

        for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        window.display();
        // --------------------------------------draw any thing here --------------------------------------
    }

    return 0;
}


