#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class Queue
{
public:
	Queue(int size = 10)
	{
		if (size < 0)
			throw" Size of a queue must be > 0;\n";
		capacity = size;
		queue = new T[capacity];

		front = rear = 0;
	}

	bool isEmpty()
	{
		return (front == rear);
	}

	Queue& Push(T x)
	{
		if ((rear + 1) % capacity == front)
		{
			T *newQueue = new T[2 * capacity];

			int start = (front + 1) % capacity;
			if (start < 2)
				copy(queue + start, queue + start + capacity - 1, newQueue);
			else
			{
				copy(queue + start, queue + capacity, newQueue);
				copy(queue, queue + rear + 1, newQueue + capacity - start);
			}

			front = 2 * capacity - 1;
			rear = capacity - 2;
			capacity *= 2;
			delete[]queue;
			queue = newQueue;
		}
		rear = (rear + 1) % capacity;
		queue[rear] = x;

		return *this;
	}

	void Pop()
	{
		if (isEmpty())
			throw "Queue is empty.Cannot delete.";
		front = (front + 1) % capacity;
		queue[front].~T();
	}

	void halve(Queue& q1, Queue& q2)
	{
		int mid = 0;  //ÖÐ¼äÎ»ÖÃ

		int start = (front + 1) % capacity;
		//1.no wrap
		if (start < rear)
		{
			mid = (front + rear) / 2;
			copy(queue + start, queue + start + mid, q1.queue);
			copy(queue + start + mid, queue + rear + 1, q2.queue);

			q1.front = q1.capacity - 1;
			q1.rear = mid - start;

			q2.front = q2.capacity - 1;
			q2.rear = rear - mid - 1;
		}
		else
		{
			mid = ((start + rear + capacity) / 2) % capacity;

			if (mid >= front)
			{
				copy(queue + start, queue + mid + 1, q1.queue);
				copy(queue + mid + 1, queue + capacity, q2.queue);
				copy(queue, queue + rear + 1, q2.queue + capacity - mid - 1);
				q1.front = q1.capacity - 1;
				q1.rear = mid - start;
				q2.front = q2.capacity - 1;
				q2.rear = capacity - 1 - mid + rear;
			}
			else
			{
				copy(queue + start, queue + capacity, q1.queue);
				copy(queue, queue + mid + 1, q1.queue + capacity - start);
				copy(queue + mid + 1, queue + rear + 1, q2.queue);
				q1.front = q1.capacity - 1;
				q2.front = q2.capacity - 1;
				q1.rear = capacity - 1 - start + mid;
				q2.rear = rear - mid - 1;
			}
		}
	}

	T& Front()
	{
		if (isEmpty())    cout << "Queue is empty";
		return queue[(front + 1) % capacity];
	}
	T& Rear()const
	{
		if (isEmpty())
			cout << "Queue is empty";
		return queue[rear];
	}

	void output()
	{
		if ((front + 1) % capacity < rear)
			for (int i = (front + 1) % capacity; i <= rear; i++)
				cout << setw(4) << queue[i];
		else
		{
			for (int i = (front + 1) % capacity; i <= capacity - 1; i++)
				cout << setw(4) << queue[i];
			for (int i = 0; i < rear + 1; i++)
				cout << setw(4) << queue[i];
		}

		cout << endl;
	}

private:
	T *queue;
	int capacity;
	int front;
	int rear;
};
#endif



