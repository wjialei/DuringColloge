#pragma once
#ifndef WINNERTREE_H
#define WINNERTREE_H

class WinnerTree {
public:
	//构造函数
	WinnerTree(int p)
	{
		k = p;
		//非叶子节点
		l = new int[k];
		buf = new int[k];
	}
	//构建一个胜者树
	void build()
	{
		for (int i = k - 1; i > 0; i--)
			if (getKey(2 * i) > getKey(2 * i + 1))
				l[i] = getIndex(2 * i + 1);
			else
				l[i] = getIndex(2 * i);
		l[0] = l[0];//记录总胜者
	}
private:
	int k;
	int* l;
	int* buf;
	//辅助函数
	int getIndex(int i) {
		if (i < k)
			return l[i];
		else
			return (i - k);
	}
	int getKey(int i)
	{
		if (i < k)
			return buf[l[i]];
		else
			return buf[i - k];
	}
}
#endif
