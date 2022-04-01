#ifndef THESAURUS
#define THESAURUS

#include "core/types.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <fstream>
#include <memory>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

class Thesaurus {
public:
    int createEntry(const std::string&, std::function<types::ACTION>*);
    int createEntry(const std::string&);
    int callAction(const std::string&, std::vector<std::string>*, int);
    bool synonymCheck(const std::string&, const std::string&);
    void print();
    bool contains(const std::string&);
    bool containsAction(const std::string&);
private:
	types::ACTION_MAP synonym_action_map;
    const char* synonymsPath = "data/synonyms/syn_";

    bool addEntry(const std::string&, std::function<types::ACTION>*, std::shared_ptr<std::unordered_set<std::string>>);
};

#endif