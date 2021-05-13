#ifndef LORN
#define LORN

#include<vector>

#include "core/game.h"
#include "core/types.h"
#include<vector>
#include<string>
#include<map>
#include<functional>

class Lorn {
	public:
		Lorn();
		~Lorn();
		int begin();
	private:
		Game* game;
		std::map<std::string, std::function<Action>>* actions;

		int newGame(std::vector<std::string>*);
		int loadGame(std::vector<std::string>*);
};

#endif
