#pragma once
#ifndef WINNERTREE_H
#define WINNERTREE_H

class WinnerTree {
public:
	//���캯��
	WinnerTree(int p)
	{
		k = p;
		//��Ҷ�ӽڵ�
		l = new int[k];
		buf = new int[k];
	}
	//����һ��ʤ����
	void build()
	{
		for (int i = k - 1; i > 0; i--)
			if (getKey(2 * i) > getKey(2 * i + 1))
				l[i] = getIndex(2 * i + 1);
			else
				l[i] = getIndex(2 * i);
		l[0] = l[0];//��¼��ʤ��
	}
private:
	int k;
	int* l;
	int* buf;
	//��������
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
