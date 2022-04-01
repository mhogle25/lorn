#ifndef LORN
#define LORN

#include<vector>

#include "core/game.h"
#include "core/input.h"
#include "core/types.h"
#include "core/thesaurus.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <functional>
#include <memory>
#include <bits/stdc++.h>

class Lorn {
	public:
		Lorn();
		~Lorn();
		int begin();
	private:
		std::unique_ptr<Game> game;
		Thesaurus thesaurus;
		const char* helpPath = "data/help";

		const char* s_new = "new";
		const char* s_load = "load";
		const char* s_help = "help";
		const char* s_game = "game";

		std::function<types::ACTION> newGameAction;
		std::function<types::ACTION> loadGameAction;
		std::function<types::ACTION> helpAction;

		Input input;
};

#endif
