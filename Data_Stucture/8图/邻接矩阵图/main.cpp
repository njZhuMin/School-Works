#include <iostream>
#include "MGraph.cpp"
#include "SeqQueue.cpp"
using namespace std;


int main()
{
	char v[6]={'a','b','c','d','e','f'};	//构造函数测试
	MGraph<char> MG(undigraph, v, 6, 10);
	
	//深度优先遍历测试
	cout << "DFS traverse:" << endl;
	MG.DFSTraverse();
	cout << endl;
	
	//广度优先遍历测试
	cout << "BFS traverse:" << endl;
	MG.BFSTraverse();
	cout << endl;
	
	//根据序号返回顶点值测试
	cout << MG.getVexValue(2);
	cout << endl;

/*	//插入一个顶点测试
	char newpoint;
	cout << "Input a new value:";
	cin >> newpoint;
	cout << endl;
	MG.InsertVex(newpoint);

	cout << "DFS traverse:" << endl;
	MG.BFSTraverse();
	cout << endl;*/

	//打印邻接矩阵测试
	cout << "Traverse adjMatrix:" << endl;
	MG.PrintEdges();
	cout << endl;
	
	//打印顶点表测试
	cout << "Traverse vexes:" << endl;
	MG.PrintVexs();

/*	//插入一条边测试
	cout << "Insert edge a-->e, weight 1:";
	EdgeType<char> et('a','e',1);
	MG.InsertEdge(et);
	cout << endl;
	cout << "Traverse adjMatrix:" << endl;
	MG.PrintEdges();
	cout << endl;*/

	MG.Prim(3);
	vector<EdgeType<char> > tree;
	MG.Kruskal(tree);
	for(int i = 0; i < tree.size(); i++)
		cout << tree[i].head << "," << tree[i].tail << ":" << tree[i].cost << endl;
	
	/**
	 * Dijkstra和Floyd算法测试
	 */
	char v2[5]={'a','b','c','d','e'};
	MGraph<char> MG2(digraph,v2,5,10);
	MG2.PrintVexs();
	MG2.PrintEdges();
	int path [5] = {0};
	int dist [5] = {0};
	MG2.Dijkstra(0,path,dist);
	cout << "Route by Dijkstra:" << endl;
	for (int i = 0; i<5; i++)
	{
		cout << path[i] << endl;
	}
	cout << endl;

	cout << "Route by Floyd:" << endl;
	int* path2[5] = {0};
	int* D[5] = {0};
	MG2.Floyd(path2, D);
	for (int k = 0; k < 5; k++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << path2[k][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}