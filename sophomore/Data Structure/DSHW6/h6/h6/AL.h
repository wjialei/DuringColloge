#pragma once
#ifndef AL_H
#define AL_H


#include <iostream>
using namespace std;

class adjList;
class Node {
	friend class adjList;
public:
	Node() {}
	Node(int d, Node * n = NULL) {
		data = d;
		next = n;
	}
	int getData() {
		return data;
	}
	Node *next;
private:
	int data;

};

class adjList {
	friend ostream &operator<<(ostream &out, adjList& list);
public:
	adjList() {
		first = last = NULL;
		length = 0;
	}

	void add(int v) {
		++length;
		Node *node = new Node(v);
		if (first == NULL) {
			first = last = node;
		}
		else {
			last = last->next = node;
		}
	}


private:
	int length;
	Node *first;
	Node* last;
};

ostream &operator<<(ostream &out, adjList& list) {
	cout << "the vector " << list.first->getData() << ":";
	Node* current = list.first->next;
	while (current) {
		cout << current->getData() << " ";
		current = current->next;
	}
	cout << endl;

	return out;
}

void input() {
	int vNum, eNum;
	cout << "please input the num of vectors and edges:";
	cin >> vNum >> eNum;
	adjList *list = new adjList[vNum];
	for (int i = 0; i < vNum; ++i)
		list[i].add(i);
	for (int i = 0; i < eNum; ++i) {
		int v1, v2;
		cout << "input 2 vectors:";
		cin >> v1 >> v2;
		list[v1].add(v2);
		list[v2].add(v1);
	}

	for (int i = 0; i < vNum; ++i)
		cout << list[i];
}
#endif