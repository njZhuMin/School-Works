#include <vector>
#define MAXV 10
#define INFINITY 999
using namespace std;

//图类型定义:{无向图，无向网，有向图，有向网}
enum GraphType{undigraph, digraph, undinetwork, dinetwrok};

/**
 * 边类型定义
 */
template <class T>
struct EdgeType
{
	T head, tail;
	int cost;
	EdgeType()	{}
	EdgeType(T head, T tail, int cost)
	{
		this->head = head;
		this->tail = tail;
		this->cost = cost;
	}
};

template <class T>
struct Edge
{
	T adjvex;
	int lowcost;
};

template <class T>
class MGraph
{
private:
	int vexnum, edgenum;
	GraphType kind;
	vector<vector<int> >edges;	//二维邻接矩阵
	vector<T> vexs;	//顶点表

	
public:
	MGraph(GraphType t, T v[], int  n, int e);
	~MGraph(){};
	int getVexterNum();		//返回顶点数量
	int getEdgeNum();			//返回边数量
	T getVexValue(int i);		//返回第i个顶点的值
	int getVexValueNum(T v);	//返回表中值的序号
	int getEdgeValue(int i, int j);	//返回邻接矩阵中第i个顶点到第j个顶点的权值
	void InsertVex(T v);				//插入一个顶点
	void RemoveVex(T v);				//删除一个顶点
	void InsertEdge(EdgeType<T> e);	//插入一条边
	void DeleteEdge(EdgeType<T> e);	//删除一条边
	void DFS(int v, bool* visited);		//连通图深度优先遍历算法
	void DFSTraverse();	//图的深度优先遍历	
	void BFSTraverse();	//图的广度优先遍历
	void PrintEdges();	//遍历邻接矩阵
	void PrintVexs();		//遍历顶点表

	void Prim(int v);		//Prim算法求最小生成树
	void Kruskal(vector<EdgeType<T> > &tree);	//Kruskal算法构造最小生成树
	int getMiniNum(Edge<T>* edges);
	void getGraph(vector<EdgeType<T> > &graph);
	void Dijkstra(int v,int path[], int dist[]);
	void Floyd(int* path[MAXV], int* D[MAXV]);
};