#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include "TrieNode.h"

class PrefixMatcher {
private:
    TrieNode* root;

public:
    PrefixMatcher();

    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);
};

#endif

