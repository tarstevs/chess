#ifndef _BOARD_H_
#define _BOARD_H_

#include <SFML/Graphics.hpp>

class board {
public:
  explicit board(sf::Vector2u windowSize);
  explicit board(sf::Event &event);
  void render_board();
  void drawBoard(sf::RenderWindow &render_window) const;

private:
  sf::Vector2u windowSize{1000, 1000};
  sf::RenderTexture render_texture;

  sf::Color white_square = sf::Color(254, 232, 209);
  sf::Color black_square = sf::Color(83, 120, 99);
  sf::Color window_background_color = sf::Color(169, 169, 169);

  void render_algebraic_notation(int i, int j, float x_offset, float square_size);
  template<typename T>
  auto func(T obj, int i, int j, float x_offset, float square_size);
  static std::string get_letter(int j);
  static int get_number(int i);
};

#endif // _BOARD_H_
