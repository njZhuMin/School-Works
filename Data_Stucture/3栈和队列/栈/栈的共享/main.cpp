#include <stdio.h>
#include "BothStack.cpp"

int main()
{
	int a[10],b[10];
	BothStack<int,30> B;
	//0~18压栈1
	for(int k=0; k<10; k++)
	{
		a[k] = k;
		B.Push(1,a[k]);
	}
	//1~19压栈2
	for(int k=0; k<10; k++)
	{
		b[k] = 2*k;
		B.Push(2,b[k]);
	}
	//9~5出栈1
	cout << "Pop 5 from Stack2:" << endl;
	for(int i=0; i<5; i++)
	{
		cout<<B.Pop(1)<<endl;
	}
	//18~14出栈1
	cout << "Pop 3 from Stack2:" << endl;
	for(int i=0; i<3; i++)
	{
		cout<<B.Pop(2)<<endl;
	}
	cout<<"Get top:"<<endl;
	cout<<B.GetTop(1)<<endl;
	cout<<B.GetTop(2)<<endl;
	return 0;
}
