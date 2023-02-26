#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1280,720), "Minecrap - v0.1");
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(100.f,100.f));
  rectangle.setFillColor(sf::Color::Green);
  rectangle.setPosition(sf::Vector2(10.f,10.f));

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    rectangle.move(0.f, 0.9f);

    window.clear();
    window.draw(rectangle);
    window.display();
  }

  return EXIT_SUCCESS;
}