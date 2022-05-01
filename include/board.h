#ifndef _BOARD_H_
#define _BOARD_H_

#include <SFML/Graphics.hpp>

class board {
public:
  void render_board(sf::Vector2u windowSize);
  void drawBoard(sf::RenderWindow &render_window) const;

private:

  sf::RenderTexture render_texture;

  sf::Color white_square = sf::Color(254, 232, 209);
  sf::Color black_square = sf::Color(83, 120, 99);
  sf::Color window_background_color = sf::Color(169, 169, 169);

  void render_algebraic_notation(int i, int j, float x_offset, float square_size);
};

#endif // _BOARD_H_
