#include <SFML/Graphics.hpp>

int main()
{
    // initialize 
    sf::RenderWindow window(sf::VideoMode(1366, 768), "My First Game");
    sf::CircleShape shape(50.0f);
	sf::RectangleShape rectangle(sf::Vector2f(120.0f, 60.0f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Red);

    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(sf::Vector2f(300, 300));
    rectangle.setOutlineColor(sf::Color::Cyan);
    rectangle.setOutlineThickness(15);
    // initialize

    while(window.isOpen())
    {
        // update 
		sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf:: Event :: Closed)
				window.close();
        }
        // update

        // draw any thing here 
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(rectangle);
		window.display();
        // draw any thing here 
    }



    return 0;
}