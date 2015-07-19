#include <string>

#define ALPHABET_SIZE 26

using namespace std;


class TrieNode {
public:
    char key;
    int value;
    TrieNode **children;

    TrieNode() {
        children = new TrieNode *[ALPHABET_SIZE];
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie();

    ~Trie();

    void addNode(const string key, int value);

    bool isNode(const string key);

    int getNode(const string key);
};
