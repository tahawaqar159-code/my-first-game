#pragma once

int main()
{
    // initialize 

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "My First Game", sf::Style::Default,settings);
    sf::CircleShape shape(50.0f, 50);
    //setting the properties of circle 
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Red);
    //setting the properties of rectangle
    sf::RectangleShape rectangle(sf::Vector2f(120.0f,2));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(sf::Vector2f(300, 300));
    rectangle.setOutlineColor(sf::Color::Cyan);
    rectangle.setOutlineThickness(15);
    rectangle.setOrigin(sf::Vector2f(0.5f, 0.5f));
    rectangle.setRotation(45);

    // define a triangle
    sf::CircleShape triangle(80.f, 3);
    triangle.setFillColor(sf::Color::Yellow);
    triangle.setPosition(sf::Vector2f(500, 100));
    // define a square
    sf::CircleShape square(80.f, 4);
    square.setFillColor(sf::Color::Magenta);
    square.setPosition(sf::Vector2f(700, 100));

    // define an octagon
    sf::CircleShape octagon(80.f, 8);
    octagon.setFillColor(sf::Color::Green);
    octagon.setPosition(sf::Vector2f(900, 100));

    // create an empty shape
    sf::ConvexShape convex;

    // resize it to 5 points
    convex.setPointCount(5);

    // define the points
    convex.setPoint(0, { 10.f, 10.f });
    convex.setPoint(1, { 150.f, 20.f });
    convex.setPoint(2, { 120.f, 90.f });
    convex.setPoint(3, { 30.f, 100.f });
    convex.setPoint(4, { 20.f, 50.f });

    // initialize

    while (window.isOpen())
    {
        // update 
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // update

        // draw any thing here 
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(rectangle);

        window.draw(triangle);
        window.draw(square);
        window.draw(octagon);
        window.draw(convex);
        window.display();
        // draw any thing here 
    }



    return 0;
}
