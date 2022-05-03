#pragma once

#include <SFML/Graphics.hpp>

class board_view {
public:
  board_view(const sf::Event &event, sf::RenderWindow &render_window);
  void configure_and_set_view();

private:
  const sf::Event &event;
  sf::RenderWindow &render_window;
  sf::View view;
};
