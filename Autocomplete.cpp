#include "Autocomplete.h"

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

Autocomplete::~Autocomplete() {
    deleteTrie(root);
}

void Autocomplete::insert(string word) {
    TrieNode* curr = root;
    for (char c : word) {
        if (curr->children.count(c) == 0) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
        curr->completions.push_back(word);
    }
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
    TrieNode* curr = root;
    for (char c : partialWord) {
        if (curr->children.count(c) == 0) {
            return {};
        }
        curr = curr->children[c];
    }
    return curr->completions;
}

void Autocomplete::deleteTrie(TrieNode* node) {
    for (auto &it : node->children) {
        deleteTrie(it.second);
    }
    delete node;
}
