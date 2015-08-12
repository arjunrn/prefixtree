#include "prefix.h"
#include <string>

using namespace std;

Trie::Trie()
{
    TrieNode *root = new TrieNode();
    this->root = root;
}

Trie::~Trie()
{
    delete root;
}

void Trie::addKeyValue(const unsigned int key, int value)
{
    //we assume that the keys have the same number of digits, 4 for now

    unsigned int bits = key;
    TrieNode *n = this->root;
    for(int i=0; i < 4 ; i++) {
        unsigned int key = bits & 0xF;
        if(n->children[(int)key].pointer == nullptr) {
            TrieNode *newNode = new TrieNode();
            n->children[(int)key].pointer = newNode;
        }
        bits = bits >> 4;
        n = n->children[(int)key].pointer;
    }

    n->value = value;
}

bool Trie::isNode(const unsigned int key)
{
    /*bool found = true;
    TrieNode *n = this->root;
    for (int i = 0; i < key.length(); i++) {
        char curr = key[i];
        int index = curr - 'a';
        if (n->children[index] == nullptr) {
            found = false;
            break;
        }
        else {
            n = n->children[index];
        }
    }*/
    //return found;
    return true;
}

int Trie::getNode(const unsigned int key)
{
    unsigned int bits = key;
    TrieNode *n = this->root;
    for(int i=0; i < 4; i++) {
        unsigned int key = bits & 0xF;
        if(n->children[(int)key].pointer == nullptr) {
            return -1;
        }
        bits = bits >> 4;
        n = n->children[(int)key].pointer;
    }
    return n->value;
}
