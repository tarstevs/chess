#include "../include/game_loop.h"
#include "../include/board.h"

#include <SFML/Graphics.hpp>

game_loop::game_loop() = default;

void game_loop::run() {

  int window_width = 1000;
  int window_height = 1000;
  sf::RenderWindow render_window(sf::VideoMode(window_width, window_height), "Chess");

  sf::Event event{};

  sf::View view = render_window.getDefaultView();

  board board;
  board.render_board(render_window.getSize());

  // Game loop (runs the program as long as the render_window is open).
  while (render_window.isOpen()) {
    // Check all the render_window's events that were triggered since the last iteration of the loop.
    sf::Event event;
    // The pollEvent function returns true if an event was pending, or false if there was none.
    // Note that we use a while loop for our event loop so that all pending events are processed,
    // in case there were several.
    // Event loop
    while (render_window.pollEvent(event)) {
      // "close requested" event: we close the render_window
      if (event.type == sf::Event::Closed)
        render_window.close();

      else if (event.type == sf::Event::Resized) {
        float w = static_cast<float>(event.size.width);
        float h = static_cast<float>(event.size.height);
        view.setSize({w, h});
        view.setCenter({w / 2.f, h / 2.f});
        render_window.setView(view);
        board.render_board({event.size.width, event.size.height});
      }

    }
    render_window.clear();
    board.drawBoard(render_window);
    render_window.display();
  }
}
