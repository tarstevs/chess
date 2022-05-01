#include "../include/game_loop.h"

#include <iostream>
#include <codecvt>

class pieces {
public:
  pieces() {
    init_();
  }
  char32_t white_king{};
  char32_t white_queen{};
  char32_t white_rook{};
  char32_t white_bishop{};
  char32_t white_knight{};
  char32_t white_pawn{};

  char32_t black_king{};
  char32_t black_queen{};
  char32_t black_rook{};
  char32_t black_bishop{};
  char32_t black_knight{};
  char32_t black_pawn{};
private:

  void init_() {
    white_king = std::stoul("2654", nullptr, 16);
    white_queen = std::stoul("2655", nullptr, 16);
    white_rook = std::stoul("2656", nullptr, 16);
    white_bishop = std::stoul("2657", nullptr, 16);
    white_knight = std::stoul("2658", nullptr, 16);
    white_pawn = std::stoul("2659", nullptr, 16);

    black_king = std::stoul("265A", nullptr, 16);
    black_queen = std::stoul("265B", nullptr, 16);
    black_rook = std::stoul("265C", nullptr, 16);
    black_bishop = std::stoul("265D", nullptr, 16);
    black_knight = std::stoul("265E", nullptr, 16);
    black_pawn = std::stoul("265F", nullptr, 16);
  }
};