#pragma once
#ifndef DBLLIST_H
#define DBLLIST_H

#include<iostream>
#include<iomanip>
using namespace std;

class DblListNode
{
	friend class DblList;
public:
	DblListNode(int d = 0)
	{
		data = d;
	}
private:
	int data;
	DblListNode *left;
	DblListNode *right;
};

class DblList
{
public:
	DblList()
	{
		first = new DblListNode();
		first->left = first;
		first->right = first;
	}

	void Insert(DblListNode *p, DblListNode *x)
	{
		p->left = x;
		p->right = x->right;

		x->right->left = p;
		x->right = p;
	}

	void Delete(DblListNode*x)
	{
		if (x == first) throw"Deletion of header node nor permitted";
		else
		{
			x->left->right = x->right;
			x->right->left = x->left;
			delete x;
		}
	}

	void print()
	{
		DblListNode* current = first->right;
		while (current != first)
		{
			cout << setw(4) << current->data;
			current = current->right;
		}
	}

	DblListNode* getFirst()
	{
		return first;
	}

	DblListNode* getLast()
	{
		return first->left;
	}

	void Concatenate(DblList m)
	{
		m.getFirst()->right->left = this->getLast();
		m.getLast()->right = this->getFirst();
		this->getLast()->right = m.getFirst()->right;
		this->getFirst()->left = m.getFirst()->left;
		m.getFirst()->right = m.getFirst();
		m.getFirst()->left = m.getFirst();
	}

private:
	DblListNode * first;
};
#endif
