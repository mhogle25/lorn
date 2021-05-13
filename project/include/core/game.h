#ifndef GAME
#define GAME

#include "core/input.h"

class Game {
	public:
		Game();
		~Game();
		int startNew();	
	private:
		Input* input;

};

#endif
