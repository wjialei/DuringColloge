#include "Tree.h"
/*
��1��ʵ��һ��c++������������һ�Ŷ�������Ҷ�ڵ����Ŀ������ʱ�临�Ӷȡ�
	ʱ�临�Ӷȣ�O(n)
��4��������������ʵ��һ����������ɾ���������е����н�㣬���������ĸ��Ӷȡ�
	ʱ�临�Ӷȣ�O(n)
*/
void main()
{
	// TreeNode<char> *myRoot = new TreeNode<char>('+');
	Tree<char> *my = new Tree<char>('+');

	my->getRoot()->setLeft('*');
	my->getRoot()->setRight('E');

	my->getRoot()->getLeft()->setLeft('*');
	my->getRoot()->getLeft()->setRight('D');

	my->getRoot()->getLeft()->getLeft()->setLeft('/');
	my->getRoot()->getLeft()->getLeft()->setRight('C');

	my->getRoot()->getLeft()->getLeft()->getLeft()->setLeft('A');
	my->getRoot()->getLeft()->getLeft()->getLeft()->setRight('B');

	// ����empty()����
	cout << "Tree is empty?(0 or 1)   "
		<< my->isEmpty() << endl;
	// ���ֱ����ĵݹ����
	cout << "Preorder: ";
	my->Preorder();
	cout << endl;
	cout << "Inorder: ";
	my->Inorder();
	cout << endl;
	cout << "Postorder: ";
	my->Postorder();
	cout << endl;
	cout << "LevelOrder: ";
	my->Levelorder();
	cout << endl;
	// ����������
	cout << "NonrecPreorder: ";
	my->NonrecPreorder();
	cout << endl;
	cout << "NonrecInorder: ";
	my->InorderTraverse();
	cout << endl;
	cout << "the number of left nodes is : " << my->LeafNodeNum(my->getRoot()) << endl;

	while (1);
}
