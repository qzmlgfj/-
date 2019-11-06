#pragma once
#include "Queue.hpp"
#include <math.h>
using namespace std;

void drawLine(const char c, int x);

template <class T>
class BinaryTreeNode
{
private:
	T data;

	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;
	template <class T>
	friend class BinaryTree;

public:
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

public:
	BinaryTreeNode<T> *root;

	BinaryTree();
	BinaryTree(T data);
	BinaryTreeNode<T> *newNode(T data);
	void addNode(BinaryTreeNode<T> *&p);
	void buildBinaryTree();				//ǰ��ݹ齨��������
	void treeGraphView();				//һ�����ӻ�������Ŀǰ�����õ��ַ���������
	int getDepth(BinaryTreeNode<T> *p); //�������
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
void BinaryTree<T>::treeGraphView()
{
	if (!root) //����ֱ�ӷ���
		return;

	int k = 1;					//������ָʾ
	int i = 1;					//���ֵܷ���ָʾ
	int Depth = getDepth(root); //��������
	int Offset;					//��ƫ����ָʾ
	int lineOffset;				//��ǹ��ƫ����

	if (Depth == 1) //ֻ�и��ڵ�ֱ�����������
	{
		cout << root->data << endl;
		return;
	}

	int Width = 8 * pow(2, Depth - 2) - 3; //������������ͼ���

	Queue<BinaryTreeNode<T> *> queue(NodeNum);
	Queue<int> parentqueue(30), thisqueue(30);
	queue.EnQueue(root);
	thisqueue.EnQueue(Width / 2 + 1);

	BinaryTreeNode<T> *p;

	while (!queue.IsEmpty())
	{
		p = queue.Dequeue();

		if (!p) //���У����������ߵĻ���
		{
			if (queue.IsEmpty())
			{
				cout << endl;
				break;
			}

			cout << endl;
			k++;
			i = 1;
			lineOffset = 1;

			int parentOffset; //��Ǹ��ڵ�ƫ����

			parentOffset = parentqueue.Dequeue();
			Offset = thisqueue.Dequeue();
			thisqueue.EnQueue(-1);
			thisqueue.EnQueue(Offset);

			int isSame = 0; //����Ƿ�����ֵܽ��

			while (1)
			{
				if (abs(Offset - parentOffset) > (Width / pow(2, k) + 1)) //���ȶ�ʧ�ܣ���ȡ��һ�����ڵ�ƫ����
				{
					parentOffset = parentqueue.Dequeue();
					isSame = 0;
					continue;
				}

				if (Offset - parentOffset < 0) //�ý��Ϊ���ӽڵ�
				{
					drawLine(' ', Offset - lineOffset);
					drawLine('_', parentOffset - Offset);
					drawLine('|', 1);
					isSame = 1;

					lineOffset = parentOffset + 1;
				}
				else //�ý��Ϊ���ӽڵ�
				{
					drawLine(' ', parentOffset - lineOffset);
					if (!isSame)
						drawLine('|', 1);
					drawLine('_', Offset - parentOffset);

					lineOffset = Offset + 1;
				}

				Offset = thisqueue.Dequeue(); //ȡ��һƫ����
				if (Offset == -1)			  //�ò�������
					break;
				thisqueue.EnQueue(Offset);
			}

			cout << endl;
			lineOffset = 1; //����һ�У����ƫ������1

			Offset = thisqueue.Dequeue();
			thisqueue.EnQueue(-1);
			thisqueue.EnQueue(Offset);

			isSame = 0;

			while (1)
			{
				if (!isSame)
				{
					drawLine(' ', Offset - lineOffset);
					isSame = 1;
				}
				else
					drawLine(' ', Offset - lineOffset);
				drawLine('|', 1);
				lineOffset = Offset + 1;

				Offset = thisqueue.Dequeue();
				if (Offset == -1)
					break;
				thisqueue.EnQueue(Offset);
			}

			cout << endl;

			//k++;
			continue;
		}

		if (i == 1)
		{
			queue.EnQueue(NULL); //��Ϊ�׸���㣬�򽫿�ָ����������б��
			lineOffset = 1;
		}

		Offset = thisqueue.Dequeue(); //ȡ�øýڵ�ƫ����
		parentqueue.EnQueue(Offset);  //��ƫ�������븸�ڵ�ƫ��������

		drawLine(' ', Offset - lineOffset);
		lineOffset = Offset + 1;
		cout << p->data;

		if (p->leftChild)
		{
			queue.EnQueue(p->leftChild);
			thisqueue.EnQueue(Offset - ((int)(Width / pow(2, k + 1)) + 1)); //���ӽڵ�ƫ��������ƫ��������
		}

		if (p->rightChild)
		{
			queue.EnQueue(p->rightChild);
			thisqueue.EnQueue(Offset + ((int)(Width / pow(2, k + 1)) + 1));
		}

		i++;
	}
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

void drawLine(const char c, int x)
{
	for (int i = 1; i <= x; i++)
		cout << c;
}

template <class T>
void BinaryTree<T>::preTraversal(BinaryTreeNode<T> *p)
{
	if(!p)
	return;

	//�Ե�ǰ�ڵ����
	cout<<p->data<<"  "<<endl;

	preTraversal(p->leftChild);
	preTraversal(p->rightChild);
}

template <class T>
void BinaryTree<T>::inTraversal(BinaryTreeNode<T> *p)
{
	if(!p)
	return;

	inTraversal(p->leftChild);

	//�Ե�ǰ�ڵ����
	cout<<p->data<<"  "<<endl;

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
	cout<<p->data<<"  "<<endl;
}