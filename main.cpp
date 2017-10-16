#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"
using namespace std;

int main()
{
	cout << "begin tests" << endl;
	Tree *mytree = new Tree();
	for (int i = 0; i<100; i++){
		int r = (rand() % 100) + 1;
		mytree->Insert(r);
	}
	mytree->Print();
	cout << "test complete" << endl;
	return 0;
}