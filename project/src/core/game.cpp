#include "core/game.h"

Game::Game(Input* input, const std::string& name) {
	this->input = input;
	this->name = name;
	std::cout << "Game created with name: " << name << std::endl;
}

Game::~Game() {

}

int Game::startNew() {
	return 0;
}
