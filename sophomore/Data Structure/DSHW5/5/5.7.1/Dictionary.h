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
	// 构造函数
	Dictionary()
	{
		root = 0;
	}
	// 计算树高
	int height(TreeNode<Pair<K, E>>*father, int h)
	{
		int h1 = 0;
		int h2 = 0;
		// 返回左子树的高度
		if (father->leftChild)
			h1 = height(father->leftChild, h);
		// 返回右子树的高度
		if (father->rightChild)
			h2 = height(father->rightChild, h);
		// 返回自自身的高度
		return  (h1 > h2 ? h1 : h2) + 1;
	}
	// 生成随机树
	void randomTree(int n)
	{
		srand((unsigned)time(NULL));
		for (size_t i = 0; i < n; i++)
		{
			Pair<K, E> pair(rand(), rand() / 2);
			insert(pair);
		}
	}
	// 构建一棵树
	void insert(Pair<K, E> pair)
	{
		TreeNode<Pair<K, E>>* p = root;
		TreeNode<Pair<K, E>>* pp = 0;
		// 寻找合适的位置
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
		// 插入新节点
		p = new TreeNode<Pair<K, E>>(0, 0, pair);

		if (root) // tree not empty
			if (pair.first < pp->data.first) pp->leftChild = p;
			else pp->rightChild = p;
		else root = p;
	}
	// 删除节点
	bool del(K k)
	{
		TreeNode<Pair<K, E>>* p = root;
		TreeNode<Pair<K, E>>* pp = 0;
		TreeNode<Pair<K, E>>* ppp = 0;// 记录p的父节点

	 // 寻找k的位置
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
			// 删除该节点
			if (pp->leftChild)
			{
				TreeNode<Pair<K, E>>*temp = getMaxNode(pp->leftChild);
				pp->data = temp->data;
				return true;
			}
			// 如果没有左节点，则删除右节点
			if (pp->rightChild)
			{
				TreeNode<Pair<K, E>>*temp = getMinNode(pp->rightChild);
				pp->data = temp->data;
				return true;
			}
			// 如果左右都没有那么直接删除这一个节点
			if (ppp)
				if (ppp->leftChild == pp)
					ppp->leftChild = 0;
				else
					ppp->rightChild = 0;
			delete pp;
			pp = NULL;
		}
	}
	// 删除
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
	// 最大节点
	TreeNode<Pair<K, E>>* getMaxNode(TreeNode<Pair<K, E>>* root)
	{
		TreeNode<Pair<K, E>>* temp = root;
		while (temp->rightChild)
			temp = temp->rightChild;
		return temp;
	}
	// 最小节点
	TreeNode<Pair<K, E>>* getMinNode(TreeNode<Pair<K, E>>* root)
	{
		TreeNode<Pair<K, E>>* temp = root;
		while (temp->leftChild)
			temp = temp->leftChild;
		return temp;
	}
	// 递归删除节点的函数
	void recurDel(TreeNode< Pair<K, E>>* p)
	{
		// 删除左子树
		if (p->leftChild)
		{
			recurDel(p->leftChild);
			p->leftChild = NULL;
		}
		// 删除右子树
		if (p->rightChild)
		{
			recurDel(p->rightChild);
			p->rightChild = NULL;
		}
		// 如果是root节点 就特殊处理一下
		if (p == root)
		{
			delete p;
			root = NULL;
		}
		else
			delete p;
	}
	// 中序遍历
	void inorder(TreeNode<Pair<K, E>>* current)
	{
		if (current)
		{
			inorder(current->leftChild);
			cout << current->data.first << " ";
			inorder(current->rightChild);
		}
	}
	// 获取根节点
	TreeNode<Pair<K, E>>* getRoot() { return root; }
private:
	TreeNode<Pair<K, E>>*root;
};
#endif
