#include <iostream>
#include <list>
#include "Graph.h"
using namespace std;

/*
2   ���AOE�������ÿ������������ٿ�ʼʱ�䡣������ǰ-�����ԡ�
*/

void main()
{
	Graph g(10);
	g.init();
	g.TopologicalOrder();
	cout << "�¼����緢��ʱ�䣺" << endl;
	g.EarliestEventTime();
	cout << "�¼���ٷ���ʱ�䣺" << endl;
	g.LatestEventTime();
	cout << "����緢��ʱ�䣺" << endl;
	g.EarliestActivitiesTime();
	cout << "���ٿ�ʼʱ�䣺" << endl;
	g.LatestActivitiesTime();
	cout << "�ؼ���У�" << endl;
	g.CriticalActivities();

	while (1);
}
