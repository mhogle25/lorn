#include "core/thesaurus.h"

int Thesaurus::createEntry(const std::string& parentWord, std::function<types::ACTION>* action) {
    std::shared_ptr<std::unordered_set<std::string>> synonyms = std::make_shared<std::unordered_set<std::string>>();

    if (!addEntry(parentWord, action, synonyms)) {
        std::cout << "[Thesaurus] Duplicate entry detected for word " << parentWord << "\n";
    }

    std::ifstream synonymsFile;
    synonymsFile.open(synonymsPath + parentWord, std::ios::in);

    if (!synonymsFile.is_open()) {
        std::cout << "[Thesaurus] Failed to open synonyms file for word " << parentWord << "\n";
        return -1;
    }

    std::string word;
    while (synonymsFile >> word) {
        if (parentWord.size() < 1) {
            continue;
        }

        if (!addEntry(word, action, synonyms)) {
            std::cout << "[Thesaurus] Duplicate entry detected for word " << word << "\n";
        }
    }
    synonymsFile.close();
    return 0;
}

int Thesaurus::createEntry(const std::string& parentWord) {
    return createEntry(parentWord, nullptr);
}

bool Thesaurus::contains(const std::string& word) {
    return synonym_action_map.find(word) != synonym_action_map.end();
}

bool Thesaurus::containsAction(const std::string& word) {
    if (contains(word)) {
        return synonym_action_map[word].containsAction();
    }
    return false;
}

int Thesaurus::callAction(const std::string& key, std::vector<std::string>* args, int index) {
    if (!contains(key)) {
        std::cout << "[Thesaurus] No action found for word " << key << "\n";
        return 1;
    }

    if (!synonym_action_map[key].containsAction()) {
        std::cout << "[Thesaurus] No action found for word " << key << "\n";
        return 1;
    }

    std::function<types::ACTION>* f = synonym_action_map[key].action;
    return (*f)(args, index);
}

bool Thesaurus::synonymCheck(const std::string& word1, const std::string& word2) {
    if (word1 == word2) {
        return true;
    }

    if (!contains(word1)) {
        return false;
    }

    return synonym_action_map[word1].synonyms->find(word2) != synonym_action_map[word1].synonyms->end();
}

void Thesaurus::print() {
    std::cout << "Full Thesaurus: \n"
    << "----------------\n";
    for (auto it = synonym_action_map.begin(); it != synonym_action_map.end(); it++) {
        std::cout << it->first << ": {\n    actions:" << it->second.action << "\n    synonyms: [\n";
        for (auto it2 = it->second.synonyms->begin(); it2 != it->second.synonyms->end(); it2++) {
            std::cout << "        " << *it2 << ",\n";
        }
        std::cout << "    ]\n},\n";
    }
    std::cout << "----------------\n";
}

bool Thesaurus::addEntry(const std::string& word, std::function<types::ACTION>* action, std::shared_ptr<std::unordered_set<std::string>> synonyms) {
    if (contains(word)) {
        return false;
    }

    synonyms->insert(word);

    synonym_action_map.insert(types::ACTION_PAIR {
        word, 
        types::ACTION_MAP_VALUE { 
            action, 
            synonyms 
        }
    });

    return true;
}