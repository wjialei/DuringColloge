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
		//当满额将容量翻倍
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

	//分成两个栈
	Stack halve()
	{
		int sum;
		sum = top + 1;
		int halfCut = sum / 2;//直接对于sum为单数的情况取整
							//不过多纠结两个栈多一个少一个的问题

		//定义一个栈用于储存上端元素
		Stack half(halfCut);
		for (int i = 0; i <= halfCut - 1; i++)
		{
			half.push(stack[halfCut]);
		}

		//剩下的元素就是另一半
		//不用再次定义
		for (int i = 0; i < halfCut; i++)
			this->pop();
		return half;
	}

	//合成
	Stack compose(Stack s)
	{
		//先创建一个足够大的数组
		//储存合成后的栈元素
		int sumSize = s.capacity + capacity;
		Stack sum(sumSize);

		//将第一个栈的元素压在底部
		for (int i = 0; i <= top; i++)
			sum.push(stack[i]);
		//第二个栈元素置于顶端
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
