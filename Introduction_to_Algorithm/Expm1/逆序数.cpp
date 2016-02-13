#include <iostream>
using namespace std;

void Merge_and_Count(int* arr, int first, int mid, int last, int* temp);
void MergePass(int* arr, int first, int last, int* temp);
void MergeSort(int* arr, int n);

int count = 0;

int main()
{
	int a[6] = {5,6,7,9,1,2};
	MergeSort(a,6);
	for(int i = 0; i < 6; i++)
		cout << a[i] << "  ";
	cout << endl << count << endl;
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
void Merge_and_Count(int* arr, int first, int mid, int last, int* temp)  
{  
    int i = first, j = mid + 1;  
    int m = mid, n = last;  
    int k = 0;  
    while(i <= m && j <= n)  
    {  
		if(arr[i] > arr[j])
		{  
			temp[k++] = arr[j++];  
			count += mid - i + 1;
		} 
        else  
			temp[k++] = arr[i++];  		 
	}  
	while(i <= m)  
		temp[k++] = arr[i++];  
	while(j <= n)  
		temp[k++] = arr[j++];  
	for(i = 0; i < k; i++)  
		arr[first + i] = temp[i];  
	//return count;
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
		MergePass(arr, first, mid, temp);    	//左边有序  
		MergePass(arr, mid + 1, last, temp); 	//右边有序  
		Merge_and_Count(arr, first, mid, last, temp); 	//再将二个有序数列合并  	
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
