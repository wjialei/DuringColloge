#include "Graph.h"

/*
 3，5  假定图采用领接表表示描写一个完整的深度/广度优先搜索的c++函数。用适当的图检测函数的正确性
 6     说明怎样修改函数DFS，使它像在Components中一样，产生所有最近访问的顶点的列表
*/

int main()
{
	Graph g;
	cout << "创建图6.17中G的邻接表\n…\n";
	g.init();
	cout << "DFS深度优先搜索结果：";
	g.DFS();
	cout << endl;
	cout << "BFS广度优先搜索结果：";
	g.BFS(0);
	cout << endl;
	while (1);
}
