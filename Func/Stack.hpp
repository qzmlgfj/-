#pragma once
#include <iostream>
#define EmptyTOS -1

using namespace std;

template <class T>
class Stack
{
private:
	int TopOfStack; //标记栈顶位置
	T *Array;		//元素数组
public:
	int Capacity;
	Stack(int n = 10); //实例化指定容量，默认10
	~Stack();
	int isFull();
	int isEmpty();
	void Push(T elem);
	T Pop();
	T getTop();	//返回栈顶元素
	T getBottom(); //返回栈底元素
	void Print();  //从底向上遍历输出
};

template <class T>
Stack<T>::Stack(int n)
{
	Capacity = n;
	Array = new T[Capacity];
	TopOfStack = EmptyTOS;
}

template <class T>
Stack<T>::~Stack()
{
	delete[] Array;
}

template <class T>
void Stack<T>::Push(T elem)
{
	if (isFull())
	{
		cout << "Full Stack" << endl; //Error Warning
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
	if (!isEmpty())
		return Array[TopOfStack--];

	cout << "Empty Stack" << endl; //Error Warning
	return 0;
}

template <class T>
T Stack<T>::getTop()
{
	if (!isEmpty())
		return Array[TopOfStack];

	cout << "Empty Stack" << endl;
	return 0;
}

template <class T>
int Stack<T>::isFull()
{
	return TopOfStack == Capacity - 1;
}

template <class T>
int Stack<T>::isEmpty()
{
	return TopOfStack == EmptyTOS;
}

template <class T>
void Stack<T>::Print()
{
	for (int i = 0; i < Capacity; i++)
		cout << Array[i] << " ";
	cout << endl;
}

template <class T>
T Stack<T>::getBottom()
{
	if (!isEmpty())
		return Array[0];

	cout << "Empty Stack" << endl;
	return 0;
}