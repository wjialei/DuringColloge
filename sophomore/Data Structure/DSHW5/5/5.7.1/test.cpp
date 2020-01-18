#include<iostream>
#include<iomanip>
#include<cmath>
#include"Dictionary.h"

using namespace std;
/*
1.	删除键值为K的元素，给出时间复杂度。
2.	初始化一棵空的二叉树，随机插入n个元素。使用统一的随机数产生器得到带插入的值。
	计算所得到二叉查找树的高度，并将这个高度除以Log2n,n分别为100，500，1000，2000，
	3000，…，10000。验证该比值接近于常数（约为2）。
*/

void main()
{

	Dictionary<int, int>d;
	d.randomTree(5);
	cout << "随机种树…\n中序遍历:";
	d.inorder(d.getRoot());
	cout << endl << "\n树高：" << d.height(d.getRoot(), 1);
	// 清空测试数据
	d.recurDel(d.getRoot());
	cout << endl << endl << "接下来是一组测试数据：" << endl;
	double test = 0;
	double average = 0;
	// 第一组
	d.randomTree(100);
	test = d.height(d.getRoot(), 1) * log((double)2) / log((double)100);
	average += test;
	cout << test << " ";
	d.recurDel(d.getRoot());
	// 第二组
	d.randomTree(500);
	test = d.height(d.getRoot(), 1) * log10((double)2) / log10((double)500);
	average += test;
	cout << test << " ";
	d.recurDel(d.getRoot());
	// 3~12组
	for (int i = 1000; i <= 10000; i += 1000)
	{
		d.randomTree(i);
		test = d.height(d.getRoot(), 1) * log10((double)2) / log10((double)i);
		average += test;
		cout << setw(10) << test;
		d.recurDel(d.getRoot());
	}

	cout << endl << "平均值：" << average / 12 << endl;

	while (1);
}
