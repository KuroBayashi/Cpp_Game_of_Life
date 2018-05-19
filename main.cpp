#include <SFML/Graphics.hpp>
#include "header/Grid.h"

int main(int argc, char** argv) {
  sf::RenderWindow window(
      sf::VideoMode(static_cast<unsigned int>(720), static_cast<unsigned int>(540)),
      "C++ / SFML : Game of Life"
  );

  window.setFramerateLimit(5);

  int cellSize = 10;
  Grid grid(&window, window.getSize().x / cellSize, window.getSize().y / cellSize, cellSize);

  bool pause = true;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;

        case sf::Event::MouseButtonPressed:
          if (event.mouseButton.button == sf::Mouse::Left) {
            grid.toggleCell(event.mouseButton.x, event.mouseButton.y);
          }
          else if (event.mouseButton.button == sf::Mouse::Right) {
            pause = !pause;
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