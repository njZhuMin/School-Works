#include <iostream>
using namespace std;

void Split(int *arr, int begin, int end, int v, int &left, int &right);
void swap(int &a, int &b);

int main()
{
	int a[10] = {2,6,9,8,3,4,7,1,6,7};
	int i = 0;
	int left = 0;
	int right = 0;
	
	Split(a, 0, 9, 6, left, right);
	
	for(i = 0; i < left; i++)
		cout << a[i] << "  ";
	cout << endl;
	
	for(i = left; i < right; i++)
		cout << a[i] << "  ";
	cout << endl;
	
	for(i = right; i < 10; i++)
		cout << a[i] << "  ";
	cout << endl;
	return 0;
}

/**
 * @brief 以一个数组arr和一个值v为输入，将数组s划分成3个子集：
 * @brief 比v小的元素组成的集合，等于v的元素组成的集合，比v大的元素组成的集合
 * @param arr		待分割数组
 * @param begin		数组左边界
 * @param end		数组右边界
 * @param v			pivot
 * @param left		arr[begin]~arr[left-1] < v; arr[left]~arr[right-1] = v
 * @param right		arr[right]~arr[end] > v
 */
void Split(int *arr, int begin, int end, int v, int &left, int &right)
{
	left = begin;
	for (int i = begin; i < end; ++i)
	{
		if (arr[i] < v)
			swap(arr[i], arr[left++]);
	}
	right = left;
	for (int j = left; j < end; ++j)
	{
		if (arr[j] == v)
			swap(arr[j], arr[right++]);
	}
}

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}