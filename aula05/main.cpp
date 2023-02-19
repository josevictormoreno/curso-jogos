#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1280,720), "Fundamentos iniciais");
  sf::CircleShape circle(100.f);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Blue);
    window.draw(circle);
    window.display();
  }

  return EXIT_SUCCESS;
}