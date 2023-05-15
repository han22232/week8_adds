#include <map>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    vector<string> completions;
};

class Autocomplete {
private:
    TrieNode* root;

public:
    Autocomplete();
    ~Autocomplete();
    void insert(string word);
    vector<string> getSuggestions(string partialWord);
    void deleteTrie(TrieNode* node); 
};

#endif  
