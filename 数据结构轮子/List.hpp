#pragma once
#include <iostream>

template <class T>
class Node
{
public:
	T data;
	Node *next, *prev;
};

template <class T>
class List
{
private:
	Node<T> *now;

	Node<T> *Create_Node() //申请一块Node内存
	{
		Node<T> *p = new Node<T>;
		p->next = NULL;
		p->prev = NULL;

		return p;
	}

public:
	Node<T> *head, *end;
	int total;

	List();					 //构造一个头节点
	void Delete(Node<T> *p); //删除N处节点
	void AddNode(T a);		 //在末尾添加节点
	Node<T> *getMin();		 //返回最小节点并移出链表
};

template <class T>
List<T>::List()
{
	head = Create_Node();

	now = head;
	end = head;

	total = 0;
}

template <class T>
void List<T>::Delete(Node<T> *p)
{
	now = p;
	if (!p->next)
	{
		end = now->prev;
		now->prev->next = now->next;
	}

	else
	{
		(now->next)->prev = now->prev;
		(now->prev)->next = now->next;
	}
	total--;
}

template <class T>
void List<T>::AddNode(T a) //多次操作后end指针的移动有丶问题
{
	end->next = Create_Node();
	now = end->next;

	now->data = a;
	now->prev = end;

	end = now;
	total++;
}

template <class T>
Node<T> *List<T>::getMin()
{
	if (head == end)
		return NULL;

	Node<T> *p = head->next;

	for (now = head->next; now != NULL; now = now->next)
	{
		if (p->data->weight > now->data->weight)
			p = now;
	}

	Delete(p);

	return p;
}