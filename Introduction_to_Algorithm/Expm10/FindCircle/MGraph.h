#ifndef MGRAPH_H
#define MGRAPH_H

#define MAX_Num 20
template<class VexType,class ArcType>  
class MGraph  
{  
public:  
    void CreateGraph();//创建图  
    int LocateVex(VexType v);//返回顶点v所在顶点向量中的位置（下标）  
    void CheckCircle();  
private:  
    VexType vexs[MAX_Num];//顶点向量  
    ArcType arcs[MAX_Num][MAX_Num]; //这里把邻接矩阵类型用模板表示，主要是为了处理有权值的情况，比如：权值可以为小数（代价），也可以为整数  
    int vexnum;//顶点数  
    int arcnum;//边数  
private:  
    void DFS(int x,bool visited[MAX_Num],int stack[MAX_Num],int& top,bool inStack[MAX_Num],int& count);  
  
};

#endif // MGRAPH_H
