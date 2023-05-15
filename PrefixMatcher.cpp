#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

PrefixMatcher::~PrefixMatcher() {
    deleteTrie(root);
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    TrieNode* curr = root;
    for (char c : address) {
        if (curr->children.count(c) == 0) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
    }
    curr->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
    TrieNode* curr = root;
    int routerNumber = -1;
    for (char c : networkAddress) {
        if (curr->children.count(c) == 0) {
            break;
        }
        curr = curr->children[c];
        if (curr->routerNumber != -1) {
            routerNumber = curr->routerNumber;
        }
    }
    return routerNumber;
}

void PrefixMatcher::deleteTrie(TrieNode* node) {
    for (auto &it : node->children) {
        deleteTrie(it.second);
    }
    delete node;
}
