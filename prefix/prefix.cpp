#include "prefix.h"
#include <string>

using namespace std;

Trie::Trie() {
    //we will build the trie here
    TrieNode *root = new TrieNode();
    //root->key = '$';
    this->root = root;
    //we should not build the whole tree at once, in the addKeyValue function, in case we need a node, we have to create it
    /*for(int i=0;i<26;i++)
    {
        if(i==0)
        {
            for(int j=0;j<26;j++)
            {
                TrieNode *node=new TrieNode();
                root->children[j].n=node;
            }
        }


    }*/

}

Trie::~Trie() {
    delete root;
}

void Trie::addKeyValue(const int key, int value) {// in case we need a node, i think we have to create it here
    //we assume that the keys have the same number of digits, 4 for now
    int temp;
    this->first = key / 1000;
    temp = key % 1000;
    this->second = temp / 100;
    temp = temp % 100;
    this->fourth = temp % 10;
    this->thrid = temp/10;
    TrieNode *n = this->root;
   // for (int i = 0; i < key.length(); i++) {
   // for (int i = 0; i < 4; i++) {
        /*if(n->children[first].pointer==nullptr)
        {
            TrieNode *newNode=new TrieNode();
            n->children[first].pointer=newNode;
            TrieNode *newNode1=new TrieNode();
            newNode->children[second].pointer=newNode1;
            TrieNode *newNode2=new TrieNode();
            newNode1->children[third].pointer=newNode2;
            TrieNode *newNode3=new TrieNode();
            newNode2->children[fourth].pointer=newNode3;
            newNode3->value=value;

        }*/

        //char curr = key[i];
        //int index = curr - 'a';
    if (n->children[first] == nullptr) {
        TrieNode *newNode = new TrieNode();
        //newNode->key = curr;
        n->children[first] = newNode;
    }
        n = n->children[first];

    if (n->children[second] == nullptr) {
        TrieNode *newNode = new TrieNode();
        //newNode->key = curr;
        n->children[second] = newNode;
    }
    n = n->children[second];

    if (n->children[third] == nullptr) {
        TrieNode *newNode = new TrieNode();
        //newNode->key = curr;
        n->children[third] = newNode;
    }
    n = n->children[third];

    if (n->children[fourth] == nullptr) {
        TrieNode *newNode = new TrieNode();
        //newNode->key = curr;
        n->children[fourth] = newNode;
    }
    n = n->children[fourth];

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

int Trie::getNode(const int key) {
    key/1000=first;
    key%1000=temp;
    temp/100=second;
    temp%100=temp;
    temp%10=fourth;
    temp/10=third;
    bool flag = true;
    TrieNode *node = this->root;
    if(node->children[first].pointer== nullptr)
        flag=false;
    else
    {
        node=node->children[first];
        if(node->children[second].pointer==nullptr)
            flag=false;
        else
        {
            node=node->children[second];
            if(node->children[third].pointer==nullptr)
                flag=false;
            else
            {
                node=node->children[third];
                if(node->children[fourth].pointer==nullptr)
                    flag=false;
                else
                {
                    node=node->children[fourth];
                }
            }
        }
    }




   /* for (int i = 0; i < key.length(); i++) {
        char curr = key[i];
        int index = curr - 'a';
        if (node->children + index == nullptr) {
            flag = false;
            break;
        }
        node = node->children[index];
    }*/


    if (flag) {
        return node->value;
    }
    else {
        return -1;
    }
}
