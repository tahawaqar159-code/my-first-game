#include <SFML/Graphics.hpp>
# include <iostream>
using namespace std;
#pragma once

int main()
{
    // initialize 

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "My First Game", sf::Style::Default, settings);

    // initialize
  
    //load
    sf::Texture playertexture;
    sf::Sprite playersprite;

    if (playertexture.loadFromFile("assets/player/textures/skeleton.png"))
	{
		playersprite.setTexture(playertexture);
		//  X,y width and height of the texture to be used for the sprite
        int Xindex = 0;
		int Yindex = 0;
        playersprite.setTextureRect(sf::IntRect(Xindex * 64,Yindex*64 ,64,64));
        playersprite.scale(sf::Vector2f(2, 2));
	}
	else
	{
	cout << "Error loading player texture" << endl;
	}
    //load 

    while (window.isOpen())
    {
        // update 
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
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
        // update

        // draw any thing here 
        window.clear(sf::Color::Black);
       
        window.draw(playersprite);
        window.display();
        // draw any thing here 
    }

    return 0;
}


