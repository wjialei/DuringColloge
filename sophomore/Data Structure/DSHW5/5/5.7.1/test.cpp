#include<iostream>
#include<iomanip>
#include<cmath>
#include"Dictionary.h"

using namespace std;
/*
1.	ɾ����ֵΪK��Ԫ�أ�����ʱ�临�Ӷȡ�
2.	��ʼ��һ�ÿյĶ��������������n��Ԫ�ء�ʹ��ͳһ��������������õ��������ֵ��
	�������õ�����������ĸ߶ȣ���������߶ȳ���Log2n,n�ֱ�Ϊ100��500��1000��2000��
	3000������10000����֤�ñ�ֵ�ӽ��ڳ�����ԼΪ2����
*/

void main()
{

	Dictionary<int, int>d;
	d.randomTree(5);
	cout << "���������\n�������:";
	d.inorder(d.getRoot());
	cout << endl << "\n���ߣ�" << d.height(d.getRoot(), 1);
	// ��ղ�������
	d.recurDel(d.getRoot());
	cout << endl << endl << "��������һ��������ݣ�" << endl;
	double test = 0;
	double average = 0;
	// ��һ��
	d.randomTree(100);
	test = d.height(d.getRoot(), 1) * log((double)2) / log((double)100);
	average += test;
	cout << test << " ";
	d.recurDel(d.getRoot());
	// �ڶ���
	d.randomTree(500);
	test = d.height(d.getRoot(), 1) * log10((double)2) / log10((double)500);
	average += test;
	cout << test << " ";
	d.recurDel(d.getRoot());
	// 3~12��
	for (int i = 1000; i <= 10000; i += 1000)
	{
		d.randomTree(i);
		test = d.height(d.getRoot(), 1) * log10((double)2) / log10((double)i);
		average += test;
		cout << setw(10) << test;
		d.recurDel(d.getRoot());
	}

	cout << endl << "ƽ��ֵ��" << average / 12 << endl;

	while (1);
}
