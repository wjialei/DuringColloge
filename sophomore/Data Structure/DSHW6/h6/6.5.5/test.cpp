#include "Graph.h"

/*
5  定义一个迭代类TopIterator，按拓扑顺序迭代处理一个有向无环图的每个顶点。
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
