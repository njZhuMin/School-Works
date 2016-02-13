#include <stdio.h>
#include "LinkList.cpp"

int main()
{
	int a[10];
	for (int i=0; i<10; i++)
	{
		a[i] = i;
	}
	int b[10];
	for (int i=0; i<10; i++)
	{
		a[i] = 2*i;
	}
	LinkList<int> L1(a,20);
	LinkList<int> L2(b,10);
	L1.Merge(L2);
	L1.PrintLinkList();
	/*cout<<"Print all list:"<<endl;
	L1.PrintLinkList();
	cout<<"Get length:"<<endl;
	cout<<L1.ListLength()<<endl;
	cout<<"Get position 3:"<<endl;
	int s = L1.Get(3);
	cout<<s<<endl;
	cout<<"Find value 8:"<<endl;
	cout<<L1.Locate(8)<<endl;
	cout<<"Insert and delete:"<<endl;
	L1.Insert(2,13);
	L1.Delete(5);
	L1.PrintLinkList();
	cout<<"Invert:"<<endl;
	L1.Invert();
	L1.PrintLinkList();*/
	return 0;
}
