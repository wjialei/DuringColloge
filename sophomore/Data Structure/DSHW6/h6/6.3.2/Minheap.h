#pragma once
#ifndef MH_H
#define MH_H

#include <iostream>
#include <iomanip>
using namespace std;

struct Edge
{
	int first;
	int second;
	int length;
};
class Minheap
{
public:
	Minheap(int s = 10)
	{
		n = 0;
		capacity = s;
		heap = new Edge[capacity + 1];
	}
	bool isempty()
	{
		return n == 0;
	}
	void Insert(int a, int b, int l)
	{
		if (n == capacity)
			return;
		n++;
		int i = n;
		while (i > 1)
		{
			if (l >= heap[i / 2].length)
				break;
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i].first = a;
		heap[i].second = b;
		heap[i].length = l;
	}
	Edge pop()
	{
		if (!n)
		{
			Edge e;
			return e;
		}
		Edge result = heap[1];
		int k = heap[n].length;
		n--;
		int i = 1;
		for (int j = 2; j <= n;)
		{
			if (heap[j].length > heap[j + 1].length)
				j++;
			if (k < heap[j].length)
				break;
			heap[i] = heap[j];
			i = j;
			j *= 2;
		}
		heap[i].length = k;
		return result;
	}
private:
	Edge *heap;
	int n;
	int capacity;
};
class Sets
{
public:
	Sets(int s = 7)
	{
		n = s;
		parent = new int[s];
		for (int i = 0; i < n; i++)
			parent[i] = -1;
	}
	void SimpleUnion(int i, int j)
	{
		parent[i] = j;
	}
	int SimpleFind(int i)//find root of i
	{
		if (parent[i] == -1)
			return -1;
		while (parent[i] > 0)
			i = parent[i];
		return i;
	}
private:
	int *parent;
	int n;
};

class Graph
{
public:
	Graph(int vertices = 7)
	{
		n = vertices;
		count = 0;
		edge = new int*[n];
		for (int i = 0; i < n; i++)
		{
			edge[i] = new int[n];
		}
	}
	void init()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				edge[i][j] = 0;
		addEdge(0, 1, 28);
		addEdge(0, 5, 10);
		addEdge(1, 6, 14);
		addEdge(1, 2, 16);
		addEdge(2, 3, 12);
		addEdge(3, 6, 18);
		addEdge(3, 4, 22);
		addEdge(4, 5, 25);
		addEdge(4, 6, 24);
	}
	void addEdge(int r, int c, int v)
	{
		edge[r][c] = v;
		edge[c][r] = v;
		heap.Insert(r, c, v);
		count++;
	}
	void Kruskal()
	{
		Graph T;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				T.edge[i][j] = 0;
		Edge e;
		while (!heap.isempty())
		{
			e = heap.pop();
			if ((T.count < n - 1) && (!(sets.SimpleFind(e.first) == sets.SimpleFind(e.second)) || (sets.SimpleFind(e.first) == -1 && sets.SimpleFind(e.second) == -1)))//bu在同一联通分量里
			{
				T.addEdge(e.first, e.second, e.length);
				sets.SimpleUnion(e.first, e.second);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << setw(5) << T.edge[i][j];
			cout << endl;
		}
	}
private:
	bool * visited;
	Minheap heap;
	int **edge;
	int *length;
	int n;
	int count;
	Sets sets;
};

#endif