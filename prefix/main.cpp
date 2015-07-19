#include "prefix.h"
#include <iostream>

using namespace std;

int main() {
    Trie trie;
    trie.addNode("arjun", 10);
    trie.addNode("arjunam", 50);
    cout << "Hello World!!" << endl;
    cout << trie.getNode("arjun") << endl;
    cout << trie.getNode("arjunam") << endl;
    cout << "Key Present: arjun: " << trie.isNode("arjun") << endl;
    cout << "Key Present: mina: " << trie.isNode("mina") << endl;
    return 0;
}
