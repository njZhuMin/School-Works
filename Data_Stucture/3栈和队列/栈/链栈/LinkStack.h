#ifndef LINKSTACK_H
#define LINKSTACK_H

template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class LinkStack
{
private:
	Node<T>* top;		//栈顶指针
public:
	LinkStack();		//构造函数
	~LinkStack();		//析构函数
	void Push(T x);		//入栈
	T Pop();			//出栈
	T Top();			//取出栈顶元素（元素不出栈）
	bool isEmpty();		//判断链栈是否为空
};

#endif // LINKSTACK_H
