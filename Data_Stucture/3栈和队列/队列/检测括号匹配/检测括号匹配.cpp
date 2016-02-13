#include <cstdlib>  
#include <iostream>  
#define STACK_SIZE  100  
using namespace std;

typedef struct{  
    char *base;			//栈底指针
    char *top;  		//栈顶指针
    int stacksize;  	//栈大小
 }SqStack;  
 
//栈的初始化
int InitStack(SqStack &s)  
{  
	//申请栈底指针空间
    s.base = (char *) malloc (STACK_SIZE * sizeof(char));  
	//检测是否初始化成功
    if(s.base == NULL)  
		return 0;  
	s.top = s.base;  
    s.stacksize = STACK_SIZE;  
	return 0;  
 }   
 
//入栈操作
int Push(SqStack &s,char c)  
{  
	//栈满，重分配空间
    if(s.top - s.base >= s.stacksize)
	{  
        s.base = (char *) realloc (s.base, (s.stacksize+100)*sizeof(char));  
    }  
    if(s.base == NULL)  
		return 1; 
	//c入栈
    *s.top++ = c;  
    return 0;  
 }  

//出栈操作
int Pop(SqStack &s,char &c)  
{  
	//栈空
	if(s.top == s.base)  
		return 1;  
	c = *--s.top;  
	return 0;  
}  

int main()  
 {  
	SqStack s;  
	InitStack(s);  
	int i;
	char *pc="([]()[])";
	char *pcx=pc;  
	char c;  
	for(i=0; pcx[i]!=0; i++)
	{
		//左括号入栈
        if(pcx[i]=='(' || pcx[i]=='[')  
		{
			Push(s,pcx[i]);  
			//向后为空，则不匹配
			if(pcx[i+1] == NULL)
			{
				cout << "Not match!" << endl;  
                exit(1);  
			}
		}
        else
		{
            Pop(s,c);
			//检测是否有匹配的右括号
            c = c=='('? ')' :']';
            if(c != pcx[i])
            {
                cout << "Not match!" << endl; 
				exit(1); 
            }
         } 
    }
	cout << "Tokens match!" << endl;
	return 0;
 }