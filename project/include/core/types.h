#ifndef TYPES
#define TYPES

#include<vector>
#include<string>
#include<unordered_map>
#include<functional>
#include <memory>
#include <bits/stdc++.h>

namespace types {
    struct ACTION_MAP_VALUE;

    typedef int ACTION (std::vector<std::string>*, int);
    typedef std::unordered_map<std::string, ACTION_MAP_VALUE> ACTION_MAP;
    typedef std::pair<std::string, ACTION_MAP_VALUE> ACTION_PAIR;
    
    struct ACTION_MAP_VALUE {
        std::function<types::ACTION>* action;
        std::shared_ptr<std::unordered_set<std::string>> synonyms;

        bool containsAction() {
            return action != nullptr;
        }
    };

}

#endif
