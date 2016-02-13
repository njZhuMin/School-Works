#include <iostream>
using namespace std; 
#define MAXSIZE 11

struct indexBlock		//定义块的结构
{
    int key;
    int start;
    int end;
}indexBlock[4];		//定义结构体数组

//declaration
int blockSearch(int x, int a[]);	//分块查找函数
void Fibonacci(int *f);
int Fibonacci_Search(int *a, int n, int key);

int main()
{
	/////////////////////////////分块查找测试/////////////////////////////
	int j = -1, k, x;
	int a[] = {1,3,5,7,9,11,13,15,2,4,6,8,10,12,14};
	cout << "Array 1 is:" << endl;
	for(int i = 0; i < 15; i++) 
	{
		cout << a[i] << "\t";
       if((i + 1) % 5 == 0)
			cout << endl;
	}
	cout << endl;
            
	for(int i = 0; i < 3; i++) 
	{
		indexBlock[i].start = j + 1;   //确定每个块范围的起始值
		j = j + 1;
            
		indexBlock[i].end = j + 4;     //确定每个块范围的结束值
		j = j + 4;

		indexBlock[i].key = a[j];      //确定每个块范围中元素的最大值
	}
        
	cout << "Input a number:" << endl;
	cin >> x;
	cout << endl;
	
	k = blockSearch(x, a);
        
	if(k >= 0)
		cout << "Index of " << x << " is " << k+1 << endl;
	else
		cout << x <<" not found!" << endl;
	
	cout << endl;
	/////////////////////////////斐波那契数列查找/////////////////////////////
	int b[MAXSIZE] = {0,1,16,24,35,47,59,62,73,88,99};  
	int k2 = 0; 
	cout << "Array 2 is:" << endl;
	for(int i = 0; i < 11; i++) 
	{
		cout << b[i] << "\t";
       if((i + 1) % 5 == 0)
			cout << endl;
	}
	cout << endl;
 
	cout << "Input a number" << endl;  
	cin >> k2;
	cout << endl;
	
	int pos = Fibonacci_Search(b, MAXSIZE-1, k2);  
	if(pos != -1)  
		cout << "Index of "<< k2 <<" is: " << pos + 1 << endl; 
	else  
		cout << k2 << " is not found!" << endl; 
	
    return 0;
}

/*
 * 分块查找法要求将列表组织成以下索引顺序结构：
 * 首先将列表分成若干个块（子表）。一般情况下，块的长度均匀，最后一块可以不满。
 * 每块中元素任意排列，即块内无序，但块与块之间有序。
 * 构造一个索引表。其中每个索引项对应一个块并记录每块的起始位置，和每块中最大关键字（或最小关键字）。
 * 索引表按关键字有序排列。
 * 
 * 分块查找的基本过程如下：
 * 1.首先，将待查关键字 K 与索引表中的关键字进行比较，以确定待查记录所在的块。
 *   具体的可用顺序查找法或折半查找法进行。
 * 2.进一步用顺序查找法，在相应块内查找关键字为 K的元素。
 */
 //http://blog.csdn.net/xuejianxinokok/article/details/6607094
 //http://www.cnblogs.com/hanjun/archive/2013/02/05/2892826.html
 //http://www.cnblogs.com/Braveliu/p/3464919.html
/**
 * @brief 分块查找
 * @param x
 * @param a
 * @return 
 */
int blockSearch(int x, int a[])
{
    int i = 0;
    int j;
    //确定在哪个块中
    while(i < 3 && x > indexBlock[i].key)
	{  
		i++;
	}
    
    if(i >= 3)	//大于分的块数，则返回-1,找不到该数
        return -1;
    
    j = indexBlock[i].start;    //j等于块范围的起始值
    //在确定的块内进行查找
	while(j <= indexBlock[i].end && a[j] != x) 
	{    
		j++;
	}
    
    if(j > indexBlock[i].end)	//如果大于块范围的结束值，则说明没有要查找的数，j置为-1
        j = -1;

    return j;
}


/**
 * @brief Fibonacci递归
 * @param f
 */
void Fibonacci(int *f)
{
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < MAXSIZE; ++i)
		f[i] = f[i-1] + f[i-2];
 }
 
 // 斐波那契数列
 /*---------------------------------------------------------------------------------
 |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10  |  11  |  12  |
  ----------------------------------------------------------------------------------
 |  0  |  1  |  1  |  2  |  3  |  5  |  8  |  13 |  21 |  34 |  55  |  89  |  144 |
  -----------------------------------------------------------------------------------*/
  
/**
 * @brief 斐波那契数列查找
 * @param a 目标数据
 * @param n 数据大小
 * @param key 查找关键字
 * @return 
 */
 //http://www.cnblogs.com/Braveliu/p/3463499.html

 int Fibonacci_Search(int *a, int n, int key)
 {
	int low = 1;  	// 定义最低下标为记录首位
	int high = n; 	// 定义最高下标为记录末位（一般输入的参数n必须是数组的个数减1）
 
	int F[MAXSIZE];
	Fibonacci(F); 	//确定斐波那契数列
 
	int k = 0, mid = 0;
	//查找n在斐波那契数列中的位置，为什么是F[k]-1，而不是F[k]？
	while(n > F[k]-1)
	{
		k++;
	}
	// 将不满的数值补全
	for(int i = n; i < F[k]-1; ++i)
		a[i] = a[high];
		 
	// 查找过程
	while(low <= high)
	{
		mid = low + F[k-1] - 1; 
		if (key < a[mid]) 	//查找记录小于当前分割记录
		{
			high = mid - 1;
			k = k - 1;     	//注意:减一位
		}
		else if (key > a[mid]) 	//查找记录大于当前分割记录
		{
			low = mid + 1;
			k = k - 2;  	//注意:这里减两位
		}
		else
			return (mid <= high) ? mid : n;  //若相等则说明mid即为查找到的位置； 若mid > n 说明是补全数值，返回n
	}
	return -1;
}