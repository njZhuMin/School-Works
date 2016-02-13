#include "ALGraph.h"
#include "SeqQueue.h"
#include <string>

template <class T>
ALGraph<T>::ALGraph(GraphType t, T vexs[], int n, int e)
{
	EdgeNode* p;
	vexnum = n;
	edgenum = e;
	kind = t;
	adjlist.resize(vexnum);
	for(int i = 0; i < vexnum; ++i)
	{
		adjlist[i].data = vexs[i];
		adjlist[i].firstedge = 0;
	}
	for(int j = 0; j < vexnum; j++)
	{
		int va, vb;
		cin >> va >> vb;
		EdgeNode* p = new EdgeNode;
		p->adjvex = vb;
		p->nextedge = adjlist[va].firstedge;
		adjlist[va].firstedge = p;
		p = new EdgeNode;
		p->adjvex = va;
		p->nextedge = adjlist[vb].firstedge;
		adjlist[vb].firstedge = p;
	}
}

template <class T>
ALGraph<T>::~ALGraph()
{
}

/**private*/
/**
 * @brief 在顶点的邻接表中加入一条边
 * @param v 加入边中邻接顶点序号
 * @return 
 */
template<class T>
bool ALGraph<T>::appendEdge(T v)
{
    EdgeNode *p = adjlist;
    EdgeNode *q = NULL;
    //找到链接表中末节点，末节点的指针赋值给q。
	//如果发现有一个节点的adjVex的值和v相同，则返回false
    while(p != NULL)
	{
        if(p->adjvex == v)
            return false;
        q = p;
        p = p->nextedge;
    }
    // 在邻接表的最后加上一条边
    p = new EdgeNode(v);
    if (q == 0)
        adjlist = p;
    else
        q->nextedge = p;
    return true;
}

/**
 * @brief 在顶点的邻接表中删除一条边
 * @param v 要删除边的邻接顶点序号
 * @return 
 */
template <class T>
bool ALGraph<T>::removeEdge(int v)
{
    EdgeNode *p = adjlist;
    EdgeNode *q = NULL;
    //遍历邻接表，如果发现这条边，则删除
    while(p != NULL)
	{
		if (p->adjvex == v)
		{
			if (p == adjlist)
				adjlist = p->nextedge;
			else
				q->nextedge = p->nextedge;
			delete p;
			return true;
        }
        q = p;
        p = p->nextedge;
    }
    return false;
}

/**
 * @brief 清空一个顶点的邻接表，释放邻接表各节点
 */
template <class T>
void ALGraph<T>::clearEdgeList()
{
    EdgeNode *p, *q;
    p = adjlist;
    while(p != NULL)
	{
        q = p->nextedge;
        delete p;
        p = q;
    }
    adjlist = NULL;
}


/**
 * @brief 返回第v个顶点对应边表头指针
 * @param v
 * @return 对应边表头指针
 */
/*template <class T>
EdgeNode* ALGraph<T>::getFirstAdjVex(int v)
{
	if(adjlist[v].firstedge != NULL);
    {
        return adjlist[v].firstedge;
    }
    return NULL;
}*/

/**
 * @brief 返回第v个顶点对应边表头
 * @param v
 * @return 对应边表头
 */
template <class T>
int ALGraph<T>::getFirstAdjVex(int v)
{
	if(adjlist[v].firstedge != NULL)
    {
        return adjlist[v].firstedge->adjvex;
    }
    return -1;
}

/**
 * @brief v相对于w的下一个邻接点
 * @param v
 * @param w
 * @return 
 */
template <class T>
int ALGraph<T>::getNextAdjVex(int v, int w)
{
    EdgeNode* p;
    for(p = adjlist[v].firstedge; p != NULL; p = p->nextedge)
    {
        if(p->adjvex == w && p->nextedge != NULL)
        {
            return p->nextedge->adjvex;
        }
    }
    return -1;
}

//返回顶点数量
template<class T>
int ALGraph<T>::getVexterNum()
{
	return vexnum;
}

//返回边数量
template<class T>
int ALGraph<T>::getEdgeNum()
{
	return edgenum;
}

//返回第i个顶点的值
template<class T>
T ALGraph<T>::getVexValue(int i)
{
	if(i < vexnum)
		return adjlist[i].data;
	else
	{	cout<< "Vex out of range!" << endl;
		return 0;
	}
}

//返回表中值的序号
template<class T>
int ALGraph<T>::getVexValueNum(T v)
{
	for(int i = 0; i < adjlist.size(); i++)
	{
		if(adjlist[i].data == v)
			return i;
	}
	cout << "Value not match!" << endl;
	return 0;
}

/**
 * @brief 连通图深度优先遍历算法
 * @param v 第v个顶点
 * @param isVisited 访问标志
 */
template <class T>
void ALGraph<T>::DFS(int v, bool* isVisited)
{
    cout << adjlist[v].data << '\t';
    isVisited[v] = true;
    for(int w = getFirstAdjVex(v); w >= 0; w = getNextAdjVex(v,w) )
    {
        if (!isVisited[w])
        {
            DFS(w,isVisited);
        }
    }
}

/**
 * @brief 图的深度优先遍历算法
 */
template<class T>
void ALGraph<T>::DFSTraverse()
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
void ALGraph<T>::BFSTraverse()
{
	int i;
	SeqQueue<int, 10> q;
	bool* isVisited = new bool[vexnum];
	for(i = 0; i < vexnum; i++)
		isVisited[i] = false;
	
	for(i = 0; i < vexnum; i++)
	{
		if(!isVisited[i])
		{
			cout << adjlist[i].data << "\t";
			isVisited[i] = true;
			q.EnQueue(i);
			while(!q.isEmpty())
			{
				T u = q.DeQueue();
				for(int w = getFirstAdjVex(i); w >= 0; w = getNextAdjVex(i,w))
				{
					if(!isVisited[w])
					{
						cout << adjlist[w].data << "\t";
						isVisited[w] = true;
						q.EnQueue(w);
					}
				}
			}
		}
	}
	delete []isVisited;
}

/**
 * @brief 插入一个顶点
 * @param v 顶点值
 */
template<class T>
bool ALGraph<T>::insertVex(T v)
{
	int i;
	vexnum++;
    //判断相同的顶点是否存在，如存在，则返回
    for(i = 0; i < vexnum; i++)
		if(adjlist[i].data == v)
			return false;
    //增加一个顶点项
	adjlist.resize(vexnum);	
	adjlist[vexnum].data = v;
	adjlist[vexnum].nextedge = NULL;
    return true;
}

/**
 * @brief //删除一个顶点
 * @param v 顶点值
 */
template<class T>
bool ALGraph<T>::removeVex(T v)
{
	/* std::vector::resize
	 * void resize (size_type n, value_type val = value_type());
	 * Change size
	 * Resizes the container so that it contains n elements.
	 * If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
	 * If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
	 * If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
	 * Notice that this function changes the actual content of the container by inserting or erasing elements from it.
	 */
	int i;
	int vex;
	//在顶点表中找到要删除顶点的序号，如果没找到则返回
	if((vex = getVexValueNum(v)) == -1)
		return false;
     
	//遍历其它顶点
	//如果这些顶点的邻接表中包含了要删除的顶点，则移除
    for(i = 0; i < vexnum; i++)
	if(i != vex)
	{
		if(adjlist[i].removeEdge(vex))
			edgenum--;
	}
    // 在顶点表中删除序号为v的顶点
    adjlist[v].clearEdgeList();
    for(i = vex; i < vexnum - 1; i++)
        adjlist[i] = adjlist[i + 1];
    vexnum--;
	
    //如果在所有的邻接边表中的顶点序号大于要删除的顶点序号，但将顶点序号减1
    EdgeNode *p;
    for (i = 0; i < vexnum; i++)
    {
        //遍历该顶点的邻接边点，调整邻接顶点序号
        p = adjlist[i].nextedge;       
        while(p != NULL)
        {
			if (p->adjvex > v)                // 判断邻接顶点号是否大于要删除的顶点号
				p->adjvex--;	          		  // 如果>v，则将顶点号减1
			p = p->nextedge;
        }
    }
    return true;
}

/**
 * @brief 插入一条边
 * @param e
 */
template<class T>
bool ALGraph<T>::insertEdge(VexNode<T> e)
{
	//找到顶点在顶点表中的序号
	//只要在图的顶点表中未找到，则返回
    int v = getVexValueNum(e);
    if(v == -1)
		return false;
    adjlist[edgenum].appendEdge(v);
    //如果为无向图，则必须在另一顶点的邻接表中增加一条边
    if(kind == undigraph || kind == undinetwork)
        adjlist[v].appendEdge(edgenum);
    edgenum++;
    return true;
}

/**
 * @brief 删除一条边
 * @param e
 */
template<class T>
bool ALGraph<T>::deleteEdge(VexNode<T> e)
{
	//找到顶点在顶点表中的序号
	//只要在图的顶点表中未找到，则返回
	int v = getVexValueNum(e);
	if(v == -1)
		return false;
    //为第一个顶点的邻接表中增加一条边
    adjlist[edgenum].removeEdge(v);
    // 如果为无向图，则必须在另一顶点的邻接表中增加一条边
    if(kind == undigraph || kind == undinetwork)
        adjlist[v].removeEdge(edgenum);
    edgenum--;
    return true;
}

/**
 * @brief 拓补排序算法
 */
template <class T>
void ALGraph<T>::TopoSort()
{
	int i, count = 0;
	int* indegree = new int[vexnum];
	SeqQueue<int,20> s;
	for(i = 0; i < vexnum; i++)
	{
		indegree[i] = 0;
	}
	//求所有顶点入度
	EdgeNode* p;
	for(i = 0; i < vexnum; i++)
	{
		p = adjlist[i].fistedge;
		while(p)
		{
			indegree[p->adjvex]++;
			p = p->nextedge;
		}
	}
	//入度为0的顶点入队
	for(i = 0; i < vexnum; i++)
	{
		if(!indegree[i])
			s.EnQueue(i);
	}
	while(!s.isEmpty())
	{
		i = s.DeQueue();
		cout << adjlist[i].data;	//输出顶点
		++count;
		EdgeNode* p = adjlist[i].firstedge;
		while(p)
		{
			indegree[p->adjvex]--;
			if(!indegree[p->adjvex])
				s.EnQueue(p->adjvex);
		}
	}
	if(count < vexnum)
		cout << "The AOV has a ring!" << endl;
	delete []indegree;
}
