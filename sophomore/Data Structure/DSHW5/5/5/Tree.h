#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "Stack.h"

using namespace std;
template <class T>class Tree;

template <class T>
class TreeNode
{
	friend class Tree<T>;
public:
	TreeNode(T dat = 0, TreeNode *left = NULL, TreeNode *right = NULL)
	{
		data = dat;
		leftChild = left;
		rightChild = right;
	}

private:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
};

template <class T>
class Tree
{
public:
	Tree()
	{
		root = NULL;
		CreatBiTree(root);
	}

	void CreatBiTree(TreeNode<T>* &T)
	{ // ����ݹ鴴��������  
		char ch;
		cin >> ch;
		if (ch == '#')
		{
			T = NULL;
		}
		else
		{
			T = new TreeNode<char>(ch); // �����µ�����  
			CreatBiTree(T->leftChild); // �ݹ鴴��������  
			CreatBiTree(T->rightChild); // �ݹ鴴��������  
		}
	}

	// ������
	class InorderIterator
	{
	public:
		InorderIterator(TreeNode <T> *root = 0)
		{
			currentNode = root;
		}
		T*next()
		{
			while (currentNode)
			{
				s.push(currentNode);
				currentNode = currentNode->leftChild;
			}
			if (s.isEmpty()) return 0;
			currentNode = s.Top();
			s.pop();
			T&temp = currentNode->data;
			currentNode = currentNode->rightChild;
			return &temp;
		}
	private:
		Stack<TreeNode<T>*>s;
		TreeNode<T> *currentNode;

	};
	/***********************************************/

	void InorderTraverse()
	{
		InorderIterator *It = new InorderIterator(root);
		T* t = It->next();
		while (t != 0)
		{
			cout << " " << *t;
			t = It->next();
		}
	}

	//�ǵݹ�ǰ�����
	void NonrecPreorder()
	{
		Stack<TreeNode<T>*> s;
		TreeNode<T> *currentNode = root;
		while (1) {
			while (currentNode) {
				cout << currentNode->data << " ";//visit
				s.push(currentNode);
				currentNode = currentNode->leftChild;
			}
			if (s.isEmpty())
				return;
			currentNode = s.Top();
			s.pop();
			currentNode = currentNode->rightChild;
		}
	}
private:
	TreeNode<T>* root;
};
#endif
