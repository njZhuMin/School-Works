#include <stdio.h>
#include "LinkStack.cpp"

int main()
{
	int a[10];
	LinkStack<int> L1;
	//1~10压栈
	for(int i=0; i<10; i++)
	{
		a[i] = i;
		L1.Push(a[i]);
	}
	//9~5出栈
	for(int i=0; i<5; i++)
	{
		cout<<L1.Pop()<<endl;
	}
	return 0;
}
