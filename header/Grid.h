#ifndef CPP_GAME_OF_LIFE_GRID_H
#define CPP_GAME_OF_LIFE_GRID_H

#include "Cell.h"

class Grid {

  private:

  sf::RenderWindow *m_window;
  int m_columns;
  int m_rows;
  int m_cellSize;
  Cell **m_cells;

  int getCountNeighbors(Cell **cells, Cell *cell);

  public:

  Grid(sf::RenderWindow *window, int columns, int rows, int cellSize);
  void update();
  void toggleCell(int x, int y);
  void show();

};

#endif //CPP_GAME_OF_LIFE_GRID_H
