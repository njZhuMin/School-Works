#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{  
    int value;  
    struct node *next;  
}LinkList;  
  
void CreateList(LinkList *L); //建立一个链表  
void Output(LinkList *L,int k);  //输出倒数第k个结点的值  
  
int main()  
{  
    int k;  
    LinkList *L=(LinkList*)malloc(sizeof(LinkList));  
    L->next=NULL;  
      
    CreateList(L);  
  
    while (printf("Please input K:  "),scanf("%d",&k)!=EOF)  //输入倒数第几个结点k  
    {  
        Output(L,k);  
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
  
  
void Output(LinkList*L,int k)  
{  
    LinkList *tail=L,*head=L;    
    int i;  
    if (k<=0)  //如果k小于等于0，退出  
    {  
        printf("Input error!\n");  
        return;  
    }  
    for (i=0;i<k;i++)    //tail指针先走  
    {  
        tail=tail->next;  
        if (tail==NULL)    //如果k输入过大，退出  
        {  
            printf("No such node !\n");  
            return;  
        }  
    }  
  
    while(tail!=NULL&&head!=NULL)  //tail和head指针一起走  
    {  
        tail=tail->next;  
        head=head->next;  
    }  
    printf("%d\n",head->value);  
}  