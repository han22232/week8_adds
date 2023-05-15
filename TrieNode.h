#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>

struct TrieNode
{
    std::unordered_map<char, TrieNode *> children;
    int routerNumber;

    TrieNode() : routerNumber(-1) {}
    bool isWord;
    std::vector<TrieNode *> children;

    TrieNode()
    {
        bool isWord;
        std::vector<TrieNode *> children;

        TrieNode()
        {
            isWord = false;
            children = std::vector<TrieNode *>(26, nullptr);
        }
    }
};

#endif
