#pragma once
#include<iostream>
using namespace std;

template <class T>
class TreeNode
{
private:
	T data;
	TreeNode *leftChild;
	TreeNode *rightChild;
public:

	void preTraversal(TreeNode *p);
	void inTraversal(TreeNode *p);
	void postTraversal(TreeNode *p);
};

template <class T>
void TreeNode<T>::preTraversal(TreeNode *p)
{
	if (!p)
		return;

	//对目前结点的操作

	preTraversal(leftChild);
	preTraversal(rightChild);
}

template <class T>
void TreeNode<T>::inTraversal(TreeNode *p)
{
	if (!p)
		return;

	inTraversal(leftChild);

	//对目前结点的操作

	inTraversal(rightChild);
}

template <class T>
void TreeNode<T>::postTraversal(TreeNode *p)
{
	if (!p)
		return;

	postTraversal(leftChild);
	postTraversal(rightChild);

	//对目前结点的操作
}