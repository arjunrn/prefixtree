#include "prefix.h"
#include <iostream>

using namespace std;

int main() {
    Trie trie;
    //trie.addNode("arjun", 10);
    //trie.addNode("arjunam", 50);
    trie.addKeyValue(1235,"mina");
    trie.addKeyValue(1234,"mary");
    cout << "Hello World!!" << endl;
    cout << trie.getNode(1235) << endl;
    cout << trie.getNode(1234) << endl;
    //cout << "Key Present: arjun: " << trie.isNode("arjun") << endl;
    //cout << "Key Present: mina: " << trie.isNode("mina") << endl;
    return 0;
}
