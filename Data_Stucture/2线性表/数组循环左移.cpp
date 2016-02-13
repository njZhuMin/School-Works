#include <iostream>
using namespace std;
//declaration
void LeftShift(int *arr, int N, int k);
void LeftShift_2(int *arr, int N, int k);
void LeftShift_3(int *arr, int N, int k);
void Reverse(int *arr, int b, int e);

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	//左移前
	cout << "Before:" << endl;
	for (int i=0; i<10; i++){
		cout << a[i] << " ";	
	}
	cout << "\n" << endl;
	//左移后
	cout << "After leftshift 4 characters:" << endl;
	LeftShift_3(a,10,4);
	for (int i=0; i<10; i++){
		cout << a[i] << " ";	
	}
	cout << endl;
	return 0;
}

//逐位左移，时间复杂度O(k*N)
void LeftShift(int *arr, int N, int k)  
{  
	while(k--)  
	{  
		int temp = arr[0];  
		for(int i = 0 ; i < N-1 ; i++){  
			arr[i] = arr[i + 1];  
		}  
		arr[N-1] = temp;  
	}  
}  

void LeftShift_2(int *arr, int N, int k)  
{  
	k = k % N;	//复杂度从O(k*N)变为O(N2)
	while(k--)  
	{  
		int temp = arr[0];  
		for(int i = 0 ; i < N-1 ; i++){  
			arr[i] = arr[i + 1];  
		}  
		arr[N-1] = temp;  
	}  
}  

void LeftShift_3(int *arr, int N, int k)  
{  
	k = k % N ;  
	Reverse(arr, 0, k-1);     	//前面k部分逆序  
	Reverse(arr, k, N-1);     //后面N-k部分逆序  
	Reverse(arr, 0, N-1);       //全部逆序  
}  

void Reverse(int *arr, int b, int e)      //逆序排列  
{  
	for( ; b < e; b++, e--)		//从数组的前、后一起遍历 
	{    
		int temp = arr[e];  
		arr[e] = arr[b];  
		arr[b] = temp;  
	}  
}  



