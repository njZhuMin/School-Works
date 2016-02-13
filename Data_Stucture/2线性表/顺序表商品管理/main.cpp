#include <iostream>
#include "SeqList.cpp"	//类模板实现须包含.CPP
#include "Goods.h"

using namespace std;

int main()
{
	Goods a[3];
	Goods new_goods(003,"CCC",20,10);
	SeqList<Goods,100> G1(a,3);
	/*ifstream fin("Goods");
	if (fin)
	{
		G1.Load("Goods");
	}*/
	for(int i=0 ; i<3 ;i++)
	{
		cout<<"Please input Goods"<<i+1<<endl;
		cin>>a[i];
		G1.Insert(i+1,a[i]);
	}
	//G1.Save("D:\Goods.txt");
	//打印顺序表
	cout<<"Print all Lists: \n"<<endl;
	G1.PrintSeqList();
	//更新顺序表
	cout<<"Update SeqList: \n"<<endl;
	//cout<<"Please input an item: \n"<<endl;
	//cin>>new_goods;
	G1.Update(new_goods);
	G1.PrintSeqList();
	//删除
	cout<<"Delete item new_goods: \n"<<endl;
	//G1.Delete(G1.Locate(new_goods));
	G1.PrintSeqList();
	//排序
	cout<<"Sort SeqList by ID number: \n"<<endl;
	G1.SortSeqList();
	G1.PrintSeqList();
	return 0;
}