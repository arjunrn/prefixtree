#include <string>

#define ALPHABET_SIZE 10

using namespace std;

//TODO: Make the pointer a generic class
/*template <class PointerObj> class Pointer{
    PointerObj* pointer;
    int parity;
};*/
class TrieNode;
class Pointer{
public:
    TrieNode* pointer;
    int parity;

};

class TrieNode {
public:
    //char key;
    int value;
    //TrieNode **children;
//    Pointer<TrieNode> *children;
    Pointer children[ALPHABET_SIZE];
    TrieNode() {
     //   children = new Pointer<TrieNode>[ALPHABET_SIZE];
        //children=new Pointer[ALPHABET_SIZE];
        for(int i=0;i<10;i++)
        {
            children[i].pointer= nullptr;
            children[i].parity=0;
        }
    }


};


class Trie {
private:
    int first, second, third, fourth, temp;
    TrieNode *root;
public:
    Trie();

    ~Trie();

    //void addNode(const string key, int value);
    void addKeyValue(const int key, const int value);
    //void buildTrie();

    bool isNode(const int key);

    int getNode(const int key);
};
