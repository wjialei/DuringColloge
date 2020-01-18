#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <stack>
#include <iostream>

using namespace std;


struct Pair
{
	Pair(int a, int b)
	{
		vertex = a;
		dur = b;
	}
	int vertex;
	int dur;
};

class Graph
{
	friend class TopoIterator;
public:
	Graph(int vertices = 9)
	{
		n = vertices;
		edges = 11;
		HeadNodes = new list<Pair>[n];
		count = new int[n];
		t = new int[n];
	}
	void init()
	{
		count[0] = 0;//count 初始化
		count[1] = 1;
		count[2] = 1;
		count[3] = 1;
		count[4] = 2;
		count[5] = 1;
		count[6] = 1;
		count[7] = 2;
		count[8] = 2;

		Pair a1(1, 6);
		Pair a2(2, 4);
		Pair a3(3, 5);
		Pair a4(4, 1);
		Pair a5(4, 1);
		Pair a6(5, 2);
		Pair a7(6, 9);
		Pair a8(7, 7);
		Pair a9(7, 4);
		Pair a10(8, 2);
		Pair a11(8, 4);

		HeadNodes[0].push_back(a1);
		HeadNodes[0].push_back(a2);
		HeadNodes[0].push_back(a3);
		HeadNodes[1].push_back(a4);
		HeadNodes[2].push_back(a5);
		HeadNodes[3].push_back(a6);
		HeadNodes[4].push_back(a7);
		HeadNodes[4].push_back(a8);
		HeadNodes[5].push_back(a9);
		HeadNodes[6].push_back(a10);
		HeadNodes[7].push_back(a11);
	}

	void TopologicalOrder()
	{
		int top = -1;//empty stack
		int pos = 0;//current position
		int j;
		for (int i = 0; i < n; i++)
		{
			if (count[i] == 0)
			{
				count[i] = top;
				top = i;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (top == -1)
			{
				cout << "有环路" << endl;
				return;
			}
			else
			{
				j = top;
				top = count[top];//pop stack
				t[pos++] = j;
				if (j == n - 1)
					break;
				list<Pair>::iterator li = HeadNodes[j].begin();
				Pair k = *li;
				while (li != HeadNodes[j].end())
				{
					k = *li;
					count[k.vertex]--;
					if (count[k.vertex] == 0)
					{
						count[k.vertex] = top;
						top = k.vertex;
					}
					li++;
				}

			}
		}
	}

private:
	list<Pair> *HeadNodes;//有关联的结点对的集合列表
	int *count, *t;//入度，出度
	int n;//结点个数
	int edges;//边数
};
class TopoIterator
{
public:
	TopoIterator(Graph graph)
	{
		for (int i = graph.n - 1; i >= 0; i--)
			s.push(graph.t[i]);
	}
	int Next()
	{
		if (!s.empty())
		{
			current = s.top();
			s.pop();
			return current;
		}
		else
			return -1;
	}
private:
	Graph g;
	stack<int> s;
	int current;
};
#endif
