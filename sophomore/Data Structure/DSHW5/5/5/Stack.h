#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

template<class T>
void changeSize(T* &a, const int oldSize, const int newSize)
{
	if (newSize < 0)
		throw "new size must be >0";

	T*temp = new T[newSize];
	int number = min(oldSize, newSize);
	copy(a, a + number, temp);
	delete[]a;
	a = temp;
}


template <class T>
class Stack
{
public:
	Stack(int stackCapacity = 10)
	{
		capacity = stackCapacity;
		if (capacity < 0)
			throw "stack capacity must be > 0";

		stack = new T[capacity];
		top = -1;
	}

	bool isEmpty()
	{
		return top == -1;
	}

	//inline 
	T& Top()
	{
		if (isEmpty())
			throw "Stack isempty";
		return stack[top];
	}

	void push(T &item)
	{
		//�������������
		if (top == capacity - 1) {
			changeSize(stack, capacity, capacity * 2);
			capacity *= 2;
		}
		stack[++top] = item;
	}

	void pop()
	{
		if (isEmpty())
			throw"Stack is empty, cannot pop again";
		stack[top--].~T();
	}

	void output()
	{
		if (isEmpty())
			throw"Stack is empty";
		for (int i = 0; i <= top; i++)
			cout << setw(5) << stack[i] << endl;
	}

	//�ֳ�����ջ
	Stack halve()
	{
		int sum;
		sum = top + 1;
		int halfCut = sum / 2;//ֱ�Ӷ���sumΪ���������ȡ��
							//�������������ջ��һ����һ��������

		//����һ��ջ���ڴ����϶�Ԫ��
		Stack half(halfCut);
		for (int i = 0; i <= halfCut - 1; i++)
		{
			half.push(stack[halfCut]);
		}

		//ʣ�µ�Ԫ�ؾ�����һ��
		//�����ٴζ���
		for (int i = 0; i < halfCut; i++)
			this->pop();
		return half;
	}

	//�ϳ�
	Stack compose(Stack s)
	{
		//�ȴ���һ���㹻�������
		//����ϳɺ��ջԪ��
		int sumSize = s.capacity + capacity;
		Stack sum(sumSize);

		//����һ��ջ��Ԫ��ѹ�ڵײ�
		for (int i = 0; i <= top; i++)
			sum.push(stack[i]);
		//�ڶ���ջԪ�����ڶ���
		for (int i = 0; i <= s.top; i++)
			sum.push(s.stack[i]);
		return sum;
	}


private:
	T *stack;
	int top;
	int capacity;
};

#endif
