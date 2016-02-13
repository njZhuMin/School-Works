/**
 * 多段图的动态规划方法
 * 阶段：k
 * 状态：vertex[k]  每个阶段可供选择的点的位置
 * 决策：u
 * 规划方程：dist(k) = min(dist(k+1) + len(u))
 * dist(k)  k点到终点的最短路径长度
 * 初始值：dist(k) = 0;
 */
#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;

void InitGraph(int n, int k, int** vertex, int** cost);		//初始化多段图
void DynamicPlan(int n, int k, int **vertex, int **dist, int** cost, int *result);	//动态规划路径

int main()
{
	int n, k;	//点的个数n，阶段数k	
	cout << "Input number of vertexs: ";		cin >> n;
	cout << "Input number of states: ";			cin >> k;
	
	int** cost = new int* [n+1];	//边的长度
	for(int i = 0; i < n + 1; i++)
	{
		cost[i] = new int[n+1];
		for(int j = 0; j < n + 1; j++)
		{
			cost[i][j] = INT_MAX;
		}
	}
	
	int** vertex = new int* [n+1];	//每个阶段的状态
	for(int i = 0; i < n + 1; i++)
	{
		vertex[i] = new int[n+1];
		memset(vertex[i], 0, sizeof(int) * (n+1));
	}
	
	int** dist = new int* [n+1];		//记录每个阶段的状态中的点到终点的距离
	for(int i = 0; i < n + 1; i++)
	{
		dist[i] = new int[n+1];
		for(int j = 0; j < n + 1; j++)
		{
			dist[i][j] = 0;
		}
	}
	
	int* result = new int[n+1];
	memset(result, 0, sizeof(int) * (k+1));
	
	InitGraph(n, k, vertex, cost);
	DynamicPlan(n, k, vertex, dist, cost, result);
	delete[] result;
	
	//destructions below
	for(int i = 0; i < n + 1; i++)
		delete[] cost[i];
	delete[] cost;
	
	for(int i = 0; i < n + 1; i++)
		delete[] vertex[i];
	delete[] vertex;
	
	for(int i = 0; i < n + 1; i++)
		delete[] dist[i];
	delete[] dist;
	
	return 0;
}

/**
 * @brief 初始化多段图
 * @param n 点的个数
 * @param k 阶段数
 * @param int** vertex 状态
 * @param cost
 */
void InitGraph(int n, int k, int** vertex, int** cost)
{
	int x;
	int i, j;
	cout << "Input number of vertexs..." << endl;
	cout << "You mean the length between vertex 1 and 2 "
		<< "is 4 by inputting \"1 2 4\"." << endl;
	cout << "Input \"0\"To finish inputting." << endl;
	cout << "Now starts inputting:" << endl;
	
	cin >> i;
	while (i != 0)
	{
		cin >> j;
		cin >> cost[i][j];
		cin >> i;
	}
	
	cout << "Input vertexs for every state..." << endl;
	cout << "You mean there are x vertexs in this state, "
		<< "known as vertex 1, 2, 3 by inputting \"x 1 2 3\"." << endl;
	for(int i = 1; i <= k; i++)  
	{
		cout << "Input the number of vertexs in " << i << "th state: ";		cin >> x;
		cout << "Input the vertexs: " ;
		for(int j = 0; j < x; j++)
			cin >> vertex[i][j];
	}
	cout << endl;
}

void DynamicPlan(int n, int k, int **vertex, int **dist, int** cost, int *result)
{
	int t = n;
	int i, j, m;
	int point = vertex[k][0];
	for(i = k - 1; i >= 1; i--)		//阶段
	{
		j = 0;			//i阶段的状态
		while(vertex[i][j] != 0)	//状态
		{
			m = 0;		//i+1阶段的状态
			dist[i][j] = INT_MAX;
			if(cost[vertex[i][j]][point] == INT_MAX)
			{
				while(vertex[i+1][m] != 0)
				{
					if(cost[vertex[i][j]][vertex[i+1][m]] != INT_MAX)
					{
						if(dist[i][j] > (dist[i+1][m] + cost[vertex[i][j]][vertex[i+1][m]]))
						{
							dist[i][j] = dist[i+1][m] + cost[vertex[i][j]][vertex[i+1][m]];
							result[vertex[i][j]] = vertex[i+1][m];
							t--;
						}
					}
					m++;
				}
			}
			else
			{
				while (vertex[i+1][m]!=0)
				{
					if (dist[i][j] > (dist[i+1][m] + cost[vertex[i][j]][vertex[i+1][m]]))
					{
						dist[i][j] = dist[i+1][m] + cost[vertex[i][j]][vertex[i+1][m]];
						result[vertex[i][j]] = vertex[i+1][m];
						t--;
					}
					m++;
				}
			}
			j++;
		}
	}
	cout << "Congruous vertexs are: " << endl;
	t = 0;
	result[t] = 1;
	
	cout << result[t] << " -> ";
	t = result[t];
	while(t < n)
	{
		cout << result[t] << " -> ";
		t = result[t];
	}
	cout << endl;
	cout << "Shortest distance is " << dist[i+1][0] <<endl;
}