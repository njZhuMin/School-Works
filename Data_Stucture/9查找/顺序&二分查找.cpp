#include <iostream>
using namespace std; 

//declaration
int SeqSearch1(int *a, int n, int key);	//无监视哨顺序查找，时间复杂度O(n)
int SeqSearch2(int *a, int n, int key); 	//有监视哨顺序查找，时间复杂度O(n)
int BiSearch(int data[], const int x, int begin, int last);		//非递归二分查找  
int IterBiSearch(int data[], const int x, int begin, int last);	//递归二分查找  
  
int main()  
{  
	//顺序查找测试
	int a[20] = {2,3,5,1,4,7,8,9,6,0};  
	cout << "The array is: " << endl;  
	int size1 = sizeof(a)/sizeof(int);  
	for(int i = 0; i < size1; i++)  
	{  
		a[i] = i;  
		cout << a[i] << "\t"; 
		if((i+1) % 5 == 0)
			cout << endl;
	}  
	cout << endl;
	int key = 7;  
	cout << "Index of " << key << " is " << SeqSearch1(a, 10, key) << endl;  
	cout << endl;  
	key = 99; 
	cout << "Index of " << key << " is " << SeqSearch2(a, 10, key) << endl;  
	cout << endl;
	
	//二分查找测试
	int data1[60] = {0};  
	int key2 = 45;  
	cout << "The array is: " << endl;  
	int size2 = sizeof(data1)/sizeof(int);  
	for(int i = 0; i < size2; i++)  
	{  
		data1[i] = i;  
		cout << data1[i] << "\t"; 
		if((i+1) % 10 == 0)
			cout << endl;
	}  
	cout << endl;  
	int index = -1;  
	//index = BiSearch(data1, key2, 0, size2);  
	index = IterBiSearch(data1, key2, 0, size2);  
	cout << "Index of " << key2 << " is " << index << endl;  
  
	return 0; 
}  

/**
 * @brief 无监视哨顺序查找
 * @param a src数据
 * @param n 数据大小
 * @param key 目标关键字
 * @return 
 */
int SeqSearch1(int *a, int n, int key)
{  
    int i = 0;  
    for(i = 0; i < n; i++)  
    {  
        if(key == a[i])  
        {  
            return i;  
        }  
    }  
    return -1;  
}  

/**
 * @brief 有监视哨顺序查找
 * @param a src数据
 * @param n 数据大小
 * @param key 目标关键字
 * @return 
 */
int SeqSearch2(int *a, int n, int key)  
{  
    int i = 0;  
    a[n] = key;	//要求数据要开得足够大，否则溢出  
    while(a[i] != key)  
    {  
        i++;  
    }  
    if(i < n)		//如果i=n，说明查找失败  
		return i;		
	else
		return -1;
}  

/*
 * 折半查找法：
 * 在有序表中，把待查找数据值与查找范围的中间元素值进行比较，会有三种情况出现：
 * 1.待查找数据值与中间元素值正好相等，则放回中间元素值的索引
 * 2.待查找数据值比中间元素值小，则以整个查找范围的前半部分作为新的查找范围，执行1，直到找到相等的值
 * 3.待查找数据值比中间元素值大，则以整个查找范围的后半部分作为新的查找范围，执行1，直到找到相等的值
 * 4.如果最后找不到相等的值，则返回错误提示信息
 *
 * 按照二叉树来理解：中间值为二叉树的根，前半部分为左子树，后半部分为右子树
 * 折半查找法的查找次数正好为该值所在的层数，等概率情况下，约为log2(n+1)-1
 */

/**
 * @brief 非递归二分查找  
 * @param data 待查找数据
 * @param x 目标关键词
 * @param begin 开始位置
 * @param last 结束位置
 * @return 
 */
int BiSearch1(int data[], const int x, int begin, int last)  
{  
    int mid;		//中间位置  
    if(begin > last)   
        return -1;  
    while(begin <= last)  
    {  
        mid = (begin + last) / 2;  
        if(x == data[mid])    
            return mid;  
        else if(data[mid] < x)  
            begin = mid + 1;  
        else if(data[mid] > x)  
            last = mid - 1;  
    }  
    return -1;  
}  

/**
 * @brief 递归二分查找 
 * @param data 待查找数据
 * @param x 目标关键词
 * @param begin 开始位置
 * @param last 结束位置
 * @return 
 */
int IterBiSearch(int data[], const int x, int begin, int last)  
{  
    int mid = -1;  
    mid = (begin + last) / 2;  
    if(x == data[mid])   
        return mid;  
    else if(x < data[mid])  
        return IterBiSearch(data, x, begin, mid - 1);  
    else if (x > data[mid])  
        return IterBiSearch(data, x, mid + 1, last);  
    return -1;  
}  