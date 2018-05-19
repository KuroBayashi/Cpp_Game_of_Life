#include "../header/Cell.h"

Cell::Cell(int x, int y)
    : Cell(x, y, tState::DEAD){}

Cell::Cell(int x, int y, tState state)
    : m_state(state) {

  setState(state);
  setSize(sf::Vector2f(Cell::SIZE, Cell::SIZE));
  setPosition(x*Cell::SIZE, y*Cell::SIZE);
}

bool Cell::isAlive() {
  return m_state == tState::ALIVE;
}

tState Cell::getState() {
  return m_state;
}

void Cell::setState(tState state) {
  m_state = state;
  switch (m_state) {
    case tState::DEAD:
      setFillColor(sf::Color(255, 255, 255));
      break;
    case tState::ALIVE:
      setFillColor(sf::Color(150, 150, 150));
      break;
    default:
      break;
  }
  update();
}
