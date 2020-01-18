#pragma once
/*
1.	将新节点作为的s的左孩子插入线索二叉树。
4.	实现一个函数按先序遍历二叉树。给出时间和空间复杂度。
	时间复杂度为O(n), 空间复杂度为O（1）。
*/


#include <iostream>
#include <stack>
using namespace std;

template<class Type>
class ThreadedNode {

	template<class Type> friend class ThreadedTree;

public:
	ThreadedNode(Type d) {
		data = d;
	}

private:
	Type data;
	ThreadedNode<Type>* leftChild, *rightChild;
	bool leftThread, rightThread;
};


template<class Type>
class ThreadedTree {
public:
	ThreadedTree() {
		root = NULL;
	}

	ThreadedTree(ThreadedNode<Type>* n) {
		root = n;
		root->leftThread = root->rightThread = true;
		root->leftChild = root->rightChild = root;

	}

	void InsertRight(ThreadedNode<Type>* s, ThreadedNode<Type>* r) {
		r->rightChild = s->rightChild;
		r->rightThread = s->rightThread;
		r->leftChild = s;
		r->leftThread = true;
		s->rightChild = r;
		s->rightThread = false;
		if (!r->rightThread) {
			ThreadedNode<Type>* cur = r->rightChild;
			while (!cur->leftThread)
				cur = cur->leftChild;

			cur->leftChild = r;
		}
	}


	void InsertLeft(ThreadedNode<Type>* s, ThreadedNode<Type>* l) {
		l->leftChild = s->leftChild;
		l->leftThread = s->leftThread;
		l->rightChild = s;
		l->rightThread = true;
		s->leftChild = l;
		s->leftThread = false;
		if (!l->leftThread) {
			ThreadedNode<Type>* cur = l->leftChild;
			while (!cur->rightThread)
				cur = cur->rightChild;

			cur->rightChild = l;
		}

	}

	void PreorderTraverse() {

		ThreadedNode<Type>* cur = root;
		do {
			while (!cur->leftThread) {
				visit(cur);
				cur = cur->leftChild;
			}
			cur = cur->rightChild->rightChild;

		} while (cur != root);
	}

	void visit(ThreadedNode<Type>* node) {
		cout << node->data << endl;
	}


private:
	ThreadedNode<Type>* root;

};
