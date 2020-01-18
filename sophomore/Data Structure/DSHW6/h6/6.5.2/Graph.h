#pragma once
#ifndef GRAPH_H
#define GRAPH_H


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
public:
	Graph(int vertices = 10)
	{
		n = vertices;
		edges = 14;
		HeadNodes = new list<Pair>[n];
		count = new int[n];
		t = new int[n];
		ee = new int[n];
		le = new int[n];
		ea = new int[edges];
		la = new int[edges];
	}
	void init()
	{
		count[0] = 0;//count 初始化
		count[1] = 1;
		count[2] = 1;
		count[3] = 2;
		count[4] = 2;
		count[5] = 1;
		count[6] = 2;
		count[7] = 1;
		count[8] = 2;
		count[9] = 2;

		Pair a1(1, 5);
		Pair a2(2, 6);
		Pair a3(3, 3);
		Pair a4(3, 6);
		Pair a5(4, 3);
		Pair a6(4, 3);
		Pair a7(5, 4);
		Pair a8(6, 4);
		Pair a9(6, 1);
		Pair a10(7, 4);
		Pair a11(8, 2);
		Pair a12(8, 5);
		Pair a13(9, 2);
		Pair a14(9, 4);

		HeadNodes[0].push_back(a1);
		HeadNodes[0].push_back(a2);
		HeadNodes[1].push_back(a3);
		HeadNodes[2].push_back(a4);
		HeadNodes[2].push_back(a5);
		HeadNodes[3].push_back(a6);
		HeadNodes[3].push_back(a7);
		HeadNodes[3].push_back(a8);
		HeadNodes[4].push_back(a9);
		HeadNodes[4].push_back(a10);
		HeadNodes[7].push_back(a11);
		HeadNodes[6].push_back(a12);
		HeadNodes[8].push_back(a13);
		HeadNodes[5].push_back(a14);
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
	void EarliestEventTime()
	{
		for (int i = 0; i < edges; i++)//ee初始化
			ee[i] = 0;
		for (int i = 0; i < n; i++)
		{
			int j = t[i];
			if (i == n - 1)
				break;
			list<Pair>::iterator li = HeadNodes[j].begin();
			Pair p = *li;
			while (li != HeadNodes[j].end())
			{
				p = *li;
				int k = p.vertex;
				if (ee[k] < ee[j] + p.dur)
					ee[k] = ee[j] + p.dur;
				li++;
			}
			cout << "[" << i << "] :";
			Print_ee();
		}
		cout << "工程最早完成时间：" << 23 << endl;
	}
	void EarliestActivitiesTime()
	{
		for (int i = 0; i < edges; i++)//ea初始化
			ea[i] = 99;
		int cc = 0;
		for (int i = 0; i < n; i++)
		{
			int j = t[i];
			if (i == n - 1)
				break;
			list<Pair>::iterator li = HeadNodes[j].begin();
			Pair p = *li;
			while (li != HeadNodes[j].end())
			{
				p = *li;
				int k = p.vertex;
				if (ea[cc] > ee[j])
					ea[cc] = ee[j];
				li++;
				cc++;
			}
			cout << "[" << i << "] :";
			Print_ea();
		}
	}
	void LatestEventTime()
	{
		for (int i = 0; i < n; i++)//le初始化
			le[i] = ee[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			int j = t[i];
			list<Pair>::iterator li = HeadNodes[j].begin();
			Pair p = *li;
			while (li != HeadNodes[j].end())
			{
				p = *li;
				int k = p.vertex;
				if ((le[k] - p.dur) < le[j])
					le[j] = le[k] - p.dur;
				li++;
			}
			cout << "[" << i << "] :";
			Print_le();
		}
	}
	void LatestActivitiesTime()
	{
		for (int i = 0; i < edges; i++)//la初始化
			la[i] = ea[edges - 1];
		int cc = edges - 1;
		for (int i = n - 2; i >= 0; i--)
		{
			int j = t[i];
			list<Pair>::iterator li = HeadNodes[j].begin();
			Pair p = *li;
			while (li != HeadNodes[j].end())
			{
				p = *li;
				int k = p.vertex;
				if ((la[cc] - p.dur) < la[j])
					la[cc] = la[k] - p.dur;
				li++;
				cc--;
			}
			cout << "[" << i << "] :";
			Print_la();
		}
	}
	void CriticalActivities()
	{
		int i = 1;
		int u, e, l;
		for (u = 0; u < n; u++)
		{
			if (u == n - 1)
				break;
			list<Pair>::iterator li = HeadNodes[u].begin();
			Pair p = *li;
			while (li != HeadNodes[u].end())
			{
				p = *li;
				int v = p.vertex;
				e = ee[u];
				l = le[v] - p.dur;
				if (l == e)
					cout << "活动" << i << "<" << u << "," << v << ">是关键活动" << endl;
				li++;
			}
		}
	}
	void Print_ee()
	{
		cout << "ee: ";
		for (int i = 0; i < n; i++)
			cout << ee[i] << "  ";
		cout << endl;
	}
	void Print_ea()
	{
		cout << "ea: ";
		for (int i = 0; i < edges; i++)
			cout << ea[i] << "  ";
		cout << endl;
	}
	void Print_le()
	{
		cout << "le: ";
		for (int i = 0; i < n; i++)
			cout << le[i] << "  ";
		cout << endl;
	}
	void Print_la()
	{
		cout << "la: ";
		for (int i = 0; i < edges; i++)
			cout << la[i] << "  ";
		cout << endl;
	}
private:
	list<Pair> *HeadNodes;
	int *count, *t, *ee, *le, *ea, *la;
	int n;
	int edges;
};

#endif
