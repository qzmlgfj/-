#include "Queue.h"

int main()
{
	Queue<char> queue;
	char x;

	while (1)
	{
		cin >> x;

		if (x == '\n')
			continue;

		else
		{
			switch (x)
			{
			case '#':
				queue.Dequeue(); break;
			case '@':
				queue.AllDequeue(); break;
			default:
				queue.EnQueue(x);
			}
		}
	}

	system("PAUSE");
	return 0;
}