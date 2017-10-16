#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

struct Node
{
	int key_value;
	Node *left;
	Node *right;
};

class Tree
{
public:
	Tree();
	~Tree();
	void Insert(int new_value);
	void Insert_Search(int new_value, Node *current);
	bool Remove();
	void Print();
	void PrintR(Node *current);
private:
	Node *head;
};

#endif