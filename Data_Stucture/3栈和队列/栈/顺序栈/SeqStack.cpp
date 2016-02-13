#include "SeqStack.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//顺序栈初始化
template <class T,int MaxSize>
SeqStack<T,MaxSize>::SeqStack()
{
	top = -1;
}

//入栈操作
template <class T,int MaxSize>
void SeqStack<T,MaxSize>::Push(T x)
{
	if(top==MaxSize-1){
		cerr << "Stack is full!";
		exit(1);
	}
	top++;
	data[top] = x;
}

//出栈操作
template <class T,int MaxSize>
T SeqStack<T,MaxSize>::Pop()
{
	if(top==-1){
		cerr << "Stack is empty!";
		exit(1);
	}
	T x = data[top];
	top--;
	return x;
}

//取栈顶元素
template <class T,int MaxSize>
T SeqStack<T,MaxSize>::Top()
{
	if(top==-1){
		cerr << "Stack is empty!";
		exit(1);
	}
	return data[top];
}

//判断栈是否为空
template <class T,int MaxSize>
bool SeqStack<T,MaxSize>::isEmpty()
{
	return (top==-1);
}

//析构函数
template <class T,int MaxSize>
SeqStack<T,MaxSize>::~SeqStack()
{
}