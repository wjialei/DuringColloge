#pragma once
#ifndef SET_H
#define SET_H

class Sets
{
public:
	Sets(int s = 10)
	{
		n = s;
		parent = new int[s];
		for (int i = 0; i < n; i++)
			parent[i] = -1;
	}
	void Simpleinit()
	{
		for (int i = 0; i < n - 1; i++)
			SimpleUnion(i, i + 1);
	}
	void Weightinit()
	{
		for (int i = 0; i < n - 1; i++)
			WeightUnion(i, i + 1);
	}
	//Simple
	void SimpleUnion(int i, int j)
	{
		parent[i] = j;
	}
	int SimpleFind(int i)//find root of i
	{
		while (parent[i] > 0)
			i = parent[i];
		return i;
	}
	//Weight
	void WeightUnion(int i, int j)
	{
		int temp = parent[i] + parent[j];
		if (parent[j] < parent[i])//j has more children
		{
			parent[i] = j;
			parent[j] = temp;
		}
		else
		{
			parent[j] = i;
			parent[i] = temp;
		}
	}
	int CollapsingFind(int i)
	{
		int r = i;
		for (; parent[r] >= 0; r = parent[r]);//find root
		while (i != r)
		{
			int s = parent[i];
			parent[i] = r;
			i = s;
		}
		return r;
	}
private:
	int *parent;
	int n;
};

#endif
