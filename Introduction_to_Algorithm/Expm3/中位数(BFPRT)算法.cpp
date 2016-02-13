#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void InsertSort(int* arr, int n); 
int BFPRT(int* arr, int left, int right, int id);
int getPartition(int* arr, int left, int right, int pivotId);

void swap(int &a, int &b);

int main()
{
	int arr[20];
	srand((unsigned)time(NULL));	//初始化随机数种子 
	for(int i = 0; i < 20; i++)
	{
		arr[i] = rand() % 50;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Median of Array is " << BFPRT(arr, 1, 20, 10) << endl;
    return 0;
}

void InsertSort(int* arr, int n)  
{  
	for(int i = 1; i < n; i++)
	{
		for(int j = i-1; j >= 0 && arr[j] > arr[j + 1]; j--)
		{
			swap(arr[j], arr[j + 1]);
		}
	}
}

/**
 * @brief BFPRT算法，又称中位数算法,由5位大牛(Blum,Floyd,Pratt,Rivest,Tarjan)提出
 * @param arr 数组
 * @param left 左边界
 * @param right 右边界
 * @param id A[left,...,right]中第id个数
 * @return 
 */
int BFPRT(int* arr, int left, int right, int id)
{
	//小于等于5个数，直接排序得到结果
	if (right - left + 1 <= 5)		
	{
		InsertSort(arr, right - left + 1); 
		return arr[left + id - 1];
	}

	int t = left - 1;	//当前替换到前面的中位数的下标
	int start, end;
	for(start = left; (end = start + 4) <= right; start += 5)	//每5个进行处理
	{
		InsertSort(arr, end - start + 1); 	//5个数的排序
		t++;
		swap(arr[t], arr[start + 2]); 	//将中位数替换到数组前面，便于递归求取中位数的中位数
	}

	int pivotId = (left + t) / 2; 		//l到t的中位数的下标，作为主元的下标
	BFPRT(arr, left, t, pivotId- left + 1);		//不关心中位数的值，保证中位数在正确的位置
	
	int m = getPartition(arr, left, right, pivotId);
	int current = m - left + 1;
    if (id == current)		//刚好是第id个数
		return arr[m]; 	
    else if(id < current)		//第id个数在左边
		return BFPRT(arr, left, m - 1, id);		
    else 			//第id个数在右边
		return BFPRT(arr, m + 1, right, id - current); 	
}

/**
 * @brief 以pivotId所在元素为划分主元
 * @param arr
 * @param left
 * @param right
 * @return 
 */
int getPartition(int* arr, int left, int right, int pivotId)  
{  
	swap(arr[pivotId], arr[right]);
	
    int j = left - 1; 		//左边数字最右的下标
    for(int i = left; i < right; i++)
	{
        if (arr[i] <= arr[right]) 
            swap(arr[++j], arr[i]);
	}
    swap(arr[++j], arr[right]);
    return j;
}  

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
