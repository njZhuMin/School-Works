#ifndef SEQSTACK_H
#define SEQSTACK_H

template <class T,int MaxSize>
class SeqStack
{
private:
	T data[MaxSize];	//存放栈元素数组
	int top;			//栈顶指针，指示栈元素在数组下标
public:
	SeqStack();			//构造函数
	void Push(T x);		//入栈
	T Pop();			//出栈
	T Top();			//取出栈顶元素（元素不出栈）
	bool isEmpty();		//判断栈是否为空
	~SeqStack();		//析构函数

};

#endif // SEQSTACK_H

