#include <SFML/Graphics.hpp>

#include "board.h"
#include "pieces.h"

std::string get_letter(int j) {
  std::map<int, std::string> m_let{{0, "a"}, {1, "b"}, {2, "c"}, {3, "d"}, {4, "e"}, {5, "f"}, {6, "g"}, {7, "h"}};
  return m_let.at(j);
}

int get_number(int i) {
  std::map<int, int> m_num{{0, 8}, {1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 3}, {6, 2}, {7, 1}};
  return m_num.at(i);
}

void board::render_algebraic_notation(int i, int j, float x_offset, float square_size) {

  // start load font
  sf::Font font;
  if (!font.loadFromFile("font/OpenSans-Regular.ttf")) {
    // error...
  }
  // end load font

  pieces p;

  if (i == 7) {
    sf::Text text(get_letter(j), font, square_size / 3.f);
    auto letter_color = j % 2 == 0 ? sf::Color(254, 232, 209) : sf::Color(83, 120, 99);
    text.setFillColor(letter_color);
    text.setPosition(square_size / 1.35f + x_offset + static_cast<float>(j) * square_size,
                     square_size / 1.7f + static_cast<float>(i) * square_size);

    render_texture.draw(text);
    render_texture.display();
  }

  if (j == 0) {
    sf::Text text(std::to_string(get_number(i)), font, square_size / 3.f);
    auto letter_color = i % 2 == 1 ? sf::Color(254, 232, 209) : sf::Color(83, 120, 99);
    text.setFillColor(letter_color);
    text.setPosition(square_size / 18.f + x_offset + static_cast<float>(j) * square_size,
                     square_size / 25.f + static_cast<float>(i) * square_size);

    render_texture.draw(text);
    render_texture.display();
  }

}

void board::render_board(sf::Vector2u windowSize) {

  const float x_offset = static_cast<float>(windowSize.x - windowSize.y) / 2.f;
  const float square_size = static_cast<float>(windowSize.y) / 8.f;

  render_texture.create(windowSize.x, windowSize.y);
  render_texture.clear(window_background_color);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {

      sf::RectangleShape currSquare({square_size, square_size});
      currSquare.setFillColor((i + j) % 2 == 0 ? white_square : black_square);
      currSquare.setPosition(x_offset + static_cast<float>(j) * square_size, (static_cast<float>(i) * square_size));

      render_texture.draw(currSquare);
      render_texture.display();



      // start load font
      sf::Font font;
      if (!font.loadFromFile("font/FreeSerif-4aeK.ttf")) {
        // error...
      }
      // end load font

      pieces p;
      sf::Text text(p.black_king, font, square_size);
      text.setFillColor(sf::Color::Black);
      text.setPosition(square_size / 8.f + x_offset + static_cast<float>(j) * square_size,
                       -square_size / 8.f + (static_cast<float>(i) * square_size));

      render_texture.draw(text);
      render_texture.display();

      render_algebraic_notation(i, j, x_offset, square_size);
    }
  }
}

void board::drawBoard(sf::RenderWindow &render_window) const {
  render_window.draw(sf::Sprite(render_texture.getTexture()));
}
