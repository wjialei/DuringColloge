#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include"Stack.h"
#include"Queue.h"
using namespace std;

template<class T>
class Tree;

template <class T>
class TreeNode
{
	friend class Tree<T>;
public:
	TreeNode()
		:leftChild(NULL), rightChild(NULL), data(0)
	{  }

	TreeNode(T dat = 0, TreeNode<T>* left = NULL, TreeNode<T>* right = NULL)
	{
		data = dat;
		leftChild = left;
		rightChild = right;
	}

	// �������Һ��ӵĴ�С
	void setLeft(T l)
	{
		leftChild = new TreeNode<T>(l);
		//leftChild->data = l;
	}
	void setRight(T r)
	{
		rightChild = new TreeNode<T>(r);
		//rightChild->data = r;
	}

	// �������Һ��ӵ�getters
	TreeNode<T> * getLeft()
	{
		return leftChild;
	}
	TreeNode<T> * getRight()
	{
		return rightChild;
	}

	// ��������
	~TreeNode<T>() {
		delete[] leftChild;
		delete[] rightChild;
	}
private:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
};

template<class T>
class Tree
{
public:
	// default constructor
	Tree()
	{
		root = NULL;
	}
	// constructor
	Tree(T t)
	{
		root = new TreeNode<T>(t);
	}

	TreeNode<T> *getRoot()
	{
		return root;
	}

	// �������캯��
	Tree(Tree<T>&tree)
	{
		root = Copy(tree.root);
	}
	//COPY
	TreeNode<T>* Copy(TreeNode<T>* first)
	{
		if (!first) return 0;
		else
			return new TreeNode<T>(first->data, Copy(first->leftChild), Copy(first->rightChild));
	}
	Tree(Tree<T> btree1, T item, Tree<T> btree2)
	{
		root = new TreeNode<T>(item, btree1.root, btree2.root);
		delete btree1.root;
		delete btree2.root;
	}
	// ��������
	~Tree() {
		Delete(root);
	}
	void Delete(TreeNode<T>*currentNode) {
		if (currentNode) {
			Delete(currentNode->leftChild);
			Delete(currentNode->rightChild);
			delete currentNode;
		}
	}

	// ���ҽ���������Ϊ��ʱ����TRUE
	bool isEmpty()
	{
		return root == NULL;
	}


	// �������
	void Inorder()
	{
		Inorder(root);
	}
	void Inorder(TreeNode<T>*currentNode)
	{
		if (currentNode)
		{
			Inorder(currentNode->leftChild);
			cout << currentNode->data << " ";
			Inorder(currentNode->rightChild);
		}
	}
	// ǰ�����
	void Preorder()
	{
		Preorder(root);
	}
	void Preorder(TreeNode<T>*currentNode)
	{
		if (currentNode)
		{
			cout << currentNode->data << " ";
			Preorder(currentNode->leftChild);
			Preorder(currentNode->rightChild);
		}
	}
	// �������
	void Postorder()
	{
		Postorder(root);
	}
	void Postorder(TreeNode<T>*currentNode)
	{
		if (currentNode)
		{
			Postorder(currentNode->leftChild);
			Postorder(currentNode->rightChild);
			cout << currentNode->data << " ";
		}
	}
	// ��α���
	void Levelorder()
	{
		Queue<TreeNode<T>*> q;
		TreeNode<T> *currentNode = root;
		while (currentNode) {
			cout << currentNode->data << " ";
			if (currentNode->leftChild) q.Push(currentNode->leftChild);
			if (currentNode->rightChild) q.Push(currentNode->rightChild);
			if (q.isEmpty())
				return;
			currentNode = q.Front();
			q.Pop();
		}
	}

	// �ǵݹ�
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
	/*******************ǰ�������**********************/
	class PreorderIterator
	{
	public:
		PreorderIterator() { currentNode = root; }
		T *next()
		{
			while (currentNode) {
				s.Push(currentNode);
				T& temp = currentNode->data;
				currentNode = currentNode->leftChild;
				return temp;
			}
			if (s.isEmpty())
				return 0;
			currentNode = s.Top();
			s.pop();
			currentNode = currentNode->rightChild;
		}
	private:
		Stack<TreeNode<T>*> s;
		TreeNode<T> *currentNode;
	};
	/***************************************************/
	/*******************���������**********************/
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
	/***************************************************/

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

	int LeafNodeNum(TreeNode<T>*currentNode)
	{
		if (!currentNode)
			return 0;
		else if (!(currentNode->leftChild) && !(currentNode->rightChild))
			return 1;
		else
		{
			int leftNum = LeafNodeNum(currentNode->leftChild);
			int rightNum = LeafNodeNum(currentNode->rightChild);
			return leftNum + rightNum;
		}
	}

private:
	TreeNode<T> *root;
};
#endif







