#include "BothStack.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//构造函数
template <class T, int MaxSize>
BothStack<T,MaxSize>::BothStack()
{
	top1 = -1;
	top2 = MaxSize;
}

//析构函数
template <class T, int MaxSize>
BothStack<T,MaxSize>::~BothStack()
{
}

//入栈操作
template <class T, int MaxSize>
void BothStack<T,MaxSize>::Push(int i,T x)
{
	if(i==1)		//向Stack1 push
	{
		if(top1+1==top2){
			cerr << "Stack1 is full!";
			exit(1);
		}
		data[++top1] = x;
	}
	else if(i==2)	//向Stack2 push
	{
		if(top1+1==top2){
			cerr << "Stack2 is full!";
			exit(1);
		}
		data[--top2] = x;
	}
	else
	{
		cerr << "Error input!";
		exit(1);
	}
}

//出栈操作
template <class T, int MaxSize>
T BothStack<T,MaxSize>::Pop(int i)
{
	if(i==1)
	{
		if(top1==-1)
		{
			cerr << "Stack1 is empty!";
			exit(1);
		}
		T x = data[top1--];
		return x;
	}
	else if(i==2)
	{
		if(top2==MaxSize)
		{
			cerr << "Stack2 is empty!";
			exit(1);
		}
		T x = data[top2++];
		return x;
	}
	else
	{
		cerr << "Error input!";
		exit(1);
	}
}

//取栈顶元素
template <class T, int MaxSize>
T BothStack<T,MaxSize>::GetTop(int i)
{
	if(i==1)
	{
		if(top1==-1){
			cerr << "Stack1 is empty!";
			exit(1);
		}
		return data[top1];
	}
	else if(i==2)
	{
		if(top2==MaxSize){
			cerr << "Stack2 is empty!";
			exit(1);
		}
		return data[top2];
	}
	else
	{
		cerr << "Error input!";
		exit(1);
	}
}

//判断两栈是否为空
template <class T, int MaxSize>
bool BothStack<T,MaxSize>::isEmpty(int i)
{
	if(i==1)
		return (top1==-1);
	else if(i==2)
		return (top2==MaxSize);
}