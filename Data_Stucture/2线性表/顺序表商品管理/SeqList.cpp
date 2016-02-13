#include "SeqList.h"
#include <fstream>
using namespace std;

//无参构造函数
template <class T, int MaxSize>
SeqList<T,MaxSize>::SeqList(){
	length=0;
}

//有参构造函数
template <class T, int MaxSize>
SeqList<T,MaxSize>::SeqList(T a[],int n){
	if(isSpilled(n))
		Error(InvalidParameter);	//判断输入合法性，参数是否越界
	for (int i=0; i<n; i++){
		data[i]=a[i];	//To Do:重载运算符 "="
	}
	length=n;
}

//求线性表长度
template <class T, int MaxSize>
int SeqList<T,MaxSize>::ListLength(){
	return length;
}

//按位查找，取第pos个元素
template <class T, int MaxSize>
T SeqList<T,MaxSize>::Get(int pos){
	if(!isValidInquirePos(pos))		//判断查找位置是否合法
		Error(InvalidPosition);
	return data[pos-1];
}

//按值查找，求值为item的元素序号
template <class T, int MaxSize>
int SeqList<T,MaxSize>::Locate(T item){
	for(int i=0; i<length; i++){
		if(data[i]==item)
			return (i+1);
	}
	return 0;
}

//遍历顺序表，按顺序表依次输出各元素
template <class T, int MaxSize>
void SeqList<T,MaxSize>::PrintSeqList(){
	for(int i=0; i<length; i++)
		cout << data[i] << endl;
}

//在顺序表第i个位置插入值为item的元素
template <class T, int MaxSize>
void SeqList<T,MaxSize>::Insert(int i,T item){
	if(isFull())	//表满了则不允许插入
		Error(TableFull);
	if(!isValidInsertPos(i))	//判断插入位置是否合法
		Error(InvalidPosition);
	for(int j=length-1; j>=i-1; j--){
		data[j+1] = data[j];
	}
	data[i-1] = item;
	length++;
}

//删除顺序表第i个元素
template <class T, int MaxSize>
T SeqList<T,MaxSize>::Delete(int i){
	if(isEmpty())		//表为空，不允许删除
		Error(TableEmpty);
	if(!isValidInquirePos(i))		//判断删除位置是否合法
		Error(InvalidPosition);
	T x = data[i-1];
	for(int j=i; j<length; j++){
		data[j-1] = data[j];
	}	
	length--;
	return x;
}

//析构函数
template <class T, int MaxSize>
SeqList<T,MaxSize>::~SeqList(){}

//Additional function
//双向鸡尾酒排序
template <class T, int MaxSize>
void SeqList<T,MaxSize>::SortSeqList(){
	int top = 0, bottom = length-1;
	bool flag = true;
	while (flag){
		flag = false;
		for (int i = top; i < bottom; i++){
			if (data[i]>data[i+1]){
				Swap(data[i],data[i+1]);
				flag = true;
			}
		}
		--bottom;
		for (int j = bottom; j > top; --j){
			if (data[j]<data[j-1]){
				Swap(data[j],data[j-1]);
				flag = true;
			}
		}
		++top;
	}
}


 //合并顺序表
template <class T, int MaxSize>
SeqList<T, MaxSize> SeqList<T, MaxSize>::MergeSeqList(SeqList<T, MaxSize> x){
    SeqList<T, MaxSize> c = (SeqList<T, MaxSize>)malloc(sizeof(SeqList<T, MaxSize>)*(this->length + x->length));
    int i = 0, j = 0 ,k = 0;
    while(i < this->length && j < x->length)
    {
        if(this->data[i] < x->data[j])
        {
            c[k] = this->data[i];
            i++;
        }
        else
        {
            c[k] = x->data[j];
            j++;
        }
        k++;
    }
    if(i == this->length)
        while(j < x->length)
            c[k++] = x->data[j++];
    else
        while(i < this->length)
            c[k++] = this->data[i++];
    return c;
}

//删除最小元素并返回最小值，用最后一个元素填补空值
template <class T, int MaxSize>
T SeqList<T, MaxSize>::DeleteMin()
{
	T temp;
	if(isEmpty())		//表为空，不允许删除
		Error(TableEmpty);
	int min = 0;	//假设第一位为最小
	for(int i=0; i<length-1; i++){
		if(data[i] < data[min]){
			min = i;	
		}
		temp = data[min];	//保存data[m]
		data[min] = data[length-1];	//用最后元素填补最小值位置
		length--;
	}
	return temp;
}

//删除所有给定值x的元素
template <class T, int MaxSize>
void SeqList<T,MaxSize>::DeleteValue(T x){
	if(isEmpty())		//表为空，不允许删除
		Error(TableEmpty);
	int i = 0;
	while(i < length-1){
		if(data[i]==x){
			for(int j=i; j<length-1; j++){
				data[j] = data[j+1];		//覆盖删除元素
			}
			length++;
		}
		else
			i++;
	}
}

//删除介于s和t之间所有元素
template <class T, int MaxSize>
void SeqList<T,MaxSize>::DeleteRegion(T s, T t){
	if(isEmpty())		//表为空，不允许删除
		Error(TableEmpty);
	//!!判定s,t参数是否合法!!//
	if(s >= t)
		Error(InvalidParameter);
	int i = 0;
	while(i < length-1){
		if(data[i]>=s && data[i]<=t){
			for(int j=i; j<length-1; j++){
				data[j] = data[j+1];		//覆盖删除元素
			}
			length++;
		}
		else
			i++;
	}
}

//删除重复元素，保留第一次出现位置
template <class T, int MaxSize>
void SeqList<T,MaxSize>::DeleteRepeat(){
	if(isEmpty())
		Error(TableEmpty);
	int i = 0;
	int j,k;
	T temp;
	while(i<length){
		temp = data[i];		//取出第i位待检测
		j = i+1;		//从i+1位开始
		while(j<length){
			if(temp==data[j]){		//对于每一个i，检测后续是否相等
				for(k=j+1; k<length; k++)	//若相等，后续元素前移删除
					data[k-1]=data[k];
				length--;
			}
			else
				j++;
		}
		i++;	//检测完a[i]，检测下一个
	}
}

//以a[1]分割顺序表，之前的小于a[1]，之后的大于a[1]
template <class T, int MaxSize>
void SeqList<T,MaxSize>::Devide_by_a1(){
	if(length % 2)
		length++;		//凑成偶数位
	int *array = new int[length];		//创建buffer数组
	int small = 0;			
	int big = length/2+2;
	data[0] = array[length/2+1];	
	for(int i = 1;i < length;i++)
	{
		if(data[0]>data[i])
		{
			array[small] = data[i];
			small++;
		}
		else
		{
			array[big] = data[i];
			big++;
		}
	}
}

//判定函数
template <class T, int MaxSize>
bool SeqList<T,MaxSize>::isSpilled(int n){
	if(n > MaxSize)
		return true;
	else
		return false;
}

template <class T, int MaxSize>
bool SeqList<T,MaxSize>::isEmpty(){
	if(length == 0)
		return true;
	else
		return false;
}

template <class T, int MaxSize>
bool SeqList<T,MaxSize>::isFull(){
	if(length >= MaxSize)
		return true;
	else
		return false;
}

template <class T, int MaxSize>
bool SeqList<T,MaxSize>::isValidInquirePos(int pos){
	if(pos<1 || pos>length)
		return false;
	else
		return true;
}
	
template <class T, int MaxSize>
bool SeqList<T,MaxSize>::isValidInsertPos(int pos){
	if(pos<1 || pos>length+1)
		return false;
	else
		return true;
}	

//功能函数
template <class T, int MaxSize>
void SeqList<T,MaxSize>::Swap(T &a,T &b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

//异常处理函数
template <class T, int MaxSize>
void SeqList<T,MaxSize>::Error(ErrorType error) const{
	cout << errorMsg[error] << endl;
	exit(1);
}

//按ID判断是否有相同项
template <class T, int MaxSize>
int SeqList<T,MaxSize>::isIdExist(T item){
	for(int i=0; i<length; i++){
		if(data[i]==item)
			return (i);
	}
	return 0;
}

template <class T, int MaxSize>
void SeqList<T,MaxSize>::Update(T item){	
	if(isIdExist(item)){		//如果存在，删除该项，在该位置插入新项
		Delete(isIdExist(item));
		Insert(isIdExist(item),item);
	}
	else{				//否则在末尾插入新项
		Insert(length+1,item);
	}
}

template <class T, int MaxSize>
void SeqList<T,MaxSize>::Load(char *fname)
{
	ifstream fin(fname);
	fin>>length;
	for(int i=0; i<length; i++)
	{
		fin>>data[i];
	}
}

template <class T, int MaxSize>
void SeqList<T,MaxSize>::Save(char *fname)
{
	ofstream fout(fname);
	fout<<length<<endl;
	for(int i=0; i<length; i++)
	{
		fout<<data[i]<<endl;
	}
	fout.close();
}
