#include "PrefixMatcher.h"

#include <iostream>
#include <unordered_map>

TrieNode::TrieNode() {
    routerNumber = -1;
}

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    TrieNode* curr = root;
    for (char c : address) {
        if (curr->children.find(c) == curr->children.end()) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
    }
    curr->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
    TrieNode* curr = root;
    int longestMatchingPrefix = -1;
    int selectedRouter = -1;

    for (char c : networkAddress) {
        if (curr->children.find(c) == curr->children.end()) {
            break;
        }
        curr = curr->children[c];
        if (curr->routerNumber != -1) {
            longestMatchingPrefix++;
            selectedRouter = curr->routerNumber;
        }
    }

    return selectedRouter;
}
