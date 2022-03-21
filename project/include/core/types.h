#ifndef TYPES
#define TYPES

#include<vector>
#include<string>

namespace types {
    typedef std::vector<std::string>* ACTION_ARGS;
    typedef int ACTION (ACTION_ARGS);
}

#endif
