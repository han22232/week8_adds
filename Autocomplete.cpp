#include "Autocomplete.h"



Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::insert(std::string word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (curr->children[index] == nullptr) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    curr->isWord = true;
}

void Autocomplete::dfs(TrieNode* node, std::string partialWord, std::vector<std::string>& suggestions) {
    if (node == nullptr) {
        return;
    }

    if (node->isWord) {
        suggestions.push_back(partialWord);
    }

    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        dfs(node->children[i], partialWord + c, suggestions);
    }
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    TrieNode* curr = root;
    std::vector<std::string> suggestions;

    for (char c : partialWord) {
        int index = c - 'a';
        if (curr->children[index] == nullptr) {
            return suggestions;
        }
        curr = curr->children[index];
    }

    dfs(curr, partialWord, suggestions);
    return suggestions;
}

