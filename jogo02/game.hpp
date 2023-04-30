#ifndef GAME_H 
#define GAME_H

struct SnakePosition{
  int x, y;
};

struct FruitPosition{
  int x, y;
};

enum Direction{
  UP = 0,
  DOWN = 1,
  LEFT = 2,
  RIGHT = 3
};

#endif
