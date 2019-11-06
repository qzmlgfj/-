#pragma once
#include<iostream>
using namespace std;

template <class T>
class Queue
{
private:
	int Capacity;
	int Front;
	int Rear;
	int Size;
	T	*Array;
public:
	Queue(int n = 10)				//默认参数实例化
	{
		Capacity = n;
		Size = 0;
		Rear = -1;
		Front = 0;
		Array = new T[Capacity];
	}

	~Queue()
	{
		delete[]Array;
	}

	int IsEmpty()
	{
		return Size == 0;
	}

	int IsFull()
	{
		return Size == Capacity;
	}

	void EnQueue(T x)
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

	T Dequeue()
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

	T GetFront()
	{
		return Array[Front];
	}

	void AllDequeue()				//全部出队
	{
		while (!IsEmpty())
			Dequeue();
	}
};
