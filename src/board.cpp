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

  const float x_offset = static_cast<float>(windowSize.x - windowSize.y) / 2.f;
  const float square_size = static_cast<float>(windowSize.y) / 8.f;

  render_texture.create(windowSize.x, windowSize.y);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {

      render_square(x_offset, square_size, i, j);

      render_piece(x_offset, square_size, i, j);

      render_algebraic_notation(i, j, x_offset, square_size);
    }
  }
}
void board::render_square(const float x_offset, const float square_size, int i, int j) {
  sf::RectangleShape currSquare({square_size, square_size});
  currSquare.setFillColor((i + j) % 2 == 0 ? white_square : black_square);
  currSquare.setPosition(x_offset + static_cast<float>(j) * square_size, (static_cast<float>(i) * square_size));

  render_texture.draw(currSquare);
  render_texture.display();
}
void board::render_piece(const float x_offset, const float square_size, int i, int j) {
  pieces p;
  sf::Text text(p.black_king, free_sarif_font, std::floor(square_size));
  text.setFillColor(sf::Color::Black);
  text.setPosition(square_size / 8.f + x_offset + static_cast<float>(j) * square_size,
                   -square_size / 8.f + (static_cast<float>(i) * square_size));

  render_texture.draw(text);
  render_texture.display();
}

void board::render_algebraic_notation(int i, int j, float x_offset, float square_size) {

  if (i == 7) {
    sf::Text text(alg_notation_letter_map.at(j), open_sans_font, std::floor(square_size / 3.f));
    auto letter_color = j % 2 == 0 ? sf::Color(254, 232, 209) : sf::Color(83, 120, 99);
    text.setFillColor(letter_color);
    text.setPosition(square_size / 1.35f + x_offset + static_cast<float>(j) * square_size,
                     square_size / 1.7f + static_cast<float>(i) * square_size);

    render_texture.draw(text);
    render_texture.display();
  }

  if (j == 0) {
    sf::Text text(std::to_string(alg_notation_number_map.at(i)), open_sans_font, std::floor(square_size / 3.f));
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

void board::init_() {
  set_free_sarif_font();
  set_open_sans_font();
  set_alg_notation_letter_map();
  set_alg_notation_number_map();
}

void board::set_free_sarif_font() {
  if (!free_sarif_font.loadFromFile("font/FreeSerif-4aeK.ttf")) {
  };
}

void board::set_open_sans_font() {
  if (!open_sans_font.loadFromFile("font/OpenSans-Regular.ttf")) {
    // error...
  }
}

void board::set_alg_notation_letter_map() {
  alg_notation_letter_map = {{0, "a"}, {1, "b"}, {2, "c"}, {3, "d"}, {4, "e"}, {5, "f"}, {6, "g"}, {7, "h"}};
}

void board::set_alg_notation_number_map() {
  alg_notation_number_map = {{0, 8}, {1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 3}, {6, 2}, {7, 1}};
}