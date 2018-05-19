#include <algorithm>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../header/Grid.h"

Grid::Grid(sf::RenderWindow *window, int columns, int rows, int cellSize)
    : m_window(window), m_columns(columns), m_rows(rows), m_cellSize(cellSize),
      m_cells(new Cell*[columns*rows]) {

  for (int i = 0, length = columns*rows; i < length; i++) {
    m_cells[i] = new Cell(i % columns, i / columns, cellSize);
  }
}

int Grid::getCountNeighbors(Cell **cells, Cell *cell) {
  int neighborsCount = 0;
  int c_x = cell->getX();
  int c_y = cell->getY();

  int index;
  int neighborsPositions[8][2] = {
      {-1, -1}, {0, -1}, {1, -1},
      {-1,  0},          {1,  0},
      {-1,  1}, {0,  1}, {1,  1}
  };

  for (auto &neighborsPosition : neighborsPositions) {
    index = (c_y + neighborsPosition[0]) * m_columns + c_x + neighborsPosition[1];
    if (index > 0 && index < m_columns*m_rows && cells[index]->getState() == State::FULL) {
        ++neighborsCount;
    }
  }

  return neighborsCount;
}

void Grid::update() {
  auto **cells = new Cell*[m_columns*m_rows];
  for (int i = 0, l = m_columns*m_rows; i < l; i++) {
    cells[i] = new Cell(m_cells[i]->getX(), m_cells[i]->getY(), m_cells[i]->getSize(), m_cells[i]->getState());
  }

  for (int i = 0, l = m_columns*m_rows; i < l; i++) {
    switch (getCountNeighbors(cells, cells[i])) {
      case 2:
        break;
      case 3:
        if (m_cells[i]->getState() == State::EMPTY) {
          m_cells[i]->setState(State::FULL);
        }
        break;
      default:
        if (m_cells[i]->getState() == State::FULL) {
          m_cells[i]->setState(State::EMPTY);
        }
        break;
    }
  }

  for (int i = 0, l = m_columns*m_rows; i < l; i++) {
    delete cells[i];
  }
}

void Grid::toggleCell(int x, int y) {
  Cell *c = m_cells[x / m_cells[0]->getSize() + m_columns * (y / m_cells[0]->getSize())];

  if (c->getState() == State::EMPTY) {
    c->setState(State::FULL);
  }
  else if (c->getState() == State::FULL) {
    c->setState(State::EMPTY);
  }
}

void Grid::show() {
  for (int i = 0, l = m_columns*m_rows; i < l; i++) {
    m_window->draw(*m_cells[i]);
  }
}