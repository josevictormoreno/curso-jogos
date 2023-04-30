#ifndef SNAKE_H 
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"

class Snake {
	public: 
		Snake();
		int columns;
		int lines;
		int size;
		int width;
		int height;
		int snakeSize;
		int points;
		float timer, delay;
		Direction direction;
		bool gameOver;
		sf::RenderWindow window;
		sf::Texture backgroundTexture;
		sf::Texture snakeTexture;
		sf::Texture appleTexture;
		sf::Sprite background;
		sf::Sprite snake;
		sf::Sprite apple;
		sf::Clock clock;
		sf::Font font;
		sf::Text text;

		void run_game();
		void collision();
};

#endif
