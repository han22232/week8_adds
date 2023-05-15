#include <iostream>
#include <unordered_map>
#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include<map>
#include<string>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int routerNumber;

    TrieNode();
};

class PrefixMatcher : public TrieNode {
private:
    TrieNode* root;

public:
    PrefixMatcher();

    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);
};
#endif