#ifndef INPUT
#define INPUT

#include <unordered_map>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "core/types.h"
#include "core/thesaurus.h"

class Input {
	public:
		Input();
		Input(Thesaurus*);
		void setup(Thesaurus*);
		int run();
		int runArgs(int);

	private:
		std::string action;
		std::vector<std::string> args;

		Thesaurus* thesaurus;

		void getArgs();
		void getAction();
		int handleAction(int);
};

#endif
