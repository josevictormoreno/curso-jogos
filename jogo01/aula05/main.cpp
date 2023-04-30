#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1280,720), "Curso sfml - Formas");
  sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
  rectangle.setFillColor(sf::Color::Red);
  rectangle.setPosition(300.f,200.f);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    auto position = sf::Mouse::getPosition(window);
    if(position.x < (window.getSize().x - rectangle.getSize().x) &&
     position.y < (window.getSize().y - rectangle.getSize().y))
      rectangle.setPosition(sf::Vector2f(position));

    window.clear(sf::Color::Blue);
    window.draw(rectangle);
    window.display();
  }

  return EXIT_SUCCESS;
}