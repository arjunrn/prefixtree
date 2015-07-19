#include "prefix.h"
#include <string>

using namespace std;

Trie::Trie() {
    TrieNode *root = new TrieNode();
    root->key = '$';
    this->root = root;
}

Trie::~Trie() {
    delete root;
}

void Trie::addNode(const string key, int value) {
    TrieNode *n = this->root;
    for (int i = 0; i < key.length(); i++) {
        char curr = key[i];
        int index = curr - 'a';
        if (n->children[index] == nullptr) {
            TrieNode *newNode = new TrieNode();
            newNode->key = curr;
            n->children[index] = newNode;
        }
        n = n->children[index];
    }

    n->value = value;
}

bool Trie::isNode(const string key) {
    bool found = true;
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
    }
    return found;
}

int Trie::getNode(const string key) {
    bool flag = true;
    TrieNode *node = this->root;
    for (int i = 0; i < key.length(); i++) {
        char curr = key[i];
        int index = curr - 'a';
        if (node->children + index == nullptr) {
            flag = false;
            break;
        }
        node = node->children[index];
    }
    if (flag) {
        return node->value;
    }
    else {
        return -1;
    }
}
