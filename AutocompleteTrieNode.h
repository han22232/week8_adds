#ifndef AUTOCOMPLETETRIENODE_H
#define AUTOCOMPLETETRIENODE_H
#include <string>


#include <vector>

class AutocompleteTrieNode {
public:
    bool isWord;
    std::vector<AutocompleteTrieNode*> children;

    AutocompleteTrieNode(){

    isWord = false;
    children = std::vector<AutocompleteTrieNode*>(26, nullptr);
    }
};

#endif // AUTOCOMPLETETRIENODE_H
