# include <SFML/Graphics.hpp>
#pragma once
class math
{
public:
	static sf::Vector2f  normalizevector(sf::Vector2f vector);
	static bool checkCollision(sf::FloatRect rect1, sf::FloatRect rect2);
};

