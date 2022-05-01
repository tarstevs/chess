#include "../include/game_loop.h"

#include <iostream>
#include <codecvt>

class pieces {
public:
  pieces() {
    init_();
  }
  sf::Color white_piece_color = sf::Color(248, 248, 248);
  sf::Color black_piece_color = sf::Color(86, 83, 82);

  char32_t king{};
  char32_t queen{};
  char32_t rook{};
  char32_t bishop{};
  char32_t knight{};
  char32_t pawn{};
private:

  void init_() {

    king = std::stoul("265A", nullptr, 16);
    queen = std::stoul("265B", nullptr, 16);
    rook = std::stoul("265C", nullptr, 16);
    bishop = std::stoul("265D", nullptr, 16);
    knight = std::stoul("265E", nullptr, 16);
    pawn = std::stoul("265F", nullptr, 16);
  }
};