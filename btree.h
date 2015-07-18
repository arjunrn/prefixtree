//
// Created by mina on 07.07.15.
//

#ifndef MINA_BTREE_H
#define MINA_BTREE_H

struct Node
{
	int value;
	Node *left;
	Node *right;
};

class BTree {

	public:
		BTree();
		~BTree();

		void insert(int key);
		Node* search(int key);
		void print(Node *n);	
		void printLevelOrder();
		Node *root;
};


#endif //MINA_BTREE_H
