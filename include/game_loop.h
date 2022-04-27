#ifndef _HELLO_H_
#define _HELLO_H_

#include <SFML/Graphics.hpp>

class game_loop
{
public:
	game_loop();
	void run();
private:
	sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight);
};

#endif // _HELLO_H_
