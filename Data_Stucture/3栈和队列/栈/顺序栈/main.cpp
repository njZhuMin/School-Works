#include <stdio.h>
#include "SeqStack.cpp"

int main()
{
	int a[10];
	SeqStack<int,20> S1;
	//1~10压栈
	for(int i=0; i<10; i++)
	{
		a[i] = i;
		S1.Push(a[i]);
	}
	//9~5出栈
	for(int i=0; i<5; i++)
	{
		cout<<S1.Pop()<<endl;
	}
	return 0;
}
