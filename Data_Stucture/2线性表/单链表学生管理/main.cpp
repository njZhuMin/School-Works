#include <iostream>
#include "LinkList.cpp"
#include "Student.h"
using namespace std;
int main()
{
	Student s;
	LinkList<Student> L1;
	//插入
	int length = L1.ListLength();
	cout << "Insert student information: "<<endl;
	cin>>s;
	L1.Insert(length,s);
	L1.PrintLinkList();
	//删除
	int number1;
	int item1;
	cout << "Input student number to delete:" << endl;
	cin >> number1;
	item1 = L1.Locate(number1);
	if(item1 !=-1){
		L1.Delete(item1-1);
	} else {
		cout << "Not Found" << endl;
	}
	//查询
	cout << "Input student number to inquire:";
	int number2;
	int item2;
	cin >> number2;
	item2 = L1.Locate(number2);
	if(item2 !=-1){
		//cout << L1.Get(item2);
		Student s = L1.Get(item2);
		cout<<s;
	} else {
		cout << "Not Found" << endl;
	}
	cout << "Input student number to update: "<<endl;
	int tmp;
	cin >> tmp;
	int item = L1.Locate(tmp);
	if (item != -1)
	{
		cout << "Update student number: "<<endl;
		int num;
		cin >> num;
		L1.Get(item).setNumber(num);
	}
	return 0;
}
