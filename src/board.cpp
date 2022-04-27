#include <SFML/Graphics.hpp>

#include "board.h"

void board::createBoard(sf::Vector2u windowSize)
{
    const float xOffset = static_cast<float>(windowSize.x - windowSize.y) / 2.f;
    const float squareSize = static_cast<float>(windowSize.y) / 8.f;

    board.create(windowSize.x, windowSize.y);
    board.clear(backColor);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sf::RectangleShape currSquare({ squareSize, squareSize });
            currSquare.setFillColor((i + j) % 2 ? lightColor : darkColor);
            currSquare.setPosition(xOffset + static_cast<float>(i) * squareSize, (static_cast<float>(j) * squareSize));
            board.draw(currSquare);
        }
    }
}

void board::drawBoard(sf::RenderWindow& window) const
{
    window.draw(sf::Sprite(board.getTexture()));
}
