#include "../include/game_loop.h"

#include <iostream>
#include <codecvt>

class pieces {
public:
  pieces();
  sf::Color white_piece_color = sf::Color(248, 248, 248);
  sf::Color black_piece_color = sf::Color(86, 83, 82);

  char32_t king{};
  char32_t queen{};
  char32_t rook{};
  char32_t bishop{};
  char32_t knight{};
  char32_t pawn{};

  sf::Text get_positioned_sfml_text_graphic_for_piece(const std::string &piece_for_square,
                                                      float square_size,
                                                      float x_offset,
                                                      int i,
                                                      int j);

private:
  sf::Font free_sarif_font;
  char32_t get_char32_piece_code(const std::string &piece_name) const;
  void set_free_sarif_font();
  void init_();

};