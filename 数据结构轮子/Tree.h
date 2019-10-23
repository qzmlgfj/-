#pragma once
#include<iostream>
using namespace std;

extern int result;

template<class T>
void Func(T data);

template <class T>
class BinaryTreeNode
{
private:
	T data;
	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;
template <class T>
friend class BinaryTree;
};

template <class T>
class BinaryTree
{
private:
	long NodeNum;
public:
	BinaryTreeNode<T> *root;

	BinaryTree();
	BinaryTree(T data);
	//~BinaryTree();
	BinaryTreeNode<T>* newNode(T data);
	void addNode(BinaryTreeNode<T>*& p);
	void buildBinaryTree();
	void preTraversal(BinaryTreeNode<T> *p);
	void inTraversal(BinaryTreeNode<T> *p);
	void postTraversal(BinaryTreeNode<T> *p);
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
	NodeNum = 0;
}

template <class T>
BinaryTree<T>::BinaryTree(T data)
{
	root = newNode(data);
	NodeNum = 1;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::newNode(T data)
{
	BinaryTreeNode<T> *p = new BinaryTreeNode<T>;
	p->data = data;
	p->leftChild = NULL;
	p->rightChild = NULL;

	return p;
}

template <class T>
void BinaryTree<T>::addNode(BinaryTreeNode<T> *&p)
{
	T data;

	cin >> data;
	if (data == '*')		//标记空指针
		return;

	p = newNode(data);
	addNode(p->leftChild);
	addNode(p->rightChild);
}

template <class T>
void BinaryTree<T>::buildBinaryTree()
{
	T data;

	if (!root)
	{
		cin >> data;
		root = newNode(data);
	}

	addNode(root->leftChild);
	addNode(root->rightChild);
}

template <class T>
void BinaryTree<T>::preTraversal(BinaryTreeNode<T> *p)		
{
	if (!p)
		return;

	//对目前结点的操作
	cout << p->data << ' ';

	preTraversal(p->leftChild);
	preTraversal(p->rightChild);
}

template <class T>
void BinaryTree<T>::inTraversal(BinaryTreeNode<T> *p)
{
	if (!p)
		return;

	inTraversal(p->leftChild);

	//对目前结点的操作
	cout << p->data << ' ';

	inTraversal(p->rightChild);
}

template <class T>
void BinaryTree<T>::postTraversal(BinaryTreeNode<T> *p)
{
	if (!p)
		return;

	postTraversal(p->leftChild);
	postTraversal(p->rightChild);

	//对目前结点的操作
	cout << p->data << ' ';
}

/*
template<class T>
void Func(T data,T target)
{
	if(data==target)
		result
}
*/