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

	Node<T> *Create_Node() //����һ��Node�ڴ�
	{
		Node<T> *p = new Node<T>;
		p->next = NULL;
		p->prev = NULL;

		return p;
	}

public:
	Node<T> *head, *end;
	int total;

	List();					 //����һ��ͷ�ڵ�
	void Delete(Node<T> *p); //ɾ��N���ڵ�
	void AddNode(T a);		 //��ĩβ��ӽڵ�
	Node<T> *getMin();		 //������С�ڵ㲢�Ƴ�����
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
void List<T>::AddNode(T a) //��β�����endָ����ƶ���ؼ����
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