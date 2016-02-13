#include "SeqQueue.cpp"
#include <iostream>
using namespace std;

int main()
{
	SeqQueue<int,10> S1;
	int a[20];
	for(int i = 0; i<20; i++)
	{
		a[i] = i;
		S1.EnQueue(a[i]);
	}
	for(int i = 0; i<10; i++)
	{
		S1.GetQueue();
		cout << S1.DeQueue() <<endl;
	}
	return 0;
}
