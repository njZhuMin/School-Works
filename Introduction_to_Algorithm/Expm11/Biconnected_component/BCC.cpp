#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 1000 + 10;

//////////////////////////////Variable definition//////////////////////////////
int n, m;
int bcc_cnt;
int dfs_clock;	//bcc_cnt计数一共有多少个点-双连通分量
int pre[maxn];
bool iscut[maxn];
int bccno[maxn];	//bccno[i]=x表示第i个顶点属于x号点双连通分量
vector<int> G[maxn],bcc[maxn];	//bcc[i]中包含了i号点-双连通分量的所有节点

struct Edge
{
	int u,v;
	Edge(int u,int v):u(u),v(v) {}
};
stack<Edge> S;

//////////////////////////////Function declaration//////////////////////////////
int dfs(int u, int fa);
void find_bcc(int n);


int main()
{
	while(scanf("%d %d", &n, &m)==2 && n)	//n,m均成功读入，n值有效
	{
		for(int i = 0; i < n; i++)  
			G[i].clear();
		for(int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		find_bcc(n);
		cout << "There are at all " << bcc_cnt << "point BCC" << endl;
		for(int i = 1; i <= bcc_cnt; i++)
		{
			cout << "The " << i << " th point BCC contains: " << endl;
			sort(&bcc[i][0], &bcc[i][0] + bcc[i].size()); 	//对vector排序,使输出的点从小到大
			for(int j = 0; j < bcc[i].size(); j++)
			{
				cout << bcc[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}


int dfs(int u, int fa)
{
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for(int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		Edge e = Edge(u,v);
		if(!pre[v])
		{
			S.push(e);
			child++;
			int lowv = dfs(v,u);
			lowu = min(lowu,lowv);
			if(lowv >= pre[u])
			{
				iscut[u] = true;
				bcc_cnt++;	//注意bcc_cnt从1开始编号
				bcc[bcc_cnt].clear();
				while(true)
				{
					Edge x = S.top();
					S.pop();
					if(bccno[x.u] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.u);
						bccno[x.u] = bcc_cnt;
					}
					if(bccno[x.v] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.v);
						bccno[x.v] = bcc_cnt;
					}
					if(x.u == u && x.v == v) 
						break;
				}
			}
		}
		else if(pre[v] < pre[u] && v != fa) //这个判断条件如果少了,就是WA,可修改POJ2942代码
		{
			S.push(e);
			lowu = min(lowu,pre[v]);
		}
	}
	if(fa < 0 && child == 1) 
		iscut[u] = false;
	return lowu;
}

void find_bcc(int n)
{
	memset(pre, 0, sizeof(pre));
	memset(iscut, 0, sizeof(iscut));
	memset(bccno, 0, sizeof(bccno));
	dfs_clock = bcc_cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(!pre[i])
			dfs(i,-1);
	}
	return;
}