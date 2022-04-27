#ifndef _BOARD_H_
#define _BOARD_H_

#include <SFML/Graphics.hpp>

class board
{
public:
    void createBoard(sf::Vector2u windowSize);
    void drawBoard(sf::RenderWindow& window) const;

private:
    sf::RenderTexture board;
    sf::Color lightColor = sf::Color(159, 144, 176);
    sf::Color darkColor = sf::Color(125, 74, 141);
    sf::Color backColor = sf::Color(32, 31, 32);
};

#endif // _BOARD_H_
