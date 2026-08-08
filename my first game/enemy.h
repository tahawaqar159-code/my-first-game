#pragma once
# include <SFML/Graphics.hpp>

class enemy
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;
	sf::Vector2i size;
	sf::RectangleShape boundingRectangle;
public:
	void Initialize();
	void Load();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};
