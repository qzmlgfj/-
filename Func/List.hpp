#pragma once
#include <iostream>
using namespace std;

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
	void Delete(Node<T> *p); //ɾ��pָ��ڵ�
	void AddNode(T a);		 //��ĩβ��ӽڵ�
	void printList();		 //��ӡ���нڵ�����
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
void List<T>::AddNode(T a)
{
	end->next = Create_Node();
	now = end->next;

	now->data = a;
	now->prev = end;

	end = now;
	total++;
}

template <class T>
void List<T>::printList()
{
	now = head->next;

	while (now)
	{
		cout << now->data << ' ';
		now = now->next;
	}
	cout << endl;

	return;
}