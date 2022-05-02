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
  std::unordered_map<std::string, std::string> board_state{};
  std::unordered_map<int, std::string> row_index_to_alg_notation_num{};
  std::unordered_map<int, std::string> column_index_to_alg_notation_letter{};

  sf::Vector2u windowSize;
  sf::RenderTexture render_texture;
  sf::Color white_square_color = sf::Color(238, 238, 211);
  sf::Color black_square_color = sf::Color(118, 150, 86);
  sf::Color window_background_color = sf::Color(169, 169, 169);
  sf::Font free_sarif_font;
  sf::Font open_sans_font;
  std::unordered_map<int, std::string> alg_notation_letter_map;
  std::unordered_map<int, int> alg_notation_number_map;
  float x_offset{};
  float square_size{};
  void render_square(int i, int j);
  void render_piece(int i, int j);
  void render_algebraic_notation(int i, int j);
  void set_free_sarif_font();
  void set_open_sans_font();
  void set_alg_notation_letter_map();
  void set_alg_notation_number_map();
  void set_initial_board_state();
  void set_indices_to_alg_notation();
  std::string get_algebraic_notation(int i, int j);
  void init_();

};

#endif // _BOARD_H_
