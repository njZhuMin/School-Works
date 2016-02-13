#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
}LinkList;

void CreateList(LinkList *L); //建立一个链表
int GetLength(LinkList *L);  //获取链表长度
int Output(LinkList *L,int len,int k); //输出长度为len的链表的倒数第k个结点的值

int main()
{
	int n,k;
	LinkList *L=(LinkList*)malloc(sizeof(LinkList));
	L->next=NULL;
	
	CreateList(L);
	n=GetLength(L);

	while (printf("Please input K:  "),scanf("%d",&k)!=EOF)  //输入倒数第几个结点k
	{
		if (k>n-1)  
		{
			printf("Sorry,no such Node!\n\n");
			continue;
		}
		printf("%d\n\n",Output(L,n,k));
	}
	return 0;
}

void CreateList(LinkList *L)
{
	int data;
	LinkList *s=NULL,*tail=L;

	while (printf("Input value:  "),scanf("%d",&data)!=EOF)
	{	
		s=(LinkList*)malloc(sizeof(LinkList));
		s->value=data;
		s->next=NULL;
		tail->next=s;
		tail=s;
	}
}

int GetLength(LinkList *L)
{
	LinkList *s=L->next;
	int count=0;
	while (s!=NULL)
	{
		count++;
		s=s->next;
	}
	return count;
}

int Output(LinkList*L,int len,int k)
{
	LinkList *s=L;
    int i;
	for (i=0;i<len-k;i++)
	{
		s=s->next;
	}

	return s->value;
}