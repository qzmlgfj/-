#include "Stack.h"

int main()
{
	Stack<int> stack;

	for (int i = 0; i < 10; i++)
		stack.Push(i);

	for (int i = 0; i < 10; i++)
		cout << stack.Pop() << "  ";

	cout << endl;

	system("PAUSE");
	return 0;
}