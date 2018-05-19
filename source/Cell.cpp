#include "../header/Cell.h"

Cell::Cell(int x, int y, int size)
    : Cell(x, y, size, State::EMPTY) {
}

Cell::Cell(int x, int y, int size,  State state)
    : m_x(x), m_y(y), m_size(size), m_state(state) {

  setState(state);
  setSize(sf::Vector2f(size, size));
  setPosition(x*size, y*size);
}

int Cell::getX() {
  return m_x;
}

int Cell::getY() {
  return m_y;
}

int Cell::getSize() {
  return m_size;
}

State Cell::getState() {
  return m_state;
}

void Cell::setState(State state) {
  m_state = state;
  switch (m_state) {
    case State::EMPTY:
      setFillColor(sf::Color(255, 255, 255));
      break;
    case State::FULL:
      setFillColor(sf::Color(150, 150, 150));
      break;
    case State::BORN:
      setFillColor(sf::Color(0, 255, 0));
      break;
    case State::DEAD:
      setFillColor(sf::Color(255, 0, 0));
      break;
    default:
      break;
  }
  update();
}
