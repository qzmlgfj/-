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
	void buildBinaryTree();					  //ǰ��ݹ齨��������
	int getDepth(BinaryTreeNode<T> *p);		  //�������
	void preTraversal(BinaryTreeNode<T> *p);  //ǰ�����
	void inTraversal(BinaryTreeNode<T> *p);   //�������
	void postTraversal(BinaryTreeNode<T> *p); //�������
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

	cin >> data;	 //��������ʹ��cin�������ݣ��ɸ�������޸Ĳ�ͬ����Դ
	if (data == '*') //��ǿ�ָ��
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

	//�Ե�ǰ�ڵ����
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

	//�Ե�ǰ�ڵ����
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

	//�Ե�ǰ�ڵ����
	cout << p->data << "  " << endl;
}