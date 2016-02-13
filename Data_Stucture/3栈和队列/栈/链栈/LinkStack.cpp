#include "LinkStack.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//链栈初始化
template<class T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

//入栈操作
template<class T>
void LinkStack<T>::Push(T x)
{
	Node<T>* s = new Node<T>;	//申请一个数据域为x的结点s
	s->data = x;
	s->next = top;
	top = s;		//将结点s插入在栈顶
}

//出栈操作
template<class T>
T LinkStack<T>::Pop()
{
	if(top==NULL){
		cerr << "Stack is empty!";
		exit(1);
	}
	T x = top->data;		//x储存栈顶元素
	Node<T>* p = top;		//p指向top
	top = top->next;		//栈顶指针后移
	delete p;				//删除栈顶结点
	return x;
}

//取出栈顶元素
template<class T>
T LinkStack<T>::Top()
{
	if(top==NULL){
		cerr << "Stack is empty!";
		exit(1);
	}
	return top->data;
}

//判断链栈是否为空
template<class T>
bool LinkStack<T>::isEmpty()
{
	return (top==NULL);
}

//析构函数
template<class T>
LinkStack<T>::~LinkStack()
{
	Node<T>* p = top;
	while(p)
	{
		Node<T>* q = p;
		p = p->next;
		delete q;
	}
	top = NULL;
}

