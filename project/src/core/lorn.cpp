#include "core/lorn.h"

Lorn::Lorn() {
	/*
	auto act = [](std::vector<std::string> s) {
		std::cout << "hello\n";
		return 0;
	};

	auto lambda = [](int value) { 
		std::cout << "value: " << value << "\n";

	};

	int(*action)(std::vector<std::string>*) = [](std::vector<std::string>* s) {
		std::cout << "hello\n";
		return 0;
	};

	std::function<int(std::vector<std::string>*)> f = [](std::vector<std::string>* s) {
		std::cout << "hello\n";
		return 0;
	};

	std::function<Action> f2 = [](std::vector<std::string>* s) {
		std::cout << "hello\n";
		return 0;
	};

	actions.insert(std::pair<std::string, std::function<Action>> ("new", f2));
	*/

	actions.insert(std::pair<std::string, std::function<Action>> ("new", [this](std::vector<std::string>* s) {
		return newGame(s);
	}));
}
	

Lorn::~Lorn() {
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
