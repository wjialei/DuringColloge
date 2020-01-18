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
	{ // 先序递归创建二叉树  
		char ch;
		cin >> ch;
		if (ch == '#')
		{
			T = NULL;
		}
		else
		{
			T = new TreeNode<char>(ch); // 产生新的子树  
			CreatBiTree(T->leftChild); // 递归创建左子树  
			CreatBiTree(T->rightChild); // 递归创建右子树  
		}
	}

	// 迭代器
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

	//非递归前序遍历
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
