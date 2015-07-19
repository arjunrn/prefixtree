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
    return 0;
}
