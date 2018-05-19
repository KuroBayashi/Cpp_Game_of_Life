#ifndef CPP_GAME_OF_LIFE_GRID_H
#define CPP_GAME_OF_LIFE_GRID_H

#include "Cell.h"

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

using std::vector;

class Grid {

  private:
  sf::RenderWindow *m_window;
  int m_columns;
  int m_rows;
  vector<vector<Cell*>> m_cells;
  vector<vector<Cell*>> m_oldCells;

  int getCountNeighbors(int x, int y);

  public:
  explicit Grid(sf::RenderWindow *window);
  void update();
  void show();
  Cell* getCell(int x, int y);
};

#endif //CPP_GAME_OF_LIFE_GRID_H
