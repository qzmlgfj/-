#pragma once
#include<iostream>
#define EmptyTOS -1

using namespace std;

template <class T>
class Stack
{
private:
	int Capacity;
	int TopOfStack;
	T* Array;
public:
	Stack();			//默认实例化
	Stack(int n);		//实例化指定容量
	int IsFull();
	int IsEmpty();
	void Push(T elem);
	T Pop();
	T Top();
};

template <class T>
Stack<T>::Stack()
{
	Capacity = 10;
	Array = new T[Capacity];
	TopOfStack = EmptyTOS;
}

template <class T>
Stack<T>::Stack(int n)
{
	Capacity = n;
	Array = new T[Capacity];
	TopOfStack = EmptyTOS;
}

template <class T>
void Stack<T>::Push(T elem)
{
	if (IsFull())
	{
		cout << "Full Stack" << endl;	//Error Warning
		return;
	}
	else
	{
		Array[++TopOfStack] = elem;
		return;
	}
}

template <class T>
T Stack<T>::Pop()
{
	if (!IsEmpty())
		return Array[TopOfStack--];

	cout << "Empty Stack" << endl;		//Error Warning
	return 0;
}

template <class T>
T Stack<T>::Top()
{
	if (!IsEmpty())
		return Array[TopOfStack];

	cout << "Empty Stack" << endl;
	return 0;
}

template <class T>
int Stack<T>::IsFull()
{
	return TopOfStack == Capacity - 1;
}

template <class T>
int Stack<T>::IsEmpty()
{
	return TopOfStack == EmptyTOS;
}