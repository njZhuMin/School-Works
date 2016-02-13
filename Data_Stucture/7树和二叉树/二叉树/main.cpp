#include <iostream>
#include "BiTree.cpp"
#include "LinkQueue.cpp"

using namespace std;

int main()
{
	int i;
	vector<char> pre1;
	char prestr1[]="ABH**FD***E*CK**G**";
	for(i=0; i<19; i++)
	{
		pre1.push_back(prestr1[i]);
	}
	//先序构造
	BiTree<char> bt1(pre1);
	cout << "PreOrder:" << endl;
	bt1.PreOrder();
	cout << endl;
	
	//先序、中序构造
	vector<char> pre2;
	vector<char> mid;
	char prestr[]="ABHFDECKG";
	for(i=0; i<10; i++)
	{
		pre2.push_back(prestr[i]);
	}

	char midstr[]="HBDFAEKCG";
	for(i=0; i<10; i++)
	{
		mid.push_back(midstr[i]);
	}
	
	BiTree<char> bt2(pre2,mid);
	cout << "PreOrder:" << endl;
	bt2.PreOrder();
	cout << endl;
	
	cout << "MidOrder:" << endl;
	bt1.InOrder();
	cout << endl;
	cout << "PostOrder:";
	bt1.PostOrder();
	cout << endl;
	cout << "LevelOrder:";
	bt1.LevelOrder();
	cout << endl;

	cout << "The amount of nodes:" << bt1.Count() <<endl;
	cout << "The height of the tree:" << bt1.Height() << endl;
	
	return 0;
}
