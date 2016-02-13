/** 
* 斐波那契数列算法，从第三个数开始，每个数是前两个数之和：1 1 2 3 5 8 13 21 34 55 
* 求第N个数的两种算法，分递归和非递归两种 
*/ 
#include <iostream>
#include <stdlib.h>
using namespace std;
        
//递归方式 
int f(int n) 
{ 
    //参数合法性验证 
    if (n < 1) { 
        cerr << "n must larger than 1 !";
		exit(1);
    } 
    if (n == 1 || n == 2) 
		return 1; 
    else 
		return f(n - 1) + f(n - 2); 
} 

//非递归方式 
int fx(int n)
{ 
//参数合法性验证 
    if (n < 1) { 
        cerr << "n must larger than 1 !";
		exit(1);
	}
    //n为1或2时候直接返回值 
    if (n == 1 || n == 2) return 1; 
	//n>2时候循环求值 
    int result = 0; 
    int a = 1; 
    int b = 1; 
    for (int i = 3; i <= n; i++)
	{ 
        result = a + b; 
        a = b; 
        b = result; 
    } 
    return result; 
} 

int main()
{
	cout << f(20) << endl;
	cout << fx(20) << endl;
	return 0;
}