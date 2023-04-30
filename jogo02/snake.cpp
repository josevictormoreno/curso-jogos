#include "snake.hpp"
#include "game.hpp"

SnakePosition sposition[100];
FruitPosition fposition;

Snake::Snake()
{
  columns = 20;
  lines = 13;
  size = 64;
  width = size * columns;
  height = size * lines;
  direction = RIGHT;
  snakeSize = 3;
  points = 0;
  timer = 0.f;
  delay = 0.1f;
  fposition.x = fposition.y = 10;
  gameOver = false;
  window.create(sf::VideoMode(width, height), "Snake game 1.0", sf::Style::Titlebar | sf::Style::Close);
  window.setPosition(sf::Vector2i(0, 0));
  backgroundTexture.loadFromFile("assets/bg.png");
  snakeTexture.loadFromFile("assets/snake.png");
  appleTexture.loadFromFile("assets/fruta.png");
  background.setTexture(backgroundTexture);
  snake.setTexture(snakeTexture);
  apple.setTexture(appleTexture);
  font.loadFromFile("assets/font.ttf");
  text.setFont(font);
  text.setString("Pontos: " + std::to_string(points));
  text.setFillColor(sf::Color::White);
  text.setPosition(10, 10);
}

void Snake::run_game()
{
  while (window.isOpen())
  {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    if (timer > delay)
    {
      timer = 0;
      collision();
    }

    if (gameOver)
    {
      points = 0;
      snakeSize = 3;
      fposition.x = fposition.y = 10;
      gameOver = false;
    }

    window.clear();

    for (int i{}; i < columns; ++i)
    {
      for (int j{}; j < lines; ++j)
      {
        background.setPosition(i * size, j * size);
        window.draw(background);
      }
    }

    for (int i{}; i < snakeSize; ++i)
    {
      snake.setPosition(sposition[i].x * size, sposition[i].y * size);
      window.draw(snake);
    }

    apple.setPosition(fposition.x * size, fposition.y * size);
    window.draw(apple);
    window.draw(text);
    window.display();
  }
}

void Snake::collision()
{
  for (int i = snakeSize; i > 0; --i)
  {
    sposition[i].x = sposition[i - 1].x;
    sposition[i].y = sposition[i - 1].y;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != LEFT)
    direction = RIGHT;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != RIGHT)
    direction = LEFT;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != DOWN)
    direction = UP;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != UP)
    direction = DOWN;

  switch (direction)
  {
  case UP:
    sposition[0].y--;
    break;
  case DOWN:
    sposition[0].y++;
    break;
  case RIGHT:
    sposition[0].x++;
    break;
  case LEFT:
    sposition[0].x--;
    break;
  }

  if (sposition[0].x == fposition.x && sposition[0].y == fposition.y)
  {
    snakeSize++;
    points++;
    text.setString("Pontos: " + std::to_string(points));
    fposition.x = std::rand() % columns;
    fposition.y = std::rand() % lines;
  }

  for (int i{}; i < snakeSize; ++i)
  {
    if (sposition[0].x == sposition[i].x && sposition[0].y == sposition[i].y)
    {
      printf("Game Over!");
      gameOver = true;
    }
  }

  if (sposition[0].x > columns)
  {
    sposition[0].x = 0;
  }
  if (sposition[0].x < 0)
  {
    sposition[0].x = columns;
  }

  if (sposition[0].y > lines)
  {
    sposition[0].y = 0;
  }
  if (sposition[0].y < 0)
  {
    sposition[0].y = lines;
  }
}