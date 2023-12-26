#include "../shared/Queue.h"

#include <iostream>

using namespace std;

int main()
{
	int n = 7, k = 3; // set n and k to the desired values

	Queue<int> q(n + 1);
	q.SetDebugFlag(false);

	// 처음에 n명 추가 (1, 2, ..., n)
	for (int i = 1; i <= n; i++)
		q.Enqueue(i);
	q.Print();

	// 마지막 한 명이 남을 때까지 반복
	int i = 0;
	while (q.Size() != 1)
	{
		if (i == k)
		{
			cout << "Executed " << q.Front() << endl;
			q.Dequeue();
			i = 0;
		}
		else
		{
			q.Enqueue(q.Front());
			q.Dequeue();
			q.Print();
		}
		i++;
	}
	cout << "Survivor: " << q.Front() << endl;
	return 0;
}