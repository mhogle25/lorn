#ifndef LORN
#define LORN

#include<vector>

#include "core/game.h"
#include "core/types.h"
#include "core/commands.h"
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
#include<functional>

class Lorn {
	public:
		Lorn();
		~Lorn();
		int begin();
	private:
		Game game;
		std::map<std::string, std::function<types::ACTION>*> actions;

		std::function<types::ACTION> newGame;
		std::function<types::ACTION> loadGame;
};

#endif
