#include "TBTree.h"

void main()
{
	ThreadedNode<int>* n = new ThreadedNode<int>(0);
	ThreadedNode<int>* l = new ThreadedNode<int>(1);
	ThreadedNode<int>* r = new ThreadedNode<int>(2);
	ThreadedTree<int> t(n);

	t.InsertLeft(n, l);
	t.InsertRight(l, r);
	t.InsertLeft(n, new ThreadedNode<int>(3));
	t.PreorderTraverse();

	cout << endl;
	

	while (1);

}