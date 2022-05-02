#include <SFML/Graphics.hpp>
#include <cmath>

#include "board.h"
#include "pieces.h"

board::board(sf::Vector2u windowSize) : windowSize(windowSize) {
  init_();
}

board::board(sf::Event &event) {
  windowSize = {event.size.width, event.size.height};
  init_();
}

void board::render_board() {

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {

      render_square(i, j);

      render_algebraic_notation(i, j);

      render_piece(i, j);
    }
  }
}
void board::render_square(int i, int j) {
  sf::RectangleShape currSquare({square_size, square_size});
  currSquare.setFillColor((i + j) % 2 == 0 ? white_square_color : black_square_color);
  currSquare.setPosition(x_offset + static_cast<float>(j) * square_size, (static_cast<float>(i) * square_size));

  render_texture.draw(currSquare);
  render_texture.display();
}
void board::render_piece(int i, int j) {

  /**
   * Feed `get_algebraic_notation(i, j)` into the map called `board_state` to get the piece for the square. But, first,
   * add all of the `text.blah` crap to pieces so pieces can actually make the pieces
   */

  pieces p;
  sf::Text text(p.bishop, free_sarif_font, std::floor(square_size));
  text.setFillColor(p.white_piece_color);
  text.setOutlineColor(sf::Color(0, 0, 0));
  text.setOutlineThickness(1);
  text.setPosition(square_size / 8.f + x_offset + static_cast<float>(j) * square_size,
                   -square_size / 8.f + (static_cast<float>(i) * square_size));

  render_texture.draw(text);
  render_texture.display();
}

void board::render_algebraic_notation(int i, int j) {

  if (i == 7) {
    sf::Text text(alg_notation_letter_map.at(j), open_sans_font, std::floor(square_size / 5.8f));
    auto letter_color = j % 2 == 0 ? white_square_color : black_square_color;
    text.setFillColor(letter_color);
    text.setPosition(square_size / 1.2f + x_offset + static_cast<float>(j) * square_size,
                     square_size / 1.3f + static_cast<float>(i) * square_size);

    render_texture.draw(text);
    render_texture.display();
  }

  if (j == 0) {
    sf::Text text(std::to_string(alg_notation_number_map.at(i)), open_sans_font, std::floor(square_size / 5.8f));
    auto letter_color = i % 2 == 1 ? sf::Color(254, 232, 209) : sf::Color(83, 120, 99);
    text.setFillColor(letter_color);
    text.setPosition(square_size / 18.f + x_offset + static_cast<float>(j) * square_size,
                     square_size / 25.f + static_cast<float>(i) * square_size);

    render_texture.draw(text);
    render_texture.display();
  }

}

void board::drawBoard(sf::RenderWindow &render_window) const {
  render_window.draw(sf::Sprite(render_texture.getTexture()));
}

std::string board::get_algebraic_notation(int i, int j) {
  return column_index_to_alg_notation_letter.at(j) + row_index_to_alg_notation_num.at(i);
}

void board::init_() {

  /**
   * There is a bug here. To see the bug, resize the window starting at any size --super big or super small is fine-- and
   * then resize only in the "making it narrower" direction. You'll see that when you get to a width less than the width of the
   * board, the board disappears.
   *
   * NOTE THAT THIS DOES **NOT** HAPPEN WHEN YOU DO THE SAME THING BY MAKING THE BOARD SHORTER IN THE VERTICAL DIRECTION!!!
   *
   */

  x_offset = static_cast<float>(windowSize.x - windowSize.y) / 2.f;
  square_size = static_cast<float>(windowSize.y) / 8.f;
  render_texture.create(windowSize.x, windowSize.y);
  set_free_sarif_font();
  set_open_sans_font();
  set_alg_notation_letter_map();
  set_alg_notation_number_map();
  set_initial_board_state();
  set_indices_to_alg_notation();
}

/**
 * Methods called by `init_()` appear below
 */

void board::set_free_sarif_font() {
  if (!free_sarif_font.loadFromFile("font/FreeSerif-4aeK.ttf")) {
    // error...
  };
}

void board::set_open_sans_font() {
  if (!open_sans_font.loadFromFile("font/OpenSans-ExtraBold.ttf")) {
    // error...
  }
}

void board::set_alg_notation_letter_map() {
  alg_notation_letter_map = {{0, "a"}, {1, "b"}, {2, "c"}, {3, "d"}, {4, "e"}, {5, "f"}, {6, "g"}, {7, "h"}};
}

void board::set_alg_notation_number_map() {
  alg_notation_number_map = {{0, 8}, {1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 3}, {6, 2}, {7, 1}};
}

void board::set_initial_board_state() {
  board_state = {
      {"a1", "white_rook"},
      {"b1", "white_knight"},
      {"c1", "white_bishop"},
      {"d1", "white_queen"},
      {"e1", "white_king"},
      {"f1", "white_bishop"},
      {"g1", "white_knight"},
      {"h1", "white_rook"},

      {"a2", "white_pawn"},
      {"b2", "white_pawn"},
      {"c2", "white_pawn"},
      {"d2", "white_pawn"},
      {"e2", "white_pawn"},
      {"f2", "white_pawn"},
      {"g2", "white_pawn"},
      {"h2", "white_pawn"},

      {"a3", ""},
      {"b3", ""},
      {"c3", ""},
      {"d3", ""},
      {"e3", ""},
      {"f3", ""},
      {"g3", ""},
      {"h3", ""},

      {"a4", ""},
      {"b4", ""},
      {"c4", ""},
      {"d4", ""},
      {"e4", ""},
      {"f4", ""},
      {"g4", ""},
      {"h4", ""},

      {"a5", ""},
      {"b5", ""},
      {"c5", ""},
      {"d5", ""},
      {"e5", ""},
      {"f5", ""},
      {"g5", ""},
      {"h5", ""},

      {"a6", ""},
      {"b6", ""},
      {"c6", ""},
      {"d6", ""},
      {"e6", ""},
      {"f6", ""},
      {"g6", ""},
      {"h6", ""},

      {"a7", "black_pawn"},
      {"b7", "black_pawn"},
      {"c7", "black_pawn"},
      {"d7", "black_pawn"},
      {"e7", "black_pawn"},
      {"f7", "black_pawn"},
      {"g7", "black_pawn"},
      {"h7", "black_pawn"},

      {"a8", "black_rook"},
      {"b8", "black_knight"},
      {"c8", "black_bishop"},
      {"d8", "black_queen"},
      {"e8", "black_king"},
      {"f8", "black_bishop"},
      {"g8", "black_knight"},
      {"h8", "black_rook"}

  };
}

void board::set_indices_to_alg_notation() {
  row_index_to_alg_notation_num = {
      {0, "8"},
      {1, "7"},
      {2, "6"},
      {3, "5"},
      {4, "4"},
      {5, "3"},
      {6, "2"},
      {7, "1"}
  };
  column_index_to_alg_notation_letter = {
      {0, "a"},
      {1, "b"},
      {2, "c"},
      {3, "d"},
      {4, "e"},
      {5, "f"},
      {6, "g"},
      {7, "h"}
  };
}