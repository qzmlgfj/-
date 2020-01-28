#pragma once
#include <iostream>
using namespace std;

/*
使用数组实现循环队列，
通过Size标记队列元素数量
判断队空或队满
*/

template <class T>
class Queue
{
private:
	int Capacity; //容量
	int Front;	//队首
	int Rear;	 //队尾
	int Size;	 //队长
	T *Array;	 //元素数组

public:
	Queue(int n = 10); //默认参数实例化
	~Queue();
	int IsEmpty();
	int IsFull();
	void EnQueue(T x);
	T Dequeue();
	T GetFront();	  //返回队首元素
	void AllDequeue(); //全部出队
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
void Queue<T>::AllDequeue() //全部出队
{
	while (!IsEmpty())
		Dequeue();
}