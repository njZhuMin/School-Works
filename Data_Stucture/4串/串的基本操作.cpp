#include <iostream>
#include <cstring>
using namespace std;

#define MaxSize 100

//串连接
void StrCat(char * s1,char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len1 + len2 > MaxSize-1)
	{
		cerr << "String overlength!" << endl;
		exit(1);
	}
	int i = 0;
	while (s2[i]!='\0')
	{
		s1[i+len1] = s2[i];
		i++;
	}
	s1[i+len1] = '\0';
}


//串比较
int StrCmp(char* s1,char* s2)
{
	int i = 0;
	while (s1[i]==s2[i] && s1[i]!='\0')
	{
		i++;
	}
	return (s1[i] -s2[i]);
}


//串复制
void StrCpy(char* s1,char* s2)
{
	int len = strlen(s2);
	if(len > MaxSize-1)
	{
		cerr << "String overlength!" << endl;
		exit(1);
	}
	while((*s1++ = *s2++));
}

//BF串匹配算法
int BFmatching(char* s,char* t)
{
	int i,j,n,m;
	i = 0;
	j = 0;
	n = strlen(s);
	m = strlen(t);
	while(i < n && j < m)
	{
		if(s[i] == t[j])
		{
			i++;
			j++;
		}
		else 
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if(j >= m)
		return i-j;
	else
		return -1;
}

//返回子串及其以后的字符
char* StrStr(char* s,char* t)//s为主串，t为子串
{
	//char* temp = "";
	int i,j,n,m;
	i = 0;
	j = 0;
	n = strlen(s);
	m = strlen(t);
	while(i < n && j < m)
	{
		if(s[i] == t[j])
		{
			i++;
			j++;
		}
		else 
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if(j >= m)
	{
		return s+i-j;
	}
	else
	{
		cout << "Sub string not Found!";
		exit(1);
	}
}

//补充题：两个字符串的比较
int strcmp(char s[],char t[])
{
	int i;
	for(i=0 ; s[i]&&t[i] ; i++)
	{
		if(s[i]!=t[i])
			return (s[i] -t[i]);
	}
	return 0;

}
int main()
{
	//字符数组测试
	char s1[] = "Are you kidding?";
	char s2[] = "No I'm serious.";

	char s3[] = "abcdefgabcdef";
	char s4[] = "bcd";
	char s5[] = "fg";
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
	cout << "s5:" << s5 << endl;
	
	//字符数组连接测试
	cout << "After connection:" << endl;
	StrCat(s1,s2);
	cout << s1 << endl;
	
	//字符数组比较测试
	int i = StrCmp(s1,s2);
	cout << "After comparation:" << endl;
	if(i>0)
	{
		cout << "s1 > s2" << endl;
	}
	else if(i==0)
	{
		cout << "s1 = s2" << endl;
	}
	else
	{
		cout << "s1 < s2" << endl;
	}

	//字符数组拷贝测试
	StrCpy(s1,s2);
	cout << "After copy:" << endl;
	cout<< "s1:" << s1 << endl;
	cout<< "s2:" << s2 << endl;

	//字符数组主串子串匹配测试
	int j = BFmatching(s3,s4);
	if(j == -1)
	{
		cout << "Sub string not Found!" << endl;
	}
	else
	{
		cout << "First position s3 containing s4 is " << j << endl;
	}


	//StrStr返回子串及其以后的字符测试
	cout << "Main string:" << s3 << endl;
	cout << "Sub string:" << s5 << endl;
	cout << "Chars after sub string position:" << endl;
	cout << StrStr(s3,s5) << endl;


	//字符数组比较测试
	int k = strcmp(s1,s2);
	cout << "After comparation:" << endl;
   	if(k > 0)
	{
		cout << "s1 > s2" << endl;
	}
	else if(k==0)
	{
		cout << "s1 = s2" << endl;
	}
	else
	{
		cout << "s1 < s2" << endl;
	}

	//string测试
	string st1 = "Are you kidding?";
	string st2 = "No I'm serious.";
	cout << "st1:" << st1 << endl;
	cout << "st2:" << st2 << endl;

	//string连接测试
	st1 = st1 + st2;
	cout << "After connection:" << st1 << endl;
	
	//string比较测试
	cout << "After Comparation:" << endl;
	if(st1 > st2)
	{
		cout << st1 << ">" << st2 << endl;
	}
	else if(st1 == st2)
	{
		cout << st1 << "=" << st2 << endl;
	}
	else
	{
		cout << st1 << "<" << st2 << endl;
	}

	//string拷贝测试
	st1 = st2;
	cout << "After copy:" << endl;
	cout << "st1:" << st1 << endl;
	cout << "st2:" << st2 << endl;

	return 0;
}

