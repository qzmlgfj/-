#pragma once
#include <iostream>
using namespace std;

/*
ʹ������ʵ��ѭ�����У�
ͨ��Size��Ƕ���Ԫ������
�ж϶ӿջ����
*/

template <class T>
class Queue
{
private:
	int Capacity; //����
	int Front;	//����
	int Rear;	 //��β
	int Size;	 //�ӳ�
	T *Array;	 //Ԫ������

public:
	Queue(int n = 10); //Ĭ�ϲ���ʵ����
	~Queue();
	int IsEmpty();
	int IsFull();
	void EnQueue(T x);
	T Dequeue();
	T GetFront();	  //���ض���Ԫ��
	void AllDequeue(); //ȫ������
};

template <class T>
Queue<T>::Queue(int n)
{
	Capacity = n;
	Size = 0;
	Rear = -1;
	Front = 0;
	Array = new T[Capacity];
}

template <class T>
Queue<T>::~Queue()
{
	delete[] Array;
}

template <class T>
int Queue<T>::IsEmpty()
{
	return Size == 0;
}

template <class T>
int Queue<T>::IsFull()
{
	return Size == Capacity;
}

template <class T>
void Queue<T>::EnQueue(T x)
{
	if (IsFull())
	{
		cout << "The Queue is Full" << endl;
		return;
	}

	Rear++;
	Rear = Rear % Capacity;

	Array[Rear] = x;
	Size++;
}

template <class T>
T Queue<T>::Dequeue()
{
	if (IsEmpty())
	{
		cout << "The Queue is Empty" << endl;
		return NULL;
	}

	T data = Array[Front];

	Front++;
	Front = Front % Capacity;

	Size--;

	return data;
}

template <class T>
T Queue<T>::GetFront()
{
	return Array[Front];
}

template <class T>
void Queue<T>::AllDequeue() //ȫ������
{
	while (!IsEmpty())
		Dequeue();
}