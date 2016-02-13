#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
using namespace std;

template <class T>
struct Node{
	T data;
	Node <T>* next;
};

template <class T>
class LinkList
{
private:
	Node<T>* head;					//单链表头指针
public:
	LinkList();						//建立带头结点的空链表
	LinkList(T a[], int n);			//建立n个元素单链表
	~LinkList();					//析构函数
	int ListLength();				//获取单链表长度
	T Get(int pos);					//按位查找，取单链表中第pos结点元素
	int Locate(T item);				//按值查找，求单链表中值为item的元素号
	int Locate(int item);			//按值查找，求单链表中值为item的元素号
	void PrintLinkList();			//遍历单链表，按序号依次输出各元素
	void Insert(int i, T item);		//在单链表中第i个位置插入元素为item结点
	T Delete(int i);				//在单链表中删除第i个结点
	void Invert();					//逆置单链表
	void Merge(LinkList<T> &L2);	//合并链表
};

#endif // LINKLIST_H
