#include <iostream>
using namespace std;

void InsertSort(int* arr, int n); 
int ChoosePivot(int* arr, int left, int right);
int getPartition(int* arr, int left, int right);
int QuickSort(int* arr, int i, int j, int target);
void swap(int &a, int &b);

int main()
{
	int arr[] = {3,4,6,1,5,9,2,8,7};
    QuickSort(arr, 0, 8, 5);
	for(int i = 0;i < 9; i++)
        cout << QuickSort(arr, 0, 8, i) << "  ";
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
 
int ChoosePivot(int* arr, int left, int right)
{
    int size = right - left + 1;
    int sub_num = size / 5;
    int i, j, k = 0;
    int temp[sub_num][5];
    int sub[sub_num];
    for(i = 0; i < sub_num; i++)
	{
        for(j = 0; i < 5; j++)
			temp[i][j] = arr[k++];
        sub[i] = QuickSort(temp[i], 0, 4, 2);
    }
     return QuickSort(sub, 0, sub_num - 1, sub_num / 2);
}
/**
 * @brief 快速排序数组划分算法
 * @param arr
 * @param left
 * @param right
 * @return 
 */
int getPartition(int* arr, int left, int right, int m)  
{  
	int x = arr[m];
    int i = left;
    int j = left + 1;
    swap(arr[m], arr[left]);
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
int QuickSort(int* arr, int left, int right, int target)
{
	if(target > right)
		return -1;
	if(left < right)
	{
        if(right - left + 1 < 10)
		{
            int temp[right - left + 1];
            for(int i = left; i < right - left + 1; i++)
                temp[i] = arr[i];
            InsertSort(temp, right - left + 1);
            return temp[target];
        }
 
        int m = ChoosePivot(arr, left, right);
        int pivot = getPartition(arr, left, right, m);
        if(pivot == target)
			return arr[pivot];
        else if(pivot > target)
            return QuickSort(arr, left, pivot - 1, target);
        else
            return QuickSort(arr, pivot + 1, right, target);
    }
    else return arr[left];
}


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
