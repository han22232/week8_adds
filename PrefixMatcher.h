#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <map>
#include <string>

class TrieNode {
public:
    int routerNumber;
    std::map<char, TrieNode*> children;
    TrieNode() : routerNumber(-1) {}
};

class PrefixMatcher {
private:
    TrieNode* root;

public:
    PrefixMatcher();
    ~PrefixMatcher();
    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);
    void deleteTrie(TrieNode* node); 
};

#endif  // PREFIXMATCHER_H
