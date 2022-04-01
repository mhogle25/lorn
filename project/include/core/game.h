#ifndef GAME
#define GAME

#include "core/input.h"
#include <string>

class Game {
	public:
		Game(Input*, const std::string&);
		~Game();
		int startNew();	
	private:
		Input* input;
		std::string name;
};

#endif
