#include "core/input.h"

Input::Input() {
    thesaurus = NULL;
}

Input::Input(Thesaurus* thesaurus) {
    setup(thesaurus);
}

void Input::setup(Thesaurus* thesaurus) {
    this->thesaurus = thesaurus;
}

void Input::getAction() {
    std::cout << "> ";

    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    ss >> action;

    std::string arg;
    while (ss >> arg) {
        args.push_back(arg);
    }
}

void Input::getArgs() {
    std::cout << "> ";

    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string arg;
    while (ss >> arg) {
        args.push_back(arg);
    }
}

int Input::run() {
    int result;
    while (true) {
        action = "";
        args.clear();
        getAction(); 
        result = handleAction(0);
        if (result < 0) {
            break;
        }
    }
    return result;
}

int Input::runArgs(int index) {
    int result = 0;
    args.clear();
    getArgs();
    result = handleAction(index);
    return result;
}

int Input:: handleAction(int index) {
    if (thesaurus->contains(action)) {
        if (thesaurus->containsAction(action)) {
            return thesaurus->callAction(action, &args, index);
        }else {
            std::cout << "Action used improperly\n";
            return 0;
        }
    } else {
        std::cout << "Unknown action: " << action << "\n";
        return 0;
    }
    
}

