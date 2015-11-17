#include <string>
#include <map>
#include <iostream>
#include <stdint.h>

#define ALPHABET_SIZE 10

using namespace std;


class TrieNode {
public:

    u_int32_t *children[16];

    //indicates level of node in the tree
    TrieNode() {

        for (int i = 0; i <= 0xF; i++) {
            children[i] = nullptr;
        }
    }


};


class kvpair {
public:
    u_int32_t key;
    u_int32_t value;
    //indicates level of node in the tree
    kvpair() {

        key=0;
        value=0;
    }


};


class Trie {
private:


public:
    Trie();

    ~Trie();

    int treedegree;
    int nodecount;
    int overallnodecount;
    int nodesize;
    u_int64_t startmemrange;
    u_int64_t endmemrange;
    u_int64_t root;
    u_int64_t firstlevel;
    u_int64_t secondlevel;
    u_int64_t thirdlevel;
    u_int64_t fourthlevel;
    u_int64_t fifthlevel;
    u_int64_t sixthlevel;
    u_int64_t seventhlevel;
    u_int64_t seven1level;
    u_int64_t seven2level;
    u_int64_t seven3level;
    u_int64_t seven4level;
    u_int64_t seven5level;
    u_int64_t seven6level;
    u_int64_t seven7level;
    u_int64_t extra;
    u_int64_t corrupted[1111];
    u_int64_t  extr=0;
    u_int64_t  extr1=0;
    u_int64_t  extr2=0;
    u_int64_t  extr3=0;
    u_int64_t  extr4=0;
    /*u_int64_t extrp=0;
    u_int64_t extr2p=0;
    u_int64_t extr3p=0;*/
    u_int64_t extr4p=0;
    u_int64_t  vari1=0;
    u_int64_t  vari2=0;
    u_int64_t par1=0;
    u_int64_t par2=0;
    u_int64_t par3=0;
    u_int64_t par4=0;
    u_int64_t par5=0;
    u_int64_t par6=0;
    u_int64_t par7=0;
    u_int64_t par8=0;
    u_int32_t newkey=0;
    u_int8_t newvalue=0;
    //uint8_t *nodedegree[100];
    int countcorrupt;
    int ccorrupt;
    std::map<u_int64_t, u_int8_t> map_type;

//    TrieNode *root;
    //void addNode(const string key, int value);
    void addKeyValue(const u_int32_t  key, u_int32_t value);

    void setKeyValue();

    void createTrie();


    u_int32_t  getNode(const u_int32_t key);

    u_int8_t getByte(int flagbit,u_int8_t bytee);
    u_int8_t setByte(int flagbit,u_int8_t bytee);
    u_int64_t getextr3(u_int64_t extr3);
    u_int64_t getextr4(u_int64_t extr3);
};
