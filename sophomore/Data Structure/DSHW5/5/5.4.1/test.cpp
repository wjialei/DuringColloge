#include "Tree.h"
/*
（1）实现一个c++函数用来计算一颗二叉树中叶节点的数目，给出时间复杂度。
	时间复杂度：O(n)
（4）【析构函数】实现一个函数用来删除二叉树中的所有结点，并给出它的复杂度。
	时间复杂度：O(n)
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

	// 测试empty()函数
	cout << "Tree is empty?(0 or 1)   "
		<< my->isEmpty() << endl;
	// 四种遍历的递归测试
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
	// 迭代器遍历
	cout << "NonrecPreorder: ";
	my->NonrecPreorder();
	cout << endl;
	cout << "NonrecInorder: ";
	my->InorderTraverse();
	cout << endl;
	cout << "the number of left nodes is : " << my->LeafNodeNum(my->getRoot()) << endl;

	while (1);
}
