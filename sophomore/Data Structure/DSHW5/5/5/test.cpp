#include "Tree.h"

int main()
{
	TreeNode<char> *root = new TreeNode<char>('a');
	Tree<char> testTree;

	cout << "InorderTranerse:";
	testTree.InorderTraverse();
	cout << endl;

	cout << "NonrecPreorder: ";
	testTree.NonrecPreorder();
	cout << endl;
}
