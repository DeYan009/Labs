#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lab18");
    window.setFramerateLimit(60);

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(100, 250, 50));
    circle.setPosition(100.f, 150.f);
    circle.setRotation(45.f);

    sf::RectangleShape rectangle(sf::Vector2f(120.f, 80.f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(400.f, 200.f);
    rectangle.setOrigin(60.f, 40.f);
    rectangle.setRotation(15.f);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.f, 0.f));
    triangle.setPoint(1, sf::Vector2f(100.f, 0.f));
    triangle.setPoint(2, sf::Vector2f(50.f, 100.f));
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(600.f, 300.f);
    triangle.setRotation(30.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        rectangle.rotate(-0.8f);
        triangle.rotate(1.2f);

        window.clear(sf::Color::Black);

        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        window.display();
    }

    return 0;
}

// #include <SFML/Graphics.hpp>

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }

//     return 0;
// }