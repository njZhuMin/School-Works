#ifndef LINKQUEUE_H
#define LINKQUEUE_H

template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class LinkQueue  
{
public:
	LinkQueue();
	virtual ~LinkQueue();
	void EnQueue(T x);
	T DeQueue();
	bool isEmpty();
private:
	Node<T>* front,* rear;
};

#endif 