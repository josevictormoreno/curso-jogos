#include <SFML/Graphics.hpp>

int main(){
  sf::RenderWindow window(sf::VideoMode(1280,720), "Imagens e Movimento"); 

  sf::Texture texture;
  texture.loadFromFile("../assets/robs.png");

  sf::Sprite sprite(texture);
  sprite.setPosition(sf::Vector2f(400.f,200.f));

  sf::Vector2u size = texture.getSize();
  sf::Vector2f velocidade(1.9f,1.9f);
  sf::Vector2f pos_text(0.f,-50.f);

  while( window.isOpen() ){
    sf::Event event;
    while( window.pollEvent(event)){
      if( event.type == sf::Event::Closed ){
        window.close();
      }
    }

    if( (sprite.getPosition().x + size.x > window.getSize().x && velocidade.x > 0) ||
         (sprite.getPosition().x < 0 && velocidade.x < 0)){
      velocidade.x = -velocidade.x;
      sprite.setColor( sf::Color::Red);
    }

    if( (sprite.getPosition().y + size.y > window.getSize().y && velocidade.y > 0) ||
         (sprite.getPosition().y < 0 && velocidade.y < 0)){
      velocidade.y = -velocidade.y;
      sprite.setColor( sf::Color::Yellow);
    }

    sprite.setPosition( sprite.getPosition() + velocidade );

    window.clear();
    window.draw( sprite );
    window.display();
  }

  return EXIT_SUCCESS;
}
