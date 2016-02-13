#include <stdio.h>
#include <iostream>
using namespace std;

//n:原数(10进制)  to:将转换成的进制 
char* fn(int n, int to)
{
    //定义静态变量：为了在多层递归里面使用的是同一个值，且static只执行一次
    static char buf[100] = "";
	//定义进制表
	static char BinHex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    //进行n == 0 和 n < 0 的情况处理,static只执行一次
	static int i;
	if(n>=0)
	{
		buf[0] = '0';
		i = 0;
	}
	else
	{
		buf[0] = '-';
		n = -n;
		i = 1;
	}
    //正整数递归，进行进制转换.
    if (n != 0)   
    {
        //递归入栈
        fn(n/to,to);
        //递归弹栈
        buf[i++] = BinHex[n % to];
    }
    return buf;
}
 
int main()
{
    char *buf = NULL;
    int n, to;
    cout << "Input data to transform:" <<"\t"<< "Radix to transform to:"<<endl;
    cin>> n >> to;  
    //进制转换
    buf = fn(n,to);
	cout << "Data in " << to << " radix:" << endl;
    puts(buf);
    return 0;
}