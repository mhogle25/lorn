#include "core/lorn.h"

Lorn::Lorn() {
	game = nullptr;

	actions = new std::map<std::string, std::function<Action>>();
	//Begin giving keys to the actions
	(*actions)["new"] = [this](std::vector<std::string>* s) {
		newGame(s);
	}
}
	

Lorn::~Lorn() {
	if (game != nullptr) {
		delete game;
	}

	delete actions;
}

int Lorn::begin() {
	return 0;
}

int Lorn::newGame(std::vector<std::string>* s) {
	if (s != nullptr) {
	}
	return 0;
}

int Lorn::loadGame(std::vector<std::string>* s) {
	if (s != nullptr) {
	}
	return 0;
}
