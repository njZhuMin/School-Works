#include <iostream>
using namespace std;  

int LIS_DP(int *array, int n);

int main()  
{  
	int data[6] = {5, 6, 7, 1, 2, 8};
	cout << LIS_DP(data, 6) << endl;
}  

int LIS_DP(int *array, int n)
 {
     int LIS[n];
     for(int i = 0; i < n; i++)
         LIS[i] = 1;
     
     for(int i = 1; i < n; i++)
     {
         int maxLen = 0;
         for(int j = 0; j < i; j++)
         {
             if(array[i] > array[j])
             {
                 if(maxLen < LIS[j])
                     maxLen = LIS[j];
             }
         }
         LIS[i] = maxLen + 1;
     }
     int maxLIS = 0;
     for(int i = 0; i < n; i++)
     {
         if(maxLIS < LIS[i])
             maxLIS = LIS[i];
     }
     return maxLIS;
 }