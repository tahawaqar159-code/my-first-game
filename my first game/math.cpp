#include "math.h"

sf::Vector2f math:: normalizevector(sf::Vector2f vector)
{
	float m = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	sf::Vector2f normalizedvector;

	normalizedvector.x = vector.x / m;
	normalizedvector.y = vector.y / m;
	return normalizedvector;
}