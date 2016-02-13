#include <iostream>
using namespace std;

void Merge(int* arr, int first, int mid, int last, int* temp);
void MergePass(int* arr, int first, int last, int* temp);
void MergeSort(int* arr, int n);

int main()
{
	int a[10] = {3,2,1,6,9,8,7,4,5,10};
	MergeSort(a,10);
	for(int i = 0; i < 10; i++)
		cout << a[i] << "  ";
	return 0;
}

/**
 * @brief 一次归并算法
 * @param arr
 * @param first
 * @param mid
 * @param last
 * @param temp
 */
void Merge(int* arr, int first, int mid, int last, int* temp)  
{  
    int i = first, j = mid + 1;  
    int m = mid, n = last;  
    int k = 0;  
    while(i <= m && j <= n)  
    {  
		if(arr[i] <= arr[j])  
			temp[k++] = arr[i++];  
        else  
			temp[k++] = arr[j++];  
	}  
	while(i <= m)  
		temp[k++] = arr[i++];  
	while(j <= n)  
		temp[k++] = arr[j++];  
	for(i = 0; i < k; i++)  
		arr[first + i] = temp[i];  
}  

/**
 * @brief 一趟归并算法
 * @param arr
 * @param first
 * @param last
 * @param temp
 */
void MergePass(int* arr, int first, int last, int* temp)  
{  
	if(first < last)  
	{  
		int mid = (first + last) / 2;  
		MergePass(arr, first, mid, temp);    //左边有序  
		MergePass(arr, mid + 1, last, temp); //右边有序  
		Merge(arr, first, mid, last, temp); //再将二个有序数列合并  
    }
}  

/**
 * @brief 归并排序算法
 * @param arr
 * @param n
 */
void MergeSort(int* arr, int n)  
{  
	int *temp = new int[n];  
	if(temp == NULL)  
		return;  
	MergePass(arr, 0, n - 1, temp);  
	delete[] temp;  
}  

