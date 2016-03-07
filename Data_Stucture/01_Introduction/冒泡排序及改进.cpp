#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define maxsize 20000
//declaration
void show_array(int* arr, int n);
void swap(int & a, int & b);
int get_time(time_t t_start, time_t t_end);
int bubbling_sort(int *a, int n);
bool _less(int a, int b);

//冒泡改进1：增加结束标志，排序已完成提前跳出循环
int sort_bubble_mend1(int* arr, int n, bool(less)(int a, int b));
//冒泡改进2：记录最后交换位置记录，减少遍历次数 
int sort_bubble_mend2(int* arr, int n, bool(less)(int a, int b));
//冒泡改进3:增加交换位置记录，并用其确定是否继续排序
int sort_bubble_mend3(int* arr, int n, bool(less)(int a, int b));
//冒泡改进4:更进一步的优化，双向冒泡
int sort_bubble_mend4(int* arr, int n, bool(less)(int a, int b));
//end of declaration

int main()
{
	cout << "Calculating time cost..." << endl;
	int a[maxsize], b[maxsize];
	//int a[10] = {10,1,2,3,4,5,6,7,8,9};
	//int b[10] = {10,1,2,3,4,5,6,7,8,9};
	
	for(int i = 0; i < maxsize; i++)
	{
		a[i] = rand()%5000;
		b[i] = a[i];
	}
	
	//测试原始冒泡排序时间
	cout << "Original bubbling sort:" << endl;
	time_t t_start1 = clock();
	int count1 = bubbling_sort(a,maxsize);
	time_t t_end1 = clock();
	cout <<  get_time(t_start1,t_end1) << " s" << endl;
	cout << "Swap count: \t" << count1 << endl;

	//测试优化后冒泡排序时间
	cout << "Advanced bubbling sort: \t" << endl;
	time_t t_start2 = clock();
	int count2 = sort_bubble_mend4(b,maxsize, _less);
	time_t t_end2 = clock(); 
	cout << "Swap count: \t" << count2 << endl;
	cout << get_time(t_start2,t_end2) << " s" << endl;
	
	return 0;
}

int get_time(time_t t_start, time_t t_end)
{
	return (t_end - t_start)*1000/CLOCKS_PER_SEC;
}

void show_array(int* arr, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << arr[i] << '\t';
		if((i+1) % 15 == 0)	cout << endl;
	}
	cout << endl;
}

int bubbling_sort(int *a, int n)  
{  
	int i,j; 
	int count = 0;
	bool flags = true;  
	for(i = 0; i < n-1; i++)  
	{  
		for(j = 0; j < n-1-i; j++)  
		{  
			if(a[j] > a[j+1])  
			{  
				swap(a[j],a[j+1]); 
				count++; 
				flags = false;  
			}  
		}  
		if(flags)  
			break;  
		else  
			flags = true;  
	}
	//show_array(a, n);
	return count;
}
 
//交换函数
void swap(int & a, int & b)
{
	int temp = a;    
	a = b;    
	b = temp;
}

//默认的小于比较
bool _less(int a, int b)
{
	return (a < b);
}

//冒泡改进1：增加结束标志，排序已完成提前跳出循环
int sort_bubble_mend1(int* arr, int n, bool(less)(int a, int b)) //默认排序比较
{
	bool SortOver = false;    //排序结束标志
	int count = 0;
	for(int i = n-1; i > 0; --i)	//i==1的时候就结束了
	//i控制沉底的位置，j控制遍历沉底
	//每次进入排序，先SortOver为真    
	{
		SortOver = true;
		for(int j = 0; j < i; ++j)
		{
			if(!less(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				count++;
				SortOver = false;	//发生了交换，说明没有结束
			}
		}
		if(SortOver)	break;	//排序结束，跳出循环
	}
	//show_array(arr, n);
	return count;
}

//冒泡改进2：记录最后交换位置记录，减少遍历次数 
int sort_bubble_mend2(int* arr, int n, bool(less)(int a, int b))    //默认排序比较
{
	bool SortOver = false;    //排序结束标志
	int count = 0;
	int LastSwapSite = n - 1;	//记录最后交换位置
	
	for(int i=n-1; i>0; i=LastSwapSite) 
	{    
		SortOver = true;	//每次进入排序，先SortOver为真
		for(int j = 0; j < i; ++j)
		{
			if(!less(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);	//发生了交换，说明没有结束
				count++;
				SortOver = false;
				LastSwapSite = j;	//记录交换位置
			}
		}
		if(SortOver) break;
	}
	//show_array(arr, n);
	return count;
}

//冒泡改进3:增加交换位置记录，并用其确定是否继续排序
int sort_bubble_mend3(int* arr, int n, bool(less)(int a, int b))    //默认排序比较
{
	int LastSwapSite = n - 1;
	int count = 0;
	for(int i = n - 1; i >0; i = LastSwapSite)	//i==1的时候就结束了
	{    
		LastSwapSite = 0;
		for(int j = 0; j < i; ++j)
		{
			if(!less(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				count++;
				LastSwapSite = j;	//记录交换位置，没有交换，位置为0，结束排序
			}
		}
	}
	//show_array(arr, n);
	return count;
}

//冒泡改进4:更进一步的优化，双向冒泡，单向冒泡每一次遍历只能沉底一个，双冒泡可以提高效率
int sort_bubble_mend4(int* arr, int n, bool (less)(int a, int b))    //默认排序比较
{
	int LastSwapSiteRight = n - 1;    //右向扫描遍历起点
	int LastSwapSiteLeft = 0;        //左向扫描遍历起点
	int count = 0;
	for(int i = n - 1; i >0; i = LastSwapSiteRight) //i控制右侧端点，i==1的时候就结束了
	{   
		LastSwapSiteRight = 0;	//每次进入排序，先LastSwapSite=0
		int k = LastSwapSiteLeft;
		for(int j = k; j < i; ++j)
		{
			if(!less(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				count++;               
				LastSwapSiteRight = j;	//记录交换位置，没有交换，位置为0，结束排序
			}
			if(!less(arr[i +  - 1 - j + k], arr[i + k - j]))
			{
				swap(arr[i + k - 1 - j], arr[i + k - j]);
				count++; 
				LastSwapSiteLeft = i + k - 1 - j;	//最后交换的位置，最左边的
			}
		}
	}
	//show_array(arr, n);
	return count;
}