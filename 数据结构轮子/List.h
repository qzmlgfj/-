#pragma once
#include <iostream>

template <class T>
class Node
{
private:
	T data;
	Node *next, *prev;
};

