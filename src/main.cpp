#include "../include/game_loop.h"


#include <iostream>


namespace A::B {
	class blah {
	public:
		void foo() {
			std::cout << "blah" << std::endl;
		}
	};
}

int main()
{
	game_loop gl;
	gl.run();
	return 0;
}
