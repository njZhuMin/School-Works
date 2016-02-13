#include <iostream>
#include <cstring>
using namespace std;

//declaration of functions
int BFmatching(char* s, char* t);
void getNext(char* t);
int KMPmatching(char* s, char* t);

int main()
{
	return 0;
}

//BF算法
int BFmatching(char* s, char* t)
{
	int i = 0;
	int j = 0;
	int n = strlen(s);
	int m = strlen(t);
	while(i < n && j < m)
	{
		if(s[i] == t[j])	//相等则后移
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+1;
			j = 0;		//回到字串首位比较
		}
	}
	if( j >= m)
		return (i-j);
	else
		return -1;
}

void getNext(char *t)
{
	int j = 0;
	int k = -1;	//next数组首位为-1
	int m = strlen(t);
	char* next = NULL;
	next[0] = -1;
	while(j < m-1)	//不回溯，只循环m-1次
	{
		if( k==-1 || t[j]==t[k] )
		{
			j++;
			k++;
			next[j] = k;	//匹配，下次从第k位起匹配
		}
		else
			k = next[k];
	}
}

int KMPmatching(char* s, char* t)
{
	int i = 0;
	int j = 0;
	int n = strlen(s);
	int m = strlen(t);
	char* next = NULL;
	while(i < n && j < m)
	{
		if( j==-1 || s[i]==t[j] )	//j==-1无任何匹配项
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if(j >= m)
		return (i - m);
	else
		return -1;
}