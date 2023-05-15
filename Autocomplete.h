
#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>
#include "TrieNode.h"

class Autocomplete {
private:
    TrieNode* root;

public:
    Autocomplete();

    void insert(std::string word);
    void dfs(TrieNode* node, std::string partialWord, std::vector<std::string>& suggestions);
    std::vector<std::string> getSuggestions(std::string partialWord);
};

#endif // AUTOCOMPLETE_H
