#pragma once
#include "Queue.hpp"
#include <math.h>
using namespace std;

template <class T>
class BinaryTree;

template <class T>
class BinaryTreeNode
{
private:
	T data;

	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;

	friend class BinaryTree<T>;

	BinaryTreeNode() {}
	BinaryTreeNode(T Data)
	{
		data = Data;
		leftChild = NULL;
		rightChild = NULL;
	}
};

template <class T>
class BinaryTree
{
private:
	long NodeNum;
	BinaryTreeNode<T> *newNode(T data);
	void addNode(BinaryTreeNode<T> *&p);

public:
	BinaryTreeNode<T> *root;

	BinaryTree();
	BinaryTree(T data);
	void buildBinaryTree();					  //前序递归建立二叉树
	int getDepth(BinaryTreeNode<T> *p);		  //求树深度
	void preTraversal(BinaryTreeNode<T> *p);  //前序遍历
	void inTraversal(BinaryTreeNode<T> *p);   //中序遍历
	void postTraversal(BinaryTreeNode<T> *p); //后序遍历
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
BinaryTreeNode<T> *BinaryTree<T>::newNode(T data)
{
	return new BinaryTreeNode<T>(data);
}

template <class T>
void BinaryTree<T>::addNode(BinaryTreeNode<T> *&p)
{
	T data;

	cin >> data;	 //本用例中使用cin输入数据，可根据情况修改不同数据源
	if (data == '*') //标记空指针
		return;

	p = newNode(data);
	NodeNum++;
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
		NodeNum++;
	}

	addNode(root->leftChild);
	addNode(root->rightChild);
}

template <class T>
int BinaryTree<T>::getDepth(BinaryTreeNode<T> *p)
{
	if (!p)
		return 0;

	int a = getDepth(p->leftChild);
	int b = getDepth(p->rightChild);

	return ((a > b) ? a : b) + 1;
}

template <class T>
void BinaryTree<T>::preTraversal(BinaryTreeNode<T> *p)
{
	if (!p)
		return;

	//对当前节点操作
	cout << p->data << "  " << endl;

	preTraversal(p->leftChild);
	preTraversal(p->rightChild);
}

template <class T>
void BinaryTree<T>::inTraversal(BinaryTreeNode<T> *p)
{
	if (!p)
		return;

	inTraversal(p->leftChild);

	//对当前节点操作
	cout << p->data << "  " << endl;

	inTraversal(p->rightChild);
}

template <class T>
void BinaryTree<T>::postTraversal(BinaryTreeNode<T> *p)
{
	if (!p)
		return;

	postTraversal(p->leftChild);
	postTraversal(p->rightChild);

	//对当前节点操作
	cout << p->data << "  " << endl;
}