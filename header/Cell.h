#ifndef CPP_GAME_OF_LIFE_CELL_H
#define CPP_GAME_OF_LIFE_CELL_H

#include <SFML/Graphics/RectangleShape.hpp>

typedef enum eState {
  DEAD,
  ALIVE
} tState;

class Cell : public sf::RectangleShape{

  private:
  tState m_state;

  public:
  static const int SIZE = 10;

  Cell(int x, int y);
  Cell(int x, int y, tState state);
  bool isAlive();
  tState getState();
  void setState(tState state);

};

#endif //CPP_GAME_OF_LIFE_CELL_H
