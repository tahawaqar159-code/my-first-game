#pragma once
# include <SFML/Graphics.hpp>
# include "enemy.h"
#include <vector>

using namespace std;

class player
{
private :
	sf::Texture texture;

	vector<sf::RectangleShape> bullets;
	float bulletspeed = 0.5f;
	float playerspeed = 1.0f;
	sf::RectangleShape boundingRectangle;	
	sf::Vector2i size;
public:
	sf::Sprite sprite;
public :
	void Initialize();
	void Load();
	void Update(float deltaTime, enemy& myenemy);
	void Draw(sf::RenderWindow& window);
};

