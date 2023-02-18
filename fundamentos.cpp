#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
  sf::RenderWindow window;
  sf::VideoMode dimension(1200,720);
  window.create(dimension, "Fundamentos Iniciais");

  while( true) {
    std::cout << "Fundamentos iniciais\n";
  }

  return 0;
}