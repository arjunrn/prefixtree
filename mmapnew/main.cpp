#include <iostream>
#include <random>
#include <fstream>
#include <stdint.h>
#include "prefix.h"

using namespace std;

int nodecount;
int overallnodecount;
int nodesize;
u_int64_t NUM_MS_PER_BITFLIP = 1000;
volatile bool run = true;

int main() {

    // init //
    Trie trie;
    int distribution;
    u_int32_t numElements;
    cout << "How many Elements max? ";
    cin >> numElements;
    cout <<
    "For inserting the keys based on simple distribution, Uniform int distribution, Poisson distribution, press 1 or 2 or 3 accordingly!!";
    cin >> distribution;
    TrieNode *ptr;
    long falsenegatives;
    //end of init//

    // build //
    u_int32_t key[numElements];
    u_int32_t value[numElements];
    u_int32_t tempr = 4000000000;
    u_int32_t temp = 4000000000;
    u_int32_t tempq = 4000000000;
    u_int32_t corrupting = 0;
    float density = 0;

    /****************Simple distribution , keys can be multiples of 3 ***************/
    if (distribution = 1) {
        for (int i = 0; i < numElements; i++) {
            key[i] = temp;
            value[i] = tempr;
            if(numElements>20000) {
                temp = temp - 1;
                tempr = tempr - 1;
            }
            else
            {
                temp=temp-3;
                tempr=tempr-3;
            }
        }
    }
        /*****************Uniform int distribution*******************************/
    else if (distribution = 2) {
        double number1;
        double number2;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distri1(0, 4000000000);
        std::uniform_int_distribution<int> distri2(0, 60000);
        for (int i = 0; i < numElements; i++) {
            number1 = distri1(generator);
            number2 = distri2(generator);
            key[i] = number1;
            value[i] =(uint8_t) number2;
        }
    }
        /*****************Poisson distribution*******************************/
    else if (distribution = 3) {
        double number;
        std::default_random_engine generator;
        int j = 1000;
        for (int i = 0; i < numElements; i++) {
            if (i % 300 == 0 and i != 0) {
                j = j + 1000;
            }
            std::poisson_distribution<int> distrib(j);
            number = distrib(generator);
            //cout<<"The key is: "<<number<<endl;
            key[i] = number;
            value[i] =(u_int8_t) number;
        }
    }

    /*******************Inserting nodes into the tree and then check the number of nodes in a memory range******************/
    int tipo = 0;
    int tmp = 0;
    ofstream outfile;
    // outfile.open("file.txt", ios::out | ios::in | ios::app);
    trie.createTrie();
    for (int i = 0; i < numElements; i++) {
        try {
            //if(value[i]==59991)
            //if(value[i]==59310)
            //if(key[i]==3999999310)
            if(i==1045793)
            {
               cout<<"we are here!";
            }
            trie.addKeyValue(key[i], value[i]);
        } catch (exception &e) {
            cerr << "exception (i=" << i << ") " << e.what() << endl;
        }
    }
    //corrupting=0;
    //for (int i = 0; i < 1111; i++) {
    //    trie.setKeyValue();
        // corrupting++;
       // tempq = tempq - 54;
   // }
/*
    int k = 0;
    for (int r = 0; r < 1111; r++) {
        if (trie.corrupted[r] != 0)
            k++;
        else
            break;

    }*/

    for (int i = 0; i < numElements; i++) {
       cout<< trie.getNode(key[i])<<endl;
    }


   /* printf("%d number of bitflips has been detected from %d number of actual existing bitflips!!!", trie.countcorrupt,
           k);*/
    return 0;
}

