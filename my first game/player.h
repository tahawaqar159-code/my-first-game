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
public:
	sf::Sprite sprite;
public :
	void Initialize();
	void Load();

	void Update(enemy& myenemy);
	void Draw(sf::RenderWindow& window);
};

