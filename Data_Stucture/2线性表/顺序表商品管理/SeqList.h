#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>
#include <stdlib.h>

template <class T, int MaxSize>
class SeqList
{
public:
	enum ErrorType {InvalidParameter,InvalidPosition,TableEmpty,TableFull};
	char *errorMsg[50] = {"Invalid parameter!","Invalid position!",
	"Table's empty, no item to delete!","Table spill, cannot insert more item!"};
		
	SeqList();					//无参构造函数
	SeqList(T a[], int n);		//有参构造函数
	int ListLength();			//求线性表长度
	T Get(int pos);				//按位查找，取第pos个元素
	int Locate(T item);			//按值查找，求值为item的元素序号
	void PrintSeqList();		//遍历顺序表，按顺序表依次输出各元素
	void Insert(int i,T item);	//在顺序表第i个位置插入值为item的元素
	T Delete(int i);			//删除顺序表第i个元素
	~SeqList();					//空析构函数

//Additional function
	void SortSeqList();			//顺序表排序
	SeqList<T, MaxSize> MergeSeqList(SeqList<T, MaxSize> x);		//合并顺序表
	T DeleteMin();					//删除最小元素并返回最小值，用最后一个元素填补空值
	void DeleteValue(T x);			//删除所有给定值x的元素
	void DeleteRegion(T s, T t);	//删除介于s和t之间所有元素
	void DeleteRepeat();			//删除重复元素，保留第一次出现位置
	void Devide_by_a1();			//以x分割顺序表，之前的小于x，之后的大于x
	void Update(T item);
	void Load(char *fname);
	void Save(char *fname);
	
private:
	T data[MaxSize];	//存放数据元素数组
	int length;			//顺序表中元素个数
//判断函数
	int isIdExist(T item);
	bool isEmpty();
	bool isFull();
	bool isSpilled(int n);
	bool isValidInquirePos(int pos);
	bool isValidInsertPos(int pos);
//功能函数
	void Swap(T &a, T &b);
	void Error(ErrorType error) const;
};

#endif // SEQLIST_H