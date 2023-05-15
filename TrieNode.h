#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>

struct TrieNode
{
    std::unordered_map<char, TrieNode *> children;
    int routerNumber;

    TrieNode() : routerNumber(-1) {}

};

#endif
