#include <iostream>
#include <time.h>
#include <windows.h>
#include "Set.h"
using namespace std;
/*��3��ͨ��ʵ��ֱ��SimpleUnion��SimpleFind��WeightedUnion��CollapsingFind���������ܽ��бȽϡ�
	Ϊ�ˣ������������һ�鲢�Ͳ��ҵĲ�����
*/
void main()
{
	Sets simple(1000);
	Sets weight(1000);
	simple.Simpleinit();
	weight.Weightinit();

	srand(time(0));
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);
	for (int i = 0; i < 10000; i++)
		simple.SimpleFind(rand() % 1000);
	QueryPerformanceCounter(&t2);
	cout << "SimpleFind Use Time:  " << (t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart << endl;

	LARGE_INTEGER t3, t4;
	QueryPerformanceCounter(&t3);
	for (int i = 0; i < 10000; i++)
		weight.CollapsingFind(rand() % 1000);
	QueryPerformanceCounter(&t4);
	cout << "CollapsingFind Use Time:  " << (t4.QuadPart - t3.QuadPart)*1.0 / tc.QuadPart << endl;

	while (1);
}
