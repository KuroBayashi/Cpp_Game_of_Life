#include <iostream>
#include "../header/Grid.h"

Grid::Grid(sf::RenderWindow *window)
    : m_window(window), m_columns(0), m_rows(0), m_cells(), m_oldCells() {

  m_rows = m_window->getSize().y / Cell::SIZE;
  m_columns = m_window->getSize().x / Cell::SIZE;

  for (unsigned int j = 0; j < m_rows; j++) {
    vector<Cell*> row;
    vector<Cell*> oldRow;

    for (unsigned int i = 0; i < m_columns; i++) {
      tState state = (rand() % 5 > 1) ? tState::ALIVE : tState::DEAD;
      row.push_back(new Cell(i, j, state));
      oldRow.push_back(new Cell(i, j, state));
    }

    m_cells.push_back(row);
    m_oldCells.push_back(oldRow);
  }
}

int Grid::getCountNeighbors(int x, int y) {
  int neighborsCount = 0;
  int neighborsPositions[8][2] = {
      {-1, -1}, {0, -1}, {1, -1},
      {-1,  0},          {1,  0},
      {-1,  1}, {0,  1}, {1,  1}
  };

  int nx, ny;
  for (auto &neighborPosition : neighborsPositions) {
    nx = x + neighborPosition[0];
    ny = y + neighborPosition[1];
    
    nx = (nx < 0) ? m_columns-1 : (nx >= m_columns) ? 0 : nx;
    ny = (ny < 0) ? m_rows-1 : (ny >= m_rows) ? 0 : ny;

    if (m_oldCells.at(static_cast<unsigned int>(ny)).at(static_cast<unsigned int>(nx))->isAlive()) {
      neighborsCount++;
    }
  }

  return neighborsCount;
}

void Grid::update() {
  for (unsigned int j = 0; j < m_rows; j++) {
    for (unsigned int i = 0; i < m_columns; i++) {
      m_oldCells.at(j).at(i)->setState(m_cells.at(j).at(i)->getState());
    }
  }

  for (unsigned int j = 0; j < m_rows; j++) {
    for (unsigned int i = 0; i < m_columns; i++) {
      switch (getCountNeighbors(i, j)) {
        case 2:
          break;
        case 3:
          if (!m_oldCells.at(j).at(i)->isAlive()) {
            m_cells.at(j).at(i)->setState(tState::ALIVE);
          }
          break;
        default:
          if (m_oldCells.at(j).at(i)->isAlive()) {
            m_cells.at(j).at(i)->setState(tState::DEAD);
          }
          break;
      }
    }
  }
}

Cell* Grid::getCell(int x, int y) {
  Cell *cell = nullptr;
  try {
    cell = m_cells.at(static_cast<unsigned int>(y)/Cell::SIZE).at(static_cast<unsigned int>(x)/Cell::SIZE);
  }
  catch (const std::out_of_range& oor) {
    //std::cerr << "Out of Range error: " << oor.what() << '\n';
  }

  return cell;
}

void Grid::show() {
  for (auto &line : m_cells) {
    for (auto &cell : line) {
      m_window->draw(*cell);
    }
  }
}