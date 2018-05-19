#include "header/Grid.h"

#include <SFML/Graphics.hpp>
#include <iostream>


int main(int argc, char** argv) {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  sf::RenderWindow window(
      sf::VideoMode(static_cast<unsigned int>(720), static_cast<unsigned int>(540)),
      "C++ / SFML : Game of Life",
      sf::Style::Titlebar | sf::Style::Close
  );

  window.setFramerateLimit(120);

  Grid grid(&window);

  int editorType = 0;   // 0 : None, 1 : Alive, 2 : Dead
  bool pause = true;

  Cell *cell;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        // On close
        case sf::Event::Closed:
          window.close();
          break;

        // On mouse down
        case sf::Event::MouseButtonPressed:
          if (event.mouseButton.button == sf::Mouse::Left) {
            editorType = (grid.getCell(event.mouseButton.x, event.mouseButton.y)->isAlive()) ? 2 : 1;
            cell = grid.getCell(event.mouseButton.x, event.mouseButton.y);
            if (cell && editorType == 1 && !cell->isAlive()) {
              cell->setState(tState::ALIVE);
            } else if (cell && editorType == 2 && cell->isAlive()) {
              cell->setState(tState::DEAD);
            }
          }
          else if (event.mouseButton.button == sf::Mouse::Right) {
            pause = !pause;
            window.setFramerateLimit(pause ? 120 : 5);
          }
          break;

        // On mouse move
        case sf::Event::MouseMoved:
          cell = grid.getCell(event.mouseMove.x, event.mouseMove.y);
          if (cell && editorType == 1 && !cell->isAlive()) {
            cell->setState(tState::ALIVE);
          } else if (cell && editorType == 2 && cell->isAlive()) {
            cell->setState((tState::DEAD));
          }
          break;

        // On mouse up
        case sf::Event::MouseButtonReleased:
          if (event.mouseButton.button == sf::Mouse::Left) {
            editorType = 0;
          }
          break;

        default:
          break;
      }
    }

    window.clear(sf::Color::Black);
    grid.show();
    window.display();

    if (!pause) {
      grid.update();
    }
  }

  return 0;
}