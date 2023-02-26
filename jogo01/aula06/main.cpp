#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Textos e Fontes");
  sf::Font font;
  font.loadFromFile("../assets/font.ttf");
  sf::Text text("Curso de jogos!", font, 32);
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
      text.setString("Aula de fontes!");
      text.setFillColor(sf::Color::Red);
    }
    window.clear(sf::Color::Blue);
    window.draw(text);
    window.display();
  }

  return EXIT_SUCCESS;
}