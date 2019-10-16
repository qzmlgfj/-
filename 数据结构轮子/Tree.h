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

	//��Ŀǰ���Ĳ���

	preTraversal(leftChild);
	preTraversal(rightChild);
}

template <class T>
void TreeNode<T>::inTraversal(TreeNode *p)
{
	if (!p)
		return;

	inTraversal(leftChild);

	//��Ŀǰ���Ĳ���

	inTraversal(rightChild);
}

template <class T>
void TreeNode<T>::postTraversal(TreeNode *p)
{
	if (!p)
		return;

	postTraversal(leftChild);
	postTraversal(rightChild);

	//��Ŀǰ���Ĳ���
}