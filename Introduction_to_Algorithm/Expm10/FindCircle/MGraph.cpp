#include "MGraph.h"
#include <iostream>
using namespace std;

template<class VexType,class ArcType>  
void MGraph<VexType,ArcType>::CreateGraph()  
{  
    VexType first;  
    VexType Secend;  
    cout<<"请输入顶点数:";  
    cin>>vexnum;  
    cout<<"请输入边数:";  
    cin>>arcnum;  
    cout<<"请输入各个顶点值：";  
    for (int i=0;i<vexnum;i++)  
    {  
        cin>>vexs[i];  
    }  
    //初始化邻接矩阵  
    for (int i=0;i<arcnum;i++)  
    {  
        for (int j=0;j<arcnum;j++)  
        {  
            arcs[i][j]=0;  
        }  
    }  
    cout<<"请输入边的信息:"<<endl;  
    for (int i=0;i<arcnum;i++)  
    {  
        cin>>first>>Secend;  
        //如果边有权值的话，则还应该输入权值  
        int x = LocateVex(first);  
        int y = LocateVex(Secend);  
        arcs[x][y]=1;//如果是有权的话，这里应该是arc[x][y]=权值  
    }  
}   
/* 
参数：v：表示顶点向量中一个值 
函数返回值：函数返回v在顶点向量中的下标 
*/  
template<class VexType,class ArcType>  
int MGraph<VexType,ArcType>::LocateVex(VexType v)  
{  
    for (int i=0;i<vexnum;i++)  
    {  
        if (vexs[i]==v)  
        {  
            return i;  
        }  
    }  
    return -1;  
}  
  
/* 
检查图中是不是有回向边 
思想： 
如果有回向边，则无环，反之有环 
*/  
template<class VexType,class ArcType>  
void MGraph<VexType,ArcType>::CheckCircle()  
{  
    int count=0;//环的个数  
    int top=-1;  
    int stack[MAX_Num];  
    bool inStack[MAX_Num]={false};  
    bool visited[MAX_Num]={false};  
    for (int i=0;i<vexnum;i++)  
    {  
        if (!visited[i])  
        {  
            DFS(i,visited,stack,top,inStack,count);  
        }  
    }  
}  
  
template<class VexType,class ArcType>  
void MGraph<VexType,ArcType>::DFS(int x,bool visited[MAX_Num],int stack[MAX_Num],int& top,bool inStack[MAX_Num],int& count)  
{  
    visited[x]=true;  
    stack[++top]=x;  
    inStack[x]=true;  
    for (int i=0;i<vexnum;i++)  
    {  
        if (arcs[x][i]!=0)//有边  
        {  
            if (!inStack[i])  
            {  
                DFS(i,visited,stack,top,inStack,count);  
            }  
            else //条件成立，表示下标为x的顶点到 下标为i的顶点有环  
            {  
                count++;  
                cout<<"第"<<count<<"环为:";  
                //从i到x是一个环，top的位置是x，下标为i的顶点在栈中的位置要寻找一下  
                //寻找起始顶点下标在栈中的位置  
                int t=0;  
                for (t=top;stack[t]!=i;t--);  
                //输出环中顶点  
                for (int j=t;j<=top;j++)  
                {  
                    cout<<vexs[stack[j]];  
                }  
                cout<<endl;  
            }  
        }  
    }  
    //处理完结点后，退栈  
    top--;  
    inStack[x]=false;  
}  

