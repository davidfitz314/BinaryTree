#include "BinaryTree.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
	cout << "inserting head" << endl;
	this->head = new Node();
	cout << "head created" << endl;
	this->head->key_value = NULL;
	cout << "value inserted" << endl;
	this->head->left = NULL;
	this->head->right = NULL;
	cout << "value is " << this->head->key_value << endl;
}

Tree::~Tree()
{
	cout << "self destruct initiated..." << endl;
	for (int i = 10; i>=0; i--){
		cout << i << endl;
	}
	cout << "jk finish deconstruture later for memory cleanup ;)" << endl;
}

void Tree::Insert(int new_value)
{
	if (this->head->key_value == NULL){
		this->head->key_value = new_value;
		cout << "new head is " << this->head->key_value << endl;
		return;
	}

	if (new_value < this->head->key_value){
		//go left
		if (this->head->left == NULL){
			Node *nLeft = new Node();
			nLeft->key_value = new_value;
			nLeft->left = NULL;
			nLeft->right = NULL;
			this->head->left = nLeft;
			return;
		} else if (this->head->left != NULL){
			//begin search
			this->Insert_Search(new_value, this->head->left);
			return;
		}
	} else {
		//go right
		if (this->head->right == NULL){
			Node *nRight = new Node();
			nRight->key_value = new_value;
			nRight->left = NULL;
			nRight->right = NULL;
			this->head->right = nRight;
			return;
		} else if (this->head->right != NULL){
			//begin search
			this->Insert_Search(new_value, this->head->right);
			return;
		}
	}
	return; 
}

void Tree::Insert_Search(int new_value, Node *current)
{
	if (new_value < current->key_value){
		//go left
		if (current->left == NULL){
			Node *nLeft = new Node();
			nLeft->key_value = new_value;
			nLeft->left = NULL;
			nLeft->right = NULL;
			current->left = nLeft;
			return;
		} else if (current->left != NULL){
			//begin search
			this->Insert_Search(new_value, current->left);
			return;
		}
	} else {
		//go right
		if (current->right == NULL){
			Node *nRight = new Node();
			nRight->key_value = new_value;
			nRight->right = NULL;
			nRight->left = NULL;
			current->right = nRight;
			return;
		} else if (current->right != NULL){
			//begin search
			this->Insert_Search(new_value, current->right);
			return;
		}
	}
}

bool Tree::Remove()
{
	return false;
}

void Tree::Print()
{
	if (this->head->key_value != NULL){
		cout << "head is " << this->head->key_value << endl;
	}
	if (this->head->left != NULL){
		cout << "left is " << this->head->left->key_value << endl;
		cout << "First L" << endl;
		this->PrintR(this->head->left);
		cout << "end L" << endl;
	}
	if (this->head->right != NULL){
		cout << "right is " << this->head->right->key_value << endl;
		cout << "First R" << endl;
		this->PrintR(this->head->right);
		cout << "end R" << endl;
	}
}

void Tree::PrintR(Node *current)
{
	Node *head = current;
	if (head->left != NULL){
		cout << "left is " << head->left->key_value << endl;
		this->PrintR(head->left);
	}
	if (head->right != NULL){
		cout << "right is " << head->right->key_value << endl;
		this->PrintR(head->right);
	}
}