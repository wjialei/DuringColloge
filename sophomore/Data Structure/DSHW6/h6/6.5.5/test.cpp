#include "Graph.h"

/*
5  ����һ��������TopIterator��������˳���������һ�������޻�ͼ��ÿ�����㡣
*/

void main()
{
	Graph g(9);
	g.init();
	g.TopologicalOrder();
	TopoIterator it(g);
	for (int n = 0; n < 9; n++)
		cout << it.Next() << "  ";

	while (1);
}
