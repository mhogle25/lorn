#include "core/lorn.h"

Lorn::Lorn() {
	/*
	auto act = [this](std::vector<std::string> s) {
		return newGame(s);
	};

	auto lambda = [this](int value) { 
		std::cout << "value: " << value << "\n";
	};

	int(*action)(std::vector<std::string>*) = [this](std::vector<std::string>* s) {
		return newGame(s);
	};

	std::function<int(std::vector<std::string>*)> f = [this](std::vector<std::string>* s) {
		return newGame(s);
	};

	std::function<Action> f2 = [this](std::vector<std::string>* s) {
		return newGame(s);
	};

	actions.insert(std::pair<std::string, std::function<Action>> ("new", f2));
	
	actions.insert(std::pair<std::string, std::function<Action>> ("new", [this](std::vector<std::string>* s) {
		return newGame(s);
	}));
	*/

	newGame = [this](types::ACTION_ARGS s) {
		return 0;
	};

	actions.insert(std::pair<std::string, std::function<types::ACTION>*>{ commands::NEW, &newGame });
}

Lorn::~Lorn() {

}

int Lorn::begin() {
	return 0;
}
