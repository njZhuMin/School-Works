#ifndef SEQQUEUE_H
#define SEQQUEUE_H

template <class T, int MaxSize>
class SeqQueue
{
private:
	T data[MaxSize];		//存放队列元素数组
	int front,rear;			//队首和队尾指针
public:
	SeqQueue();				//构造函数，置空
	~SeqQueue();			//析构函数
	void EnQueue(T x);		//元素x入队
	T DeQueue();			//队首元素出队
	T GetQueue();			//取队头元素（不删除）
	bool isEmpty();			//判断队列是否为空
	bool isFull();			//判断队列是否满
};

#endif // SEQQUEUE_H
