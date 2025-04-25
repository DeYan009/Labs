#include <SFML/Graphics.hpp>

int main()
{
    // Создаем окно (синтаксис SFML 3)
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3 Window");

    // Создаем круг
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({400.f, 300.f});  // Центр окна (используем {} для вектора)

    // Основной цикл
    while (window.isOpen())
    {
        // Обработка событий
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.is<sf::Event::Closed>())
                window.close();
        }

        // Отрисовка
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}