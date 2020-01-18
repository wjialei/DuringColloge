#pragma once
#ifndef CHAINNODE_H
#define CHAINNODE_H

#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
class linkedQueue;

template<class T>
class chainNode
{
	friend class linkedQueue<T>;
public:
	// 链表节点中初始化为空
	chainNode(T element = 0, chainNode<T> *next = 0)
	{
		data = element;
		link = next;
	}
private:
	T data;
	chainNode<T> *link;
};

template<class T>
class linkedQueue
{
public:
	linkedQueue()
	{
		front = rear = 0;
	}

	bool isEmpty()
	{
		return front == 0;
	}

	T& Front()
	{
		if (isEmpty())
			cout << "Empty linked queue!";
		else
			return front->data;
	}

	T& Rear()
	{
		if (isEmpty())
			cout << "Empty linked queue!";
		else
			return rear->data;
	}


	linkedQueue& Push(const T&e)
	{
		if (isEmpty())
			front = rear = new chainNode<T>(e, 0);
		else
		{
			rear->link = new chainNode<T>(e, 0);
			rear = rear->link;
		}

		return *this;
	}

	void Pop()
	{
		if (isEmpty())
			cout << "Nothing left to be popped." << endl;
		else
		{
			chainNode<T>*delNode = front;
			front = front->link;
			delete delNode;
		}
	}

	void print()
	{
		chainNode<T> *current = front;
		if (isEmpty())
			cout << "An empty linkedQueue is here."
			<< endl;
		while (current != 0)
		{
			cout << setw(4) << current->data;
			current = current->link;
		}
	}

private:
	chainNode<T> *front;
	chainNode<T> *rear;
};
#endif
