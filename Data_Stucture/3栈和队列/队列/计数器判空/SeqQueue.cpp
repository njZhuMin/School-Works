#include "SeqQueue.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//循环队列初始化
template <class T, int MaxSize>
SeqQueue<T,MaxSize>::SeqQueue()
{
	front = rear = 0;
	count = 0;		//初始化count
}

//析构函数
template <class T, int MaxSize>
SeqQueue<T,MaxSize>::~SeqQueue()
{
}

//循环队列入队
template <class T, int MaxSize>
void SeqQueue<T,MaxSize>::EnQueue(T x)
{
	if(isFull())
	{
		cerr << "Queue is full!";
		exit(1);
	}
	/* front ->  front 			-> *		x		rear
	 * rear  ->          rear	-> front
	 * front始终为空
	 */
	//调整指针移动与赋值顺序
	data[rear] = x;				//在队尾插入元素
	rear = (rear+1) % MaxSize;	//队尾指针循环意义下+1
	count++;		//计数器加1
}

//循环队列出队
template <class T, int MaxSize>
T SeqQueue<T,MaxSize>::DeQueue()
{
	if(isEmpty())
	{
		cerr << "Queue is empty!";
		exit(1);
	}
	//调整指针移动与赋值顺序
	T temp = data[front];
	front = (front+1) % MaxSize;	//队首指针循环意义下+1
	count--;						//计数器减1
	return temp;				//取出并返回队首元素
}

//取出队首元素
template <class T, int MaxSize>
T SeqQueue<T,MaxSize>::GetQueue()
{
	if(isEmpty())
	{
		cerr << "Queue is empty!";
		exit(1);
	}
	return data[front % MaxSize];
}

//判空
template <class T, int MaxSize>
bool SeqQueue<T,MaxSize>::isEmpty()
{
	return ((rear == front) && (count == 0));
}

//判满
template <class T, int MaxSize>
bool SeqQueue<T,MaxSize>::isFull()
{
	return ((rear == front) && (count == MaxSize));
}