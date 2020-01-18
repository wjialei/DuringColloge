#include <iostream>
#include <list>
#include "Graph.h"
using namespace std;

/*
2   针对AOE网，获得每个活动的最早和最迟开始时间。采用向前-向后策略。
*/

void main()
{
	Graph g(10);
	g.init();
	g.TopologicalOrder();
	cout << "事件最早发生时间：" << endl;
	g.EarliestEventTime();
	cout << "事件最迟发生时间：" << endl;
	g.LatestEventTime();
	cout << "活动最早发生时间：" << endl;
	g.EarliestActivitiesTime();
	cout << "活动最迟开始时间：" << endl;
	g.LatestActivitiesTime();
	cout << "关键活动有：" << endl;
	g.CriticalActivities();

	while (1);
}
