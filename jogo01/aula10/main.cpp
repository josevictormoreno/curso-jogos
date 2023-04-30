#include <SFML/Graphics.hpp>
#include <iostream>
#include <experimental/random>

int main()
{
  std::srand(std::time(nullptr));
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Minecrap - v0.3");
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(100.f, 100.f));
  rectangle.setFillColor(sf::Color::Green);
  window.setFramerateLimit(144);
  float pos_rectangle = static_cast<float>(std::experimental::randint(10, (int)(window.getSize().x - rectangle.getSize().x - 10)));
  rectangle.setPosition(sf::Vector2(pos_rectangle, 0.f));
  sf::Vector2i pos_mouse;
  sf::Vector2f coord_mouse;
  int score = 0;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      pos_mouse = sf::Mouse::getPosition(window);
      coord_mouse = window.mapPixelToCoords(pos_mouse);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      if (rectangle.getGlobalBounds().contains(coord_mouse))
      {
        pos_rectangle = static_cast<float>(std::experimental::randint(10, (int)(window.getSize().x - rectangle.getSize().x - 10)));
        rectangle.setPosition(sf::Vector2(pos_rectangle, 0.f));
        score++;
        std::cout << "Score: " << score << '\n';
      }
    }

    rectangle.move(0.f, 3.9f);

    if (rectangle.getPosition().y > window.getSize().y)
    {
      pos_rectangle = static_cast<float>(std::experimental::randint(10, (int)(window.getSize().x - rectangle.getSize().x - 10)));
      rectangle.setPosition(sf::Vector2(pos_rectangle, 0.f));
    }

    window.clear();
    window.draw(rectangle);
    window.display();
  }

  return EXIT_SUCCESS;
}