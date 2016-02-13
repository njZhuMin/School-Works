#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define maxsize 10

//declaration
void swap(int &a, int &b);
void show_array(int* arr, int n);
void BubbleSort(int* arr, int n);
void BubbleSortWithFlag(int* arr, int n);
void BubbleSortWithIndex(int* arr, int n);
void CocktailSort(int* arr, int n);
void SelectSort(int* arr, int n);
int get_time(time_t t_start, time_t t_end);

int main()
{
	cout << "Calculating time cost..." << endl;
	//int a[maxsize];
	//int a[10] = {1,2,3,4,5,6,7,8,9,10};
	//int a[10] = {10,9,8,7,6,5,4,3,2,1};
	//int a[10] = {10,1,2,3,4,5,6,7,8,9};
	//int a[10] = {2,1,3,4,5,6,7,8,9,10};
	//int a[10] = {1,2,3,4,5,6,7,8,10,9};
	//int a[10] = {2,1,3,4,5,6,7,8,10,9};
	//int a[10] = {2,3,4,5,6,7,8,9,10,1};
	int a[10] = {2,1,7,9,5,6,4,8,10,3};
	int b[maxsize],c[maxsize],d[maxsize];
	
	for(int i = 0; i < maxsize; i++)
	{
		//a[i] = rand()%5000;
		b[i] = a[i];
		c[i] = a[i];
		d[i] = a[i];
	}
	
	
	//测试原始冒泡排序时间
	cout << "Original bubble sort:" << endl;
	time_t t_start1 = clock();
	BubbleSort(a, maxsize);
	time_t t_end1 = clock();
	cout << "Time cost: \t" << get_time(t_start1,t_end1) << " ms" << endl;
	cout << endl;
	
///////////////////////////////////////////////////////////////////////////////////
	cout << "Bubble sort with flag:" << endl;
	time_t t_start2 = clock();
	BubbleSortWithFlag(b, maxsize);
	time_t t_end2 = clock();
	cout << "Time cost: \t" << get_time(t_start2,t_end2) << " ms" << endl;
	cout << endl;
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
	cout << "Bubble sort with index:" << endl;
	time_t t_start3 = clock();
	BubbleSortWithIndex(c, maxsize);
	time_t t_end3 = clock();
	cout << "Time cost: \t" << get_time(t_start3,t_end3) << " ms" << endl;
	cout << endl;
///////////////////////////////////////////////////////////////////////////////////

	//测试优化后冒泡排序时间
	cout << "Cocktail sort: \t" << endl;
	time_t t_start4 = clock();
	CocktailSort(d, maxsize);
	time_t t_end4 = clock(); 
	cout << "Time cost: \t" << get_time(t_start4,t_end4) << " ms" << endl;
	cout << endl;
	
	return 0;
}

/**
 * @brief 基本冒泡排序
 * @brief 最好、最坏和平均情况时间复杂度都是O(n^2)
 * @param arr
 * @param n
 * @return 
 */
void BubbleSort(int *arr, int n)
{
	int count = 0;
	int compare = 0;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			compare++;
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
				count++;
		}
	}
	//show_array(arr, n);
	cout << "Compare count:\t" << compare << endl;
	cout << "Swap count:\t" << count << endl;
}


/**
 * @brief 带标志的冒泡排序
 * @brief 若循环中没有发生过交换，即所有的元素有序，跳出后续循环结束排序
 * @brief 最好情况时间复杂度为O(n)，最坏和平均情况时间复杂度为O(n^2)
 * @param arr
 * @param n
 */
void BubbleSortWithFlag(int *arr, int n)
{
	bool isSorted = false;
	int count = 0;
	int compare = 0;
	for(int i = 0; i < n - 1; i++)
	{
		isSorted = true;
		for(int j = 0; j < n - i - 1; j++)
		{
			compare++;
			if(arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				count++;
				isSorted = false;
			}
		}
		if(isSorted)	break;
	}
	//show_array(arr, n);
	cout << "Compare count:\t" << compare << endl;
	cout << "Swap count:\t" << count << endl;
}


/**
 * @brief 记录未排序最后位置的冒泡排序
 * @brief 每次循环记录最后一次发生交换的元素的位置，跳过之后有序元素
 * @brief 最好情况时间复杂度为O(n)，最坏和平均情况时间复杂度为O(n^2)
 * @param arr
 * @param n
 */
void BubbleSortWithIndex(int *arr, int n)
{
	bool SortOver = false;    //排序结束标志
	int count = 0;
	int compare = 0;
	int LastSwapSite = n - 1;	//记录最后交换位置
	
	for(int i = n-1; i > 0; i = LastSwapSite) 
	{    
		SortOver = true;	//每次进入排序，先SortOver为真
		for(int j = 0; j < i; ++j)
		{
			compare++;
			if(arr[i] > arr[i + 1])
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
	cout << "Compare count:\t" << compare << endl;
	cout << "Swap count:\t" << count << endl;
}
 


/**
 * @brief 双向扫描的冒泡排序(鸡尾酒排序)
 * @brief 同时扫描最后一次发生交换的首元素与末元素的位置up，low
 * @brief 当low>=up的时候证明整个数组有序
 * @brief 最好情况时间复杂度为O(n)，最坏和平均情况时间复杂度为O(n^2)
 * @param arr
 * @param n
 * @return 
 */
void CocktailSort(int *arr, int n)
{
	int low, up, index;
	low = index = 0;
	up = n - 1;
	int count = 0;
	int compare = 0;
	while(up > low)
	{
		for(int i = low; i < up; i++)
		{
			compare++;
			if(arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				count++;
				index = i;
			}
		}
		up = index;
		for(int i = up; i > low; i--)
		{
			compare++;
			if(arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
				count++;
				index = i;
			}
		}
		low = index;
	}
	//show_array(arr, n);
	cout << "Compare count:\t" << compare << endl;
	cout << "Swap count:\t" << count << endl;
}

/**
 * @brief 选择排序
 * @brief 每一趟扫描时，同时选出最大和最小值 
 * @brief 如果最大值在最左边，肯定要被移走，此时要转移到相应的新位置 
 * @param arr
 * @param n
 */
void SelectSort(int* arr, int n)
{
	int min, max, left, right;
	for(left = 0, right = n - 1; left < right; left++, right--)
	{
		min = left;
		max = right;
		for(int i = left; i <= right; i++)
		{
			if(arr[i] < arr[min])
				min = i;
			else if(arr[i] > arr[max])
				max = i;
		}
		if(min != left)
		{
			swap(arr[left], arr[min]);
			if (max == left) 	//如果最大值在最左边，肯定要被移走，此时要转移到相应的新位置 
				max = min;
		}    
       if (max != right)
			swap(arr[right], arr[max]);
	}
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
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

int get_time(time_t t_start, time_t t_end)
{
	return (t_end - t_start)*1000/CLOCKS_PER_SEC;
}