#include "../include/game_loop.h"
#include "../include/board.h"

#include <SFML/Graphics.hpp>
#include <iostream>

game_loop::game_loop() = default;

void game_loop::run() {

  int window_width = 1000;
  int window_height = 1000;
  sf::RenderWindow render_window(sf::VideoMode(window_width, window_height), "Chess");
  render_window.setVerticalSyncEnabled(true);

  board board_current(render_window.getSize());
  board_current.render_board();
  render_window.clear();
  board_current.draw_board(render_window);
  render_window.display();

  // Game loop (runs the program as long as the render_window is open).
  while (render_window.isOpen()) {
    // Check all the render_window's events that were triggered since the last iteration of the loop.
    sf::Event event{};

    // The pollEvent function returns true if an event was pending, or false if there was none.
    // Note that we use a while loop for our event loop so that all pending events are processed,
    // in case there were several.
    // Event loop
    while (render_window.pollEvent(event)) {
      // "close requested" event: we close the render_window
      if (event.type == sf::Event::Closed)
        render_window.close();

      else if (event.type == sf::Event::Resized) {
        board board_resizeable(event);
        auto w = static_cast<float>(event.size.width);
        auto h = static_cast<float>(event.size.height);

        sf::View view;
        view.setSize({w, h});
        view.setCenter({w / 2.f, h / 2.f});

        render_window.setView(view);
        board_resizeable.render_board();

        render_window.clear();
        board_resizeable.draw_board(render_window);
        render_window.display();

      }

    }
  }
}
