#include <iostream>
#include "btree.h"

using namespace std;



int main() {
	BTree *b=new BTree();
	(*b).insert(5);
	b->insert(3);
	b->insert(4);
	b->insert(0);
	b->insert(9);
	b->insert(12);
	b->insert(3);
	b->print(b->root);
	b->printLevelOrder();
	return 0;
}
