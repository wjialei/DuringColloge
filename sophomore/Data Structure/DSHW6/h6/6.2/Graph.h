#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
	Graph(int vertices = 8)
	{
		n = vertices;
		HeadNodes = new list<int>[n];
	}
	void init()
	{
		HeadNodes[0].push_back(1);
		HeadNodes[0].push_back(2);
		HeadNodes[1].push_back(0);
		HeadNodes[1].push_back(3);
		HeadNodes[1].push_back(4);
		HeadNodes[2].push_back(0);
		HeadNodes[2].push_back(5);
		HeadNodes[2].push_back(6);
		HeadNodes[3].push_back(1);
		HeadNodes[3].push_back(7);
		HeadNodes[4].push_back(1);
		HeadNodes[4].push_back(7);
		HeadNodes[5].push_back(2);
		HeadNodes[5].push_back(7);
		HeadNodes[6].push_back(2);
		HeadNodes[6].push_back(7);
		HeadNodes[7].push_back(3);
		HeadNodes[7].push_back(4);
		HeadNodes[7].push_back(5);
		HeadNodes[7].push_back(6);

	}
	void DFS()
	{
		visited = new bool[n];
		for (int i = 0; i < n; i++)
			visited[i] = false;
		dfs(0);
		delete[]visited;
	}
	void dfs(int x)
	{
		cout << x << "  ";
		visited[x] = true;
		list<int>::iterator i;
		for (i = HeadNodes[x].begin(); i != HeadNodes[x].end(); ++i)
			if (!visited[*i])
				dfs(*i);
	}
	void BFS(int x)
	{
		visited = new bool[n];
		for (int i = 0; i < n; i++)
			visited[i] = false;
		visited[x] = true;
		cout << x << "  ";
		queue<int> q;
		q.push(x);
		while (!q.empty())
		{
			x = q.front();
			q.pop();
			list<int>::iterator i;
			for (i = HeadNodes[x].begin(); i != HeadNodes[x].end(); ++i)
				if (!visited[*i])
				{
					cout << *i << "  ";
					visited[*i] = true;
					q.push(*i);
				}
		}
		delete[] visited;
	}
private:
	list<int> *HeadNodes;
	bool * visited;
	int n;
};

#endif
