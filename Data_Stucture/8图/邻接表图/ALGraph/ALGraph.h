#ifndef ALGRAPH_H
#define ALGRAPH_H
#include <iostream>
#include <vector>
using namespace std;

enum GraphType{undigraph, digraph, undinetwork, dinetwrok};

/**
 * 边表的结点结构类型
 */
struct EdgeNode
{
	int adjvex;	//边的终点位置
	EdgeNode* nextedge;	//指向下一条边的指针
	EdgeNode(){}
	EdgeNode(int v):adjvex(v), nextedge(NULL){}	//空构造
};

/**
 * 顶点表元素结构类型
 */
template <class T>
struct VexNode
{
	T data;	//顶点信息
	EdgeNode* firstedge;	//指向该顶点对应边表指针
};

template <class T>
class ALGraph
{
private:
	int vexnum, edgenum;					//顶点数，边数
	vector<VexNode<T> > adjlist;			//顶点表
	GraphType kind;						//图的类型标记
	void DFS(int v, bool* isVisited);	//连通图深度优先遍历
	bool appendEdge(T v);					//在顶点的邻接表中加入一条边
	bool removeEdge(int v);				//在顶点的邻接表中删除一条边
	void clearEdgeList();					//清空一个顶点的邻接表，释放邻接表各节点

public:
	ALGraph(GraphType t, T vexs[], int n, int e);	//构造函数
	~ALGraph();	//析构函数
	
	/**返回指针的函数不方便遍历！！！*/
	//EdgeNode* getFirstAdjVex(int v);	//返回第v个顶点对应边表头指针
	/**重载返回第v个顶点对应边表头指针函数*/
	int getFirstAdjVex(int v);			//重载返回第v个顶点对应边表头函数
	int getNextAdjVex(int v, int w);	//v相对于w的下一个邻接点
	
	int getVexterNum();				//返回顶点数量
	int getEdgeNum();					//返回边的数量
	T getVexValue(int i);				//返回第i个顶点的值
	int getVexValueNum(T v);			//返回表中值的序号
	
	bool insertVex(T v);				//插入一个顶点
	bool removeVex(T v);				//删除一个顶点
	bool insertEdge(VexNode<T> e);	//插入一条边
	bool deleteEdge(VexNode<T> e);	//删除一条边
	void DFSTraverse();				//深度优先遍历图
	void BFSTraverse();				//广度优先遍历图
	void TopoSort();					//拓补排序算法
};

#endif // ALGRAPH_H
