#include <SFML/Graphics.hpp>
#include <iostream>
#include <experimental/random>

int main()
{
  //TODO Corrigir variaveis, atualizar para orientação a objetos
  std::srand(std::time(nullptr));
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Minecrap - v0.4");
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(100.f, 100.f));
  rectangle.setFillColor(sf::Color::Green);
  window.setFramerateLimit(144);
  float pos_rectangle = static_cast<float>(std::experimental::randint(10, (int)(window.getSize().x - rectangle.getSize().x - 10)));
  rectangle.setPosition(sf::Vector2(pos_rectangle, 0.f));
  sf::Vector2i pos_mouse;
  sf::Vector2f coord_mouse;
  std::vector<sf::RectangleShape> rectangles;
  size_t max_rectangles = 5;
  float max_speed = 10.f;
  float speed = max_speed;
  int score = 0;
  int life = 3;

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

    if (rectangles.size() < max_rectangles)
    {
      if (speed >= max_speed)
      {
        pos_rectangle = static_cast<float>(std::experimental::randint(10, (int)(window.getSize().x - rectangle.getSize().x - 10)));
        rectangle.setPosition(sf::Vector2(pos_rectangle, 0.f));
        rectangles.push_back(rectangle);
        speed = 0.f;
      }
      else
      {
        speed += 1.f;
      }
    }

    for (size_t i = 0; i < rectangles.size(); i++)
    {
      bool del = false;
      rectangles[i].move(0.f, 5.f);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
        if (rectangles[i].getGlobalBounds().contains(coord_mouse))
        {
          del = true;
          score += 10.f;
        }
      }

      if (rectangles[i].getPosition().y > window.getSize().y)
      {
        del = true;
      }

      if (del)
      {
        rectangles.erase(rectangles.begin() + i);
        life--;
        if(life == 0)
          std::cout << "game over!"<<'\n'; 
          window.close();
      }
    }

    window.clear();
    for (auto &e : rectangles)
    {
      window.draw( e );
    }
    window.display();
  }

  return EXIT_SUCCESS;
}
