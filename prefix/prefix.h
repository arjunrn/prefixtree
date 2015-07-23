#include <string>

#define ALPHABET_SIZE 10

using namespace std;

class Pointer{
    TrieNode* pointer;
    int parity;

};

class TrieNode {
public:
    //char key;
    int value;
    //TrieNode **children;
    Pointer children[ALPHABET_SIZE];

    TrieNode() {
        //children = new TrieNode *[ALPHABET_SIZE];
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i].pointer = nullptr;
            children[i].parity=0;
        }
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie();

    ~Trie();

    //void addNode(const string key, int value);
    void addKeyValue(const int key,int value);
    //void buildTrie();

    bool isNode(const string key);

    int getNode(const string key);
};
