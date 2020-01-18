#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;
template <class K, class E>class Dictionary;

template< class T>
class TreeNode
{
	friend class Dictionary< class K, class E >;
public:
	TreeNode(TreeNode<T>*l, TreeNode<T>*r, T d)
	{
		leftChild = l;
		rightChild = r;
		data = d;
	}

	T data;
	TreeNode<T>*leftChild;
	TreeNode<T>*rightChild;
};

template<typename K, typename E>
class Pair
{
public:
	Pair(int k = 50, int e = 10)
	{
		first = k;
		second = e;
	}
	int first;
	int second;
};

template <class K, class E>
class Dictionary
{
public:
	// ���캯��
	Dictionary()
	{
		root = 0;
	}
	// ��������
	int height(TreeNode<Pair<K, E>>*father, int h)
	{
		int h1 = 0;
		int h2 = 0;
		// �����������ĸ߶�
		if (father->leftChild)
			h1 = height(father->leftChild, h);
		// �����������ĸ߶�
		if (father->rightChild)
			h2 = height(father->rightChild, h);
		// ����������ĸ߶�
		return  (h1 > h2 ? h1 : h2) + 1;
	}
	// ���������
	void randomTree(int n)
	{
		srand((unsigned)time(NULL));
		for (size_t i = 0; i < n; i++)
		{
			Pair<K, E> pair(rand(), rand() / 2);
			insert(pair);
		}
	}
	// ����һ����
	void insert(Pair<K, E> pair)
	{
		TreeNode<Pair<K, E>>* p = root;
		TreeNode<Pair<K, E>>* pp = 0;
		// Ѱ�Һ��ʵ�λ��
		while (p)
		{
			pp = p;
			if (p->data.first > pair.first)
				p = p->leftChild;
			else if (p->data.first < pair.first)
				p = p->rightChild;
			else
			{
				p->data.second = pair.second;
				return;
			}
		}
		// �����½ڵ�
		p = new TreeNode<Pair<K, E>>(0, 0, pair);

		if (root) // tree not empty
			if (pair.first < pp->data.first) pp->leftChild = p;
			else pp->rightChild = p;
		else root = p;
	}
	// ɾ���ڵ�
	bool del(K k)
	{
		TreeNode<Pair<K, E>>* p = root;
		TreeNode<Pair<K, E>>* pp = 0;
		TreeNode<Pair<K, E>>* ppp = 0;// ��¼p�ĸ��ڵ�

	 // Ѱ��k��λ��
		while (p)
		{
			if (p->data.first == k)
			{
				pp = p;
				break;
			}
			else if (p->data.first > k)
			{
				ppp = p;
				p = p->leftChild;
			}
			else
			{
				ppp = p;
				p = p->rightChild;
			}
		}
		if (pp == 0)
			return false;
		else
		{
			// ɾ���ýڵ�
			if (pp->leftChild)
			{
				TreeNode<Pair<K, E>>*temp = getMaxNode(pp->leftChild);
				pp->data = temp->data;
				return true;
			}
			// ���û����ڵ㣬��ɾ���ҽڵ�
			if (pp->rightChild)
			{
				TreeNode<Pair<K, E>>*temp = getMinNode(pp->rightChild);
				pp->data = temp->data;
				return true;
			}
			// ������Ҷ�û����ôֱ��ɾ����һ���ڵ�
			if (ppp)
				if (ppp->leftChild == pp)
					ppp->leftChild = 0;
				else
					ppp->rightChild = 0;
			delete pp;
			pp = NULL;
		}
	}
	// ɾ��
	void del(TreeNode<Pair<K, E>>* pp)
	{
		if (pp->leftChild)
		{
			TreeNode<Pair<K, E>>*temp = getMaxNode(pp->leftChild);
			pp->data = temp->data;
			return;
		}
		if (pp->rightChild)
		{
			TreeNode<Pair<K, E>>*temp = getMaxNode(pp->rightChild);
			pp->data = temp->data;
			return;
		}
	}
	// ���ڵ�
	TreeNode<Pair<K, E>>* getMaxNode(TreeNode<Pair<K, E>>* root)
	{
		TreeNode<Pair<K, E>>* temp = root;
		while (temp->rightChild)
			temp = temp->rightChild;
		return temp;
	}
	// ��С�ڵ�
	TreeNode<Pair<K, E>>* getMinNode(TreeNode<Pair<K, E>>* root)
	{
		TreeNode<Pair<K, E>>* temp = root;
		while (temp->leftChild)
			temp = temp->leftChild;
		return temp;
	}
	// �ݹ�ɾ���ڵ�ĺ���
	void recurDel(TreeNode< Pair<K, E>>* p)
	{
		// ɾ��������
		if (p->leftChild)
		{
			recurDel(p->leftChild);
			p->leftChild = NULL;
		}
		// ɾ��������
		if (p->rightChild)
		{
			recurDel(p->rightChild);
			p->rightChild = NULL;
		}
		// �����root�ڵ� �����⴦��һ��
		if (p == root)
		{
			delete p;
			root = NULL;
		}
		else
			delete p;
	}
	// �������
	void inorder(TreeNode<Pair<K, E>>* current)
	{
		if (current)
		{
			inorder(current->leftChild);
			cout << current->data.first << " ";
			inorder(current->rightChild);
		}
	}
	// ��ȡ���ڵ�
	TreeNode<Pair<K, E>>* getRoot() { return root; }
private:
	TreeNode<Pair<K, E>>*root;
};
#endif
