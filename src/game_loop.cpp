#include "../include/game_loop.h"
#include "../include/board.h"

#include <SFML/Graphics.hpp>

game_loop::game_loop() = default;


void game_loop::run()
{

	int resX = 1000;
	int resY = 1000;
	sf::RenderWindow window(sf::VideoMode(resX, resY), "Chess");

	sf::Event event;
	sf::View view = window.getDefaultView();

	board board;
	board.createBoard(window.getSize());

	// Game loop (runs the program as long as the window is open).
	while (window.isOpen())
	{
		// Check all the window's events that were triggered since the last iteration of the loop.
		sf::Event event;
		// The pollEvent function returns true if an event was pending, or false if there was none.
		// Note that we use a while loop for our event loop so that all pending events are processed,
		// in case there were several.
		// Event loop
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::Resized) {
				float w = static_cast<float>(event.size.width);
				float h = static_cast<float>(event.size.height);
				view.setSize({w, h});
				view.setCenter({w/2.f, h/2.f});
                		window.setView(view);
                		board.createBoard({ event.size.width, event.size.height });
			}

		}
		window.clear();
		board.drawBoard(window);
		window.display();
	}
}
