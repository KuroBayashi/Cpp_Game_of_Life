#ifndef CPP_GAME_OF_LIFE_CELL_H
#define CPP_GAME_OF_LIFE_CELL_H

#include <SFML/Graphics/RectangleShape.hpp>

typedef enum State {
  EMPTY,
  FULL,
  BORN,
  DEAD
} State;

class Cell : public sf::RectangleShape{

  private:

  int m_x;
  int m_y;
  int m_size;
  State m_state;

  public:

  Cell(int x, int y, int size);
  Cell(int x, int y, int size, State state);
  int getX();
  int getY();
  int getSize();
  State getState();
  void setState(State state);

};

#endif //CPP_GAME_OF_LIFE_CELL_H
