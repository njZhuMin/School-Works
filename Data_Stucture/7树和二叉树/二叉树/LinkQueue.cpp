#include <iostream>
#include "LinkQueue.h"
using namespace std;

template<class T>
LinkQueue<T>::LinkQueue()
{
	Node<T>* s = new Node<T>;
	s->next = NULL;
	front = rear = s;
}
template<class T>
LinkQueue<T>::~LinkQueue()
{
	Node<T>* p = front;
	while(p)
	{
		Node<T>* q = p;
		p = p->next;
		delete q;
	}
	front = NULL;
}

template<class T>
void LinkQueue<T>::EnQueue(T x)
{
	Node<T>* s = new Node<T>;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

template<class T>
T LinkQueue<T>::DeQueue()
{
	if(rear == front)
	{
		cerr << "Queue is empty!";
		exit(1);
	}
	Node<T>* p = front->next;
	T x = p->data;
	front->next = p->next;
	if(p->next == NULL)
		rear = front;
	delete p;
	return x;
}

template<class T>
bool LinkQueue<T>::isEmpty()
{
	return rear ==front;
}
