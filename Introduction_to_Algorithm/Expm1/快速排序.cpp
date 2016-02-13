#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int getPartition(int* arr, int left, int right);
void QuickSort(int* arr, int i, int j);
void swap(int &a, int &b);

int main()
{
	int a[20];
	srand((unsigned)time(NULL));
	for(int i = 0; i < 20; i++)
		a[i] = rand() % 50;
		
	cout << "Before QuickSort:" << endl;	
	for(int i = 0; i < 20; i++)
		cout << a[i] << "  ";
	
	QuickSort(a, 0, 19);
	
	cout << endl << "After QuickSort:" << endl; 	
	for(int i = 0; i < 20; i++)
		cout << a[i] << "  ";
	return 0;
}

/**
 * @brief 快速排序数组划分算法
 * @param arr
 * @param left
 * @param right
 * @return 
 */
int getPartition(int* arr, int left, int right)  
{  
	int t = rand() % (right-left);
    int x = arr[left + t];
    int i = left;
    int j = left+1;
    swap(arr[left + t], arr[left]);
    for(; j <= right; j++)
	{
        if(arr[j] <= x)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i], arr[left]);
    return i;  
}  

/**
 * @brief 快速排序算法
 * @param arr
 * @param i
 * @param j
 */
void QuickSort(int* arr, int i, int j)
{
	if(i < j)
	{
		int pivot = getPartition(arr, i, j);
		QuickSort(arr, i, pivot - 1);
		QuickSort(arr, pivot + 1, j);
	}
}


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
