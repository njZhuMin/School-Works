#include <iostream>
#include "SeqList.cpp"
using namespace std;

int main()		//SeqList测试
{
	//赋值
	int a[10];
	for(int i=0; i<10; i++){
		a[i] = i;
	}
	SeqList<int,20> array(a,10);
	array.PrintSeqList();
	cout<<endl;
	int s = 0;
	s=array.Locate(7);
	cout<<s<<endl;
	cout<<endl;
	array.Insert(3,8);
	array.PrintSeqList();
	cout<<endl;
	array.Delete(7);
	array.PrintSeqList();
	return 0;
}
