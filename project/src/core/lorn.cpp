#include "core/lorn.h"

Lorn::Lorn() {
	newGameAction = [this](std::vector<std::string>* s, int index) {
		if (s == NULL) {
			std::cout << "Enter a name for this save file\n";
			return input.runArgs(index + 1);
		}

		if (s->size() == 0) {
			std::cout << "Enter a name for this save file\n";
			return input.runArgs(index + 1);
		}

		if (s->size() == 1) {
			if (thesaurus.synonymCheck(s->at(0), s_game) and index == 0) {
				std::cout << "Enter a name for this save file\n";
				return input.runArgs(index + 1);
			}

			game = std::make_unique<Game>(&input, s->at(0));
			return 0;
		}

		if (s->size() > 1) {
			std::string newName = "";
			long unsigned int i = 0;
			if (thesaurus.synonymCheck(s->at(0), s_game)) {
				i = 1;
			}
			for ( ; i < s->size(); i++) {
				newName += s->at(i);
				if (i != s->size() - 1) {
					newName += " ";
				}
			}
			game = std::make_unique<Game>(&input, newName);
			return 0;
		}

		return 0;
	};

	loadGameAction = [this](std::vector<std::string>* s, int index) {
		std::cout << s->size() << "\n";
		return index;
	};
	
	helpAction = [this](std::vector<std::string>* s, int index) {
		s->back();
		std::fstream file;
		file.open(helpPath, std::fstream::in);
		if (!file.is_open()) {
			std::cout << "Could not open help file\n";
			return 1;
		}
		
		while (!file.eof()) {
			std::string line;
			std::getline(file, line);
			std::cout << line << "\n";
		}

		file.close();
		return index;
	};

	thesaurus.createEntry(s_new, &newGameAction);
	thesaurus.createEntry(s_load, &loadGameAction);
	thesaurus.createEntry(s_help, &helpAction);
	thesaurus.createEntry(s_game);
}

Lorn::~Lorn() {

}

int Lorn::begin() {
	//Begin receiving input from the player
	thesaurus.print();
	input.setup(&thesaurus);
	return input.run();
}

