#include <SFML/Graphics.hpp>
# include <iostream>
# include <vector>

using namespace std;
#pragma once

int main()
{
    vector <string> topvideogames;
    topvideogames.push_back(" gta 1");
    topvideogames.push_back(" gta 2");
    topvideogames.push_back(" gta 3");
    topvideogames.push_back(" gta 4");
    topvideogames.push_back(" gta 5");
    topvideogames.push_back(" gta 6");
    topvideogames.push_back("battle field 2");
    topvideogames.push_back("battle field 1");
    topvideogames.push_back("battle field 3");
    topvideogames.push_back("battle field 4");
	for (int i = 0; i < topvideogames.size(); i++)
	{
		cout << topvideogames[i] << endl;
	}
   














    // initialize 

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "My First Game", sf::Style::Default, settings);

    // initialize
  
    //load

    // enemy
	sf::Texture enemytexture;
	sf::Sprite enemysprite;

    if (enemytexture.loadFromFile("assets/enemy/textures/villain_sheet.png"))
    {
        enemysprite.setTexture(enemytexture);
        //  X,y width and height of the texture to be used for the sprite
        int Xindex = 6;
        int Yindex = 1;
        enemysprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
        enemysprite.scale(sf::Vector2f(2, 2));
    }
    else
    {
        cout << "Error loading  enemy texture" << endl;
    }

    // enemy 
    // player

    sf::Texture playertexture;
    sf::Sprite playersprite;

    if (playertexture.loadFromFile("assets/player/textures/hero.png"))
	{
		playersprite.setTexture(playertexture);
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
    // player
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
        window.draw(enemysprite);
        window.display();
        // draw any thing here 
    }

    return 0;
}


