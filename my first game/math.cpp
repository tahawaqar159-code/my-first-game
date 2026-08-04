#include "math.h"

sf::Vector2f math:: normalizevector(sf::Vector2f vector)
{
	float m = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	sf::Vector2f normalizedvector;

	normalizedvector.x = vector.x / m;
	normalizedvector.y = vector.y / m;
	return normalizedvector;
}

bool math::checkCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
	if (rect1.left + rect1.width > rect2.left &&
		rect2.left + rect2.width > rect1.left &&
		rect2.top + rect2.height > rect1.top &&
		rect1.top + rect1.height > rect2.top)
	{
		return true;
	}

	return false;
}
