#include "LinkList.h"
#include <stdlib.h>
using namespace std;

//无参构造函数
template <class T>
LinkList<T>::LinkList()
{
	head = new Node<T>*;
	head->next = NULL;
}

//有参构造函数
template <class T>
LinkList<T>::LinkList(T a[], int n)
{
	head = new Node <T>;				//生成头结点
	Node<T>* rear = head;				//指针rear指向当前单链表最后一个结点
	for (int i=0; i<n; i++){			//**尾插法**//为每个元素开辟新结点并插入链表尾部
		Node<T>* s = new Node <T>;
		s->data = a[i];					//指针s指向新结点
		rear->next = s;			
		rear = s;
	}
	rear->next = NULL;					//单链表建立完毕，尾结点指针域置空
}

//析构函数
template <class T>
LinkList<T>::~LinkList()
{
	Node<T>* p = head;	
	while(p){
		Node<T>* q = p;
		p = p->next;
		delete q;
	}
	//**防止野指针**
	head = NULL;
}

//获取链表长度
template <class T>
int LinkList<T>::ListLength()
{
	int num = 0;
	Node<T>* p = head->next;
	while(p){
		p = p->next;
		num++;
	}
	return num;
}

//按位查找
template <class T>
T LinkList<T>::Get(int pos)
{
	Node<T>* p =  head->next;
	int j = 1;		//p初始化第一个数据结点地址，j初始化为1
	while(p && j<pos){		//判断链表非空以及位置小于pos的合法性
		p = head->next;
		j++;
	}
	if(!p || j>pos){	//p为空，**或者pos小于j，如pos=0**
		cerr << "Invalid position!";
		exit(1);
	}
	else
		return p->data;
}

//按值查找
template <class T>
int LinkList<T>::Locate(T item)
{
	Node<T>* p =  head->next;
	int j = 1;
	while(p && (p->data != item))
	{
		p = p->next;
		j++;
	}
	if(p)
		return j;
	else
		return 0;
}

//遍历单链表
template <class T>
void LinkList<T>::PrintLinkList()
{
	Node<T>* p =  head->next;
	while(p){		//p非空
		cout << p->data << endl;
		p = p->next;
	}
}

//第i位插入单链表
template <class T>
void LinkList<T>::Insert(int i, T item)
{
	Node<T>* p = head;
	int j = 0;
	while(p && j<i-1){		//找到第i-1个结点位置
		p = p->next;
		j++;
	}
	if(!p){		//p超出范围
		cerr << "Invalid Position!";
		exit(1);
	}
	else{
		Node<T>* s = new Node<T>;
		s->data = item;
		s->next = p->next;
		p->next = s;
	}
}

//单链表的删除
template <class T>
T LinkList<T>::Delete(int i)
{
	Node<T>* p = head;
	int j = 0;
	while(p && j<i-1){			//查找第i-1个结点
		p = p->next;
		j++;
	}
	if(!p || !p->next){
		cerr << "Invalid position!";
		exit(1);
	}
	else{
		Node<T>* q = p->next;
		T x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
} 

//逆置单链表
template <class T>
void LinkList<T>::Invert()
{
	Node<T>* p = head->next;
	head->next = NULL;			//逆置后的单链表初始化为空表
	while(p != NULL){			//若p非空，则遍历单链表
		Node<T>* q = p;
		p = p->next;
		q->next = head->next;		//结点插入到逆置后链表表头
		head->next = q;
	}

}

//合并有序单链表
template <class T>
void LinkList<T>::Merge(LinkList<T> &L2)
{
	Node<T>* p1 = head->next;
	Node<T>* p2 = L2.head->next;
	Node<T>* p3 = head;
	while((p1 != NULL) && (p2 != NULL)){		//两表非空，p1,p2指向需比较结点，p3指向有序单链表表尾//**倒插**
		if((p1->data) < (p2->data)){
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
		else{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
	}
	if(p1 != NULL)
		p3->next = p1;
	if(p2 != NULL)
		p3->next = p2;
	delete L2.head;
	L2.head = NULL;
}