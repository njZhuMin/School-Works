#include <iostream>
#include "SeqStack.cpp"
using namespace std;

//declaration
double Expression_Eval();

//定义字符串表
static char pred[7][7] = {'>','>','<','<','<','>','>',
                   '>','>','<','<','<','>','>',
				   '>','>','>','>','<','>','>',
				   '>','>','>','>','<','>','>',
				   '<','<','<','<','<','=',' ',
				   '>','>','>','>',' ','>','>',
				   '<','<','<','<','<',' ','='};


int main()
{
	cout << "Please input a calculation ending with @:" << endl;
	double result = Expression_Eval();
	cout << result << endl;
	return 0;
}

char Precede(int i,int j)
{
	return pred[i][j];
}

int OPNDtoInt(char ch)
{
	switch (ch)
	{
		case '+':	return 0;
		case '-':	return 1;
		case '*':	return 2;
		case '/':	return 3;
		case '(':	return 4;
		case ')':	return 5;
		case '@':	return 6;
		default:	return -1;
	}   
}


double Operate(double left,char pre_op,double right)
{
	switch(pre_op)
	{
		case '+':	return left + right;
		case '-':	return left - right;	
		case '*':	return left * right;
		case '/':
		{
			if(right == 0)
			{
				cerr<<"Divider cannot be 0!";
				exit(1);
			}
			return (left / right);
			break;
		}

		default :
		{
			cerr<<"Calculation error!"<<endl;
			exit (1);
		}
	}
}


double Expression_Eval()
{
	SeqStack<char,100> OPTR;            // 定义操作符栈
	SeqStack<double,100> OPND;          // 定义操作数栈
	OPTR.Push('@');
	char ch = getchar();
	while(ch != '@' || OPTR.Top() != '@')
	{
		if(ch >= '0' && ch <= '9')
		{
			OPND.Push(ch - '0');
			ch = getchar();
		}                               
		else                            
		{
			char pre_op = OPTR.Top();
			switch (Precede(OPNDtoInt(pre_op), OPNDtoInt(ch)))
			{
			case '<':
				OPTR.Push(ch);
				ch = getchar();
				break;
			case '=':
				OPTR.Pop();
				ch = getchar();
				break;
			case '>':
				double right = OPND.Pop();
				double left = OPND.Pop();
				pre_op = OPTR.Pop();
				OPND.Push(Operate(left,pre_op,right));
				break;
			}
		}
	}
	return OPND.Top();
}
