#include "MGraph.h"
#include "SeqQueue.h"
#include <iostream>
#define MAXV 10
#define INFINITY 999

/**
 * @brief 构造函数
 * @param t 图的类型
 * @param v 各顶点数组
 * @param n 顶点数
 * @param e 边数
 */
template<class T>
MGraph<T>::MGraph(GraphType t, T v[], int  n, int e)
{
	int i, j;
	vexnum = n;
	edgenum = e;
	kind = t;
	vexs.resize(vexnum);
	edges.resize(vexnum);
	for(i = 0; i < n; i++)	//顶点赋值
		vexs[i] = v[i];
	for(i = 0; i < n; i++)	//resize邻边矩阵
		edges[i].resize(vexnum);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			if(i == j)		//对角线为0
				edges[i][j] = 0;
			else 
				edges[i][j] = INFINITY;
	}
	for (i = 0; i < e; i++)
	{
		int va, vb, w;
		cout << "Input two vexes and cost:" << endl;
		cin >> va >> vb >> w;
		if (kind == undigraph)
			edges[va][vb] = edges[vb][va] = w;
		else
			edges[va][vb] = w;
	}
}

/**
 * @brief 连通图深度优先遍历算法
 * @param v 第v个顶点
 * @param isVisited 访问标志
 */
template<class T>
void MGraph<T>::DFS(int v, bool* isVisited)
{
	int i;
	cout << vexs[v];	//访问第v个顶点
	isVisited[v] = true;
	for(i = 0; i < vexnum; i++)
	{
		if (edges[v][i] == 1 && !isVisited[i])
			DFS(i, isVisited);
	}
}

/**
 * @brief 图的深度优先遍历算法
 */
template<class T>
void MGraph<T>::DFSTraverse()
{
	int v;
	bool* isVisited = new bool[vexnum];		//建立访问标记数组
	for(v = 0; v < vexnum; v++)
		isVisited[v] = false;		//初始化，置访问flag为false
	for(v = 0; v < vexnum; v++)
	{
		if (!isVisited[v])
			DFS(v, isVisited);
	}
	delete []isVisited;
}

/**
 * @brief 图的广度优先遍历 
 */
template<class T>
void MGraph<T>::BFSTraverse()
{
	int i,j;
	SeqQueue<int, 10> q;
	bool* isVisited = new bool[vexnum];
	for(i = 0; i < vexnum; i++)
		isVisited[i] = false;
	for(i = 0; i < vexnum; i++)
	{
		if(!isVisited[i])
		{
			cout << vexs[i];
			isVisited[i] = true;
			q.EnQueue(i);
			while(!q.isEmpty())
			{
				T u = q.DeQueue();
				for(j = 0; j < vexnum; j++)
				{
					if(edges[u][j] == 1 && !isVisited[j])
					{
						cout << vexs[j];
						isVisited[j] = true;
						q.EnQueue(j);
					}
				}
			}
		}
	}
	delete []isVisited;
}

//返回顶点数量
template<class T>
int MGraph<T>::getVexterNum()
{
	return vexnum;
}

//返回边数量
template<class T>
int MGraph<T>::getEdgeNum()
{
	return edgenum;
}

//返回第i个顶点的值
template<class T>
T MGraph<T>::getVexValue(int i)
{
	if(i < vexnum)
		return vexs[i];
	else
		cout<< "Vex out of range!" << endl;
		return 0;
}

//返回表中值的序号
template<class T>
int MGraph<T>::getVexValueNum(T v)
{
	for (int i = 0; i < vexs.size(); i++)
	{
		if(vexs[i] == v)
			return i;
	}
	cout << "Value not match!" << endl;
	return 0;
}

//返回邻接矩阵中第i个顶点到第j个顶点的权值
template<class T>
int MGraph<T>::getEdgeValue(int i, int j)
{
	if(i < vexnum && j < vexnum)
		return edges[i][j];
	else 
		cout << "Invalid vex number!" << endl;
	return 0;
}

/**
 * @brief 插入一个顶点
 * @param v 顶点值
 */
template<class T>
void MGraph<T>::InsertVex(T v)
{
	int i;
	vexnum ++;
	//插入顶点表
	vexs.resize(vexnum);
	vexs[vexnum-1] = v;
	//扩充邻接矩阵
	edges.resize(vexnum);
	for(i = 0; i < vexnum; i++)
		edges[i].resize(vexnum);
	//插入邻接矩阵
	for(i = 0; i < vexnum;i++)
	{
		edges[i][vexnum-1] = edges[vexnum-1][i]=0;
	}
}

/**
 * @brief //删除一个顶点
 * @param v 顶点值
 */
template<class T>
void MGraph<T>::RemoveVex(T v)
{
	int i,j,n;
	for(i = 0; i < vexnum; i++)
	{
		if(vexs[i] == v)		//找到要删除的第i个顶点
			n = i;
	}
	/* std::vector::resize
	 * void resize (size_type n, value_type val = value_type());
	 * Change size
	 * Resizes the container so that it contains n elements.
	 * If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
	 * If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
	 * If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
	 * Notice that this function changes the actual content of the container by inserting or erasing elements from it.
	 */
	 
	/*
	if(n == vexnum)	//如果要删除的顶点为顶点表中最后一个顶点
	{
		vexnum = vexnum-1;
		vexs.resize(vexnum);
		for(i = 0; i < vexnum; i++)
		{	
			edges[i].resize(vexnum);
		}
		edges.resize(vexnum);
	}
	else
	{*/	
		for(j = n; j < vexnum; j++)	//在顶点表中删除
			vexs[j-1] = vexs[j];
		
		//在邻接矩阵中删除
		for(j = 0; j < vexnum; j++)	//删除第i行
		{
			edges[n][j] = edges[n+1][j] = 0;
		}
		
		for(j=0; j<vexnum; j++)	//删除第i列
		{
			edges[j][n] = edges[j][n+1] = 0;
		}
		
		//重置 vexs 和 edges的大小
		vexnum = vexnum - 1;
		vexs.resize(vexnum);
		for(i = 0; i < vexnum; i++)
		{	
			edges[i].resize(vexnum);
		}
		edges.resize(vexnum);
	//}
}

/**
 * @brief 插入一条边
 * @param e
 */
template<class T>
void MGraph<T>::InsertEdge(EdgeType<T> e)
{
	int i = 0, j = 0;
	while(vexs[i] != e.head)//找到起点的在顶点表中的序号
	{
		i++;
	}
	while(vexs[j] != e.tail)//找到终点的在顶点表中的序号
	{
		j++;
	}

	if(kind == undigraph)
		edges[i][j] = edges[j][i] = e.cost;
	else
		edges[i][j] = e.cost;	
}

/**
 * @brief 删除一条边
 * @param e
 */
template<class T>
void MGraph<T>::DeleteEdge(EdgeType<T> e)
{
	{
		int i = 0,j = 0;
		while(vexs[i] != e.head)//找到起点的在顶点表中的序号
		{
			i++;
		}
		while(vexs[j] != e.tail)//找到终点的在顶点表中的序号
		{
			j++;
		}
		
		if(kind == undigraph)
			edges[i][j] = edges[j][i] = 0;
		else
			edges[i][j] = 0;
	}
}

//遍历邻接矩阵
template<class T>
void MGraph<T>::PrintVexs()
{
	for(int i = 0; i < vexnum; i++)
	{	
		cout << vexs[i] << "\t";
	}
	cout << endl;
}

//遍历顶点表
template<class T>
void MGraph<T>::PrintEdges()
{
	int i,j;
	for(i = 0; i < vexnum; i++)
	{
		for(j = 0; j < vexnum; j++)
		{
			cout << edges[i][j] << "\t";
		}
		cout << endl;
	}
}

/**
 * @brief Prim算法求最小生成树
 * @param v
 */
template<class T>
void MGraph<T>::Prim(int v)
{ 
	int i,j;
	Edge<T>* miniedges = new Edge<T>[vexnum];
	for(i = 0; i < vexnum; i++)
	{
		miniedges[i].adjvex = getVexValue(v);
		miniedges[i].lowcost = getEdgeValue(v,i);
	}
	miniedges[v].lowcost = 0;
	
	for(i = 1; i < vexnum; i++)
	{
		int k = getMiniNum(miniedges);
		cout << miniedges[k].adjvex << "-->" << getVexValue(k) << endl;
		miniedges[k].lowcost = 0;
		for(j = 0; j < vexnum; j++)
		{
			if(getEdgeValue(k,j) < miniedges[j].lowcost)
			{
				miniedges[j].adjvex = getVexValue(k);
				miniedges[j].lowcost = getEdgeValue(k,j);
			}
		}
	}
	delete []miniedges;
}

/**
 * @brief Kruskal算法构造最小生成树
 * @param tree
 */
template <class T>
void MGraph<T>::Kruskal(vector<EdgeType<T> > &tree)
{
	int i;
	vector<EdgeType<T> > graph;
	getGraph(graph);
	tree.resize(vexnum-1);
	int* components = new int[edgenum];
	for(i = 0; i < vexnum; i++)
		components[i] = i;
	int k = 0;
	int j = 0;
	while(k < vexnum-1)
	{
		int h1 = getVexValueNum(graph[j].head);
		int t1 = getVexValueNum(graph[j].tail);
		int h2 = components[h1];
		int t2 = components[t1];
		if(h2 != t2)
		{
			tree[k].head = getVexValue(h1);
			tree[k].tail = getVexValue(t1);
			tree[k].cost = graph[j].cost;
			k++;
			for(i = 0;i < vexnum;i++)
				if(components[i] == t2)
					components[i] = h2;
		}
		j++;
	}
	delete []components;
}

template<class T>
int MGraph<T>::getMiniNum(Edge<T>* miniedges)
{
	int min = INFINITY,i = 0,k;
	while(i < vexnum)
	{	
		if(miniedges[i].lowcost != 0 && min > miniedges[i].lowcost)
		{		
			min = miniedges[i].lowcost;
			k = i;
		}	
		i++;
	}
	return k;	
}


template<class T>
void MGraph<T>::getGraph(vector<EdgeType<T> > &graph)
{
	graph.resize(edgenum);
	//int min = 0;
	int k = 0;
	int i,j;
	for(i = 0; i < vexnum; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(edges[j][i] < INFINITY && i != j)
			{
				graph[k].head = getVexValue(j);
				graph[k].tail = getVexValue(i);
				graph[k].cost = edges[j][i];
				k++;
			}
		}
	}
	EdgeType<T> e;
	for(i = 1; i < edgenum; i++)
	{
		for(j = edgenum-1; j >= i; j--)                                                                                                                                                                                                                                                                     
		{
			if(graph[j].cost < graph[j-1].cost)
			{
				e = graph[j-1];
				graph[j-1] = graph[j];
				graph[j] = e;
				e = graph[j];
			}
		}
	}
}

/**
 * @brief Dijkstra单源最短路径
 * @param v
 * @param path
 * @param dist
 */
template <class T>
void MGraph<T>::Dijkstra(int v, int path[], int dist[])
{
	int i,min,j,k;
	bool* s = new bool [vexnum];
	for(i = 0; i < vexnum; i++)
	{
		s[i] = false;
		dist[i] = getEdgeValue(v,i);
		if(dist[i] < INFINITY || i==v)
			path[i] = v;
		else 
			path[i] = -1;
	}
	dist[v] = 0;
	s[v] = true;
	for(i = 1; i < vexnum; i++)
	{
		min = INFINITY;
		for(j = 0; j < vexnum; j++)
			if(!s[j] && dist[j] < min)
			{
				k = j;
				min = dist[j];
			}
			s[k] = true;
			for(int w = 0; w < vexnum; w++)
				if(!s[w] && dist[w] > dist[k] + getEdgeValue(k,w))
				{
					dist[w] = dist[k] + getEdgeValue(k,w);
					path[w] = k;
				}
	}
	delete []s;
}

/**
 * @brief Floyd每对顶点最短路径算法
 * @param path
 * @param D
 */
template <class T>
void MGraph<T>::Floyd(int* path[MAXV], int* D[MAXV])
{
	int i,j,k;
	for (i= 0; i < vexnum; i++)	
		for (j = 0; j < vexnum; j++)
		{
			if (i == j)
			{
				D[i][j] = 0;
			}
			else
				D[i][j] = getEdgeValue(i,j);
			if(D[i][j] < INFINITY)
				path[i][j] = j;
			else
				path[i][j] = -1;
		}
		for (k = 0; k < vexnum; k++)
		{
			for (i = 0; i < vexnum; i++)
			{
				for (j = 0; j < vexnum; j++)
				{
					if (D[i][k] + D[k][j] < D[i][j])
					{
						D[i][j] = D[i][k] + D[k][j];
						path[i][j] = path[i][k];
					}
				}
			}
		}
}
