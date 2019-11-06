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
	void buildBinaryTree();				//前序递归建立二叉树
	void treeGraphView();				//一个可视化函数（目前仅适用单字符二叉树）
	int getDepth(BinaryTreeNode<T> *p); //求树深度
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
void BinaryTree<T>::treeGraphView()
{
	if (!root) //空树直接返回
		return;

	int k = 1;					//作层数指示
	int i = 1;					//作兄弟方向指示
	int Depth = getDepth(root); //求得树深度
	int Offset;					//作偏移量指示
	int lineOffset;				//标记光标偏移量

	if (Depth == 1) //只有根节点直接输出并返回
	{
		cout << root->data << endl;
		return;
	}

	int Width = 8 * pow(2, Depth - 2) - 3; //根据深度求得视图宽度

	Queue<BinaryTreeNode<T> *> queue(NodeNum);
	Queue<int> parentqueue(30), thisqueue(30);
	queue.EnQueue(root);
	thisqueue.EnQueue(Width / 2 + 1);

	BinaryTreeNode<T> *p;

	while (!queue.IsEmpty())
	{
		p = queue.Dequeue();

		if (!p) //换行，进行连接线的绘制
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

			int parentOffset; //标记父节点偏移量

			parentOffset = parentqueue.Dequeue();
			Offset = thisqueue.Dequeue();
			thisqueue.EnQueue(-1);
			thisqueue.EnQueue(Offset);

			int isSame = 0; //标记是否存在兄弟结点

			while (1)
			{
				if (abs(Offset - parentOffset) > (Width / pow(2, k) + 1)) //若比对失败，则取下一个父节点偏移量
				{
					parentOffset = parentqueue.Dequeue();
					isSame = 0;
					continue;
				}

				if (Offset - parentOffset < 0) //该结点为左子节点
				{
					drawLine(' ', Offset - lineOffset);
					drawLine('_', parentOffset - Offset);
					drawLine('|', 1);
					isSame = 1;

					lineOffset = parentOffset + 1;
				}
				else //该结点为右子节点
				{
					drawLine(' ', parentOffset - lineOffset);
					if (!isSame)
						drawLine('|', 1);
					drawLine('_', Offset - parentOffset);

					lineOffset = Offset + 1;
				}

				Offset = thisqueue.Dequeue(); //取下一偏移量
				if (Offset == -1)			  //该层操作完成
					break;
				thisqueue.EnQueue(Offset);
			}

			cout << endl;
			lineOffset = 1; //另起一行，光标偏移量归1

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
			queue.EnQueue(NULL); //若为首个结点，则将空指针入队作换行标记
			lineOffset = 1;
		}

		Offset = thisqueue.Dequeue(); //取得该节点偏移量
		parentqueue.EnQueue(Offset);  //将偏移量存入父节点偏移量队列

		drawLine(' ', Offset - lineOffset);
		lineOffset = Offset + 1;
		cout << p->data;

		if (p->leftChild)
		{
			queue.EnQueue(p->leftChild);
			thisqueue.EnQueue(Offset - ((int)(Width / pow(2, k + 1)) + 1)); //将子节点偏移量存入偏移量队列
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

	//对当前节点操作
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

	//对当前节点操作
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

	//对当前节点操作
	cout<<p->data<<"  "<<endl;
}