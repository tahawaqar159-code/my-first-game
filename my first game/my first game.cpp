#include <SFML/Graphics.hpp>

int main()
{
    // initialize 
    sf::RenderWindow window(sf::VideoMode(1366, 768), "My First Game");
    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition();
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

		window.display();
        // draw any thing here 
    }



    return 0;
}