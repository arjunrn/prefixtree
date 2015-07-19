//
// Created by mina on 07.07.15.
//

#include "btree.h"
#include <iostream>
#include <queue>
using namespace std;

void BTree::insert(int key) {
	Node* new_node=new Node();//defined in a heap
	(*new_node).value=key;
	if(this->root==nullptr){
		this->root = new_node;
		return;
	}
	Node *next = this->root;
	Node *curr = nullptr;
	do{
		curr = next;
		if (key < curr->value) {
			next = curr->left;
		}
		else {
			next = curr->right;
		}	
	} while(next != nullptr);

	if (key < curr->value) {
		curr->left = new_node;
	}
	else {
		curr->right = new_node;
	}

}

BTree::BTree() {

}

void BTree::print(Node* n) {
	if(n->left != nullptr) this->print(n->left);
	cout <<  n->value << " ";
	if(n->right != nullptr) this->print(n->right);
}

void BTree::printLevelOrder() {
	if (!this->root) return;
	queue<Node*> nodesQueue;
	int nodesInCurrentLevel = 1;
	int nodesInNextLevel = 0;
	nodesQueue.push(root);
	while (!nodesQueue.empty()) {
		Node *currNode = nodesQueue.front();
		nodesQueue.pop();
		nodesInCurrentLevel--;
		if (currNode) {
			cout << currNode->value << " ";
			nodesQueue.push(currNode->left);
			nodesQueue.push(currNode->right);
			nodesInNextLevel += 2;
		}
		if (nodesInCurrentLevel == 0) {
			cout << endl;
			nodesInCurrentLevel = nodesInNextLevel;
			nodesInNextLevel = 0;
		}
	}
}
