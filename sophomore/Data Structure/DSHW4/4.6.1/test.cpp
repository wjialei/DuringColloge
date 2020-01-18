#include "LinkedQueue.h"

void main()
{
	// ��������
	linkedQueue<int> *q = new linkedQueue<int>();
	cout << "First, create a new empty linked queue..."
		<< "\nNow show my queue:" << endl;
	q->print();

	// push ����
	cout << "\nThen push 1985 into the queue..."
		<< "\nNow show my queue:" << endl;
	q->Push(1).Push(9).Push(8).Push(5);
	q->print();

	// front&rear ����
	cout << "\n\nFront of the queue is: " << q->Front()
		<< "\nRear of this queue is: " << q->Rear();

	//pop ����
	cout << "\n\nNow pop from front...\n"
		<< "After popping:\n ";
	q->Pop();
	q->print();

	cout << "\n\nTest finished;" << endl;

	// ʹ���򲻻�ֱ������
	while (1);
}
