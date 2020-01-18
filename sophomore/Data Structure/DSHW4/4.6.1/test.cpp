#include "LinkedQueue.h"

void main()
{
	// 创建对象
	linkedQueue<int> *q = new linkedQueue<int>();
	cout << "First, create a new empty linked queue..."
		<< "\nNow show my queue:" << endl;
	q->print();

	// push 测试
	cout << "\nThen push 1985 into the queue..."
		<< "\nNow show my queue:" << endl;
	q->Push(1).Push(9).Push(8).Push(5);
	q->print();

	// front&rear 测试
	cout << "\n\nFront of the queue is: " << q->Front()
		<< "\nRear of this queue is: " << q->Rear();

	//pop 测试
	cout << "\n\nNow pop from front...\n"
		<< "After popping:\n ";
	q->Pop();
	q->print();

	cout << "\n\nTest finished;" << endl;

	// 使程序不会直接跳出
	while (1);
}
