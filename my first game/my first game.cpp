
# include <vector>
# include <math.h>
# include <iostream>
using namespace std;
#pragma once

# include "player.h"
# include "enemy.h"



int main()
{
    // ----------------------------------initialize ------------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1366, 768), "My First Game", sf::Style::Default, settings);
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(360);
    // ----------------------------------initialize ------------------------------------------
  
    //bullet.setSize(sf::Vector2f(15.f, 4.f));
    //bullet.setRotation(-155.f);
    
    
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
	sf::Texture enemytexture;
    sf::Sprite enemysprite;
    //---------------------------------------load--------------------------------------


    
    // --------------------------------------calculate direction of the bullet--------------------------------------
    sf::Vector2f enemyCenter = enemysprite.getPosition() + sf::Vector2f(64.f, 64.f);
    // --------------------------------------calculate direction of the bullet--------------------------------------

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time deltaTimeTimer = clock.restart();
		float deltaTime = deltaTimeTimer.asMilliseconds();

       
        // --------------------------------------update --------------------------------------
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();   
        }
      
        myenemy.Update(deltaTime);
        myplayer.Update(deltaTime,myenemy);
       
        //--------------------------------------update--------------------------------------

        //-------------------------------------- draw any thing here --------------------------------------
        window.clear(sf::Color::Black);
        myenemy.Draw(window);
        myplayer.Draw(window);
        window.draw(myenemy.sprite);
        window.display();
        // --------------------------------------draw any thing here --------------------------------------
      
    }

    return 0;
}


