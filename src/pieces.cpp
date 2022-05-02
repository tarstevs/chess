#include <SFML/Graphics.hpp>
#include <cmath>

#include "pieces.h"

pieces::pieces() {
  init_();
}

sf::Text pieces::get_positioned_sfml_text_graphic_for_piece(const std::string &piece_for_square,
                                                            float square_size,
                                                            float x_offset,
                                                            int i,
                                                            int j) {
  sf::Color piece_color;
  if (piece_for_square.find("white") != std::string::npos) {
    piece_color = white_piece_color;
  } else {
    piece_color = black_piece_color;
  };
  size_t index_of_first_piece_letter = piece_for_square.find('_') + 1;
  std::string piece_name = piece_for_square.substr(index_of_first_piece_letter, piece_for_square.size());
  sf::Text text(get_char32_piece_code(piece_name), free_sarif_font, std::floor(square_size));
  text.setFillColor(piece_color);
  text.setOutlineColor(sf::Color(0, 0, 0));
  text.setOutlineThickness(1);
  text.setPosition(square_size / 8.f + x_offset + static_cast<float>(j) * square_size,
                   -square_size / 8.f + (static_cast<float>(i) * square_size));
  return text;
}

char32_t pieces::get_char32_piece_code(const std::string &piece_name) const {
  if (piece_name == "king")
    return king;
  if (piece_name == "queen")
    return queen;
  if (piece_name == "rook")
    return rook;
  if (piece_name == "bishop")
    return bishop;
  if (piece_name == "knight")
    return knight;
  if (piece_name == "pawn")
    return pawn;
}

void pieces::init_() {

  set_free_sarif_font();

  king = std::stoul("265A", nullptr, 16);
  queen = std::stoul("265B", nullptr, 16);
  rook = std::stoul("265C", nullptr, 16);
  bishop = std::stoul("265D", nullptr, 16);
  knight = std::stoul("265E", nullptr, 16);
  pawn = std::stoul("265F", nullptr, 16);
}

/**
 * Methods called by `init_()` appear below
 */

void pieces::set_free_sarif_font() {
  if (!free_sarif_font.loadFromFile("font/FreeSerif-4aeK.ttf")) {
    // error...
  };
}