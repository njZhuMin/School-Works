#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 10

int best;
int num[maxn];
// int x[maxn];
int path[maxn];
int g[maxn][maxn], n;
// 最大团： V中取K个顶点，两点间相互连接
// 最大独立集： V中取K个顶点，两点间不连接 
// 最大团数量 = 补图中最大独立集数

bool dfs( int *adj, int total, int cnt);
int MaximumClique();


int main()
{
	
	return 0;
}
bool dfs( int *adj, int total, int cnt )  // total: 与u相连的顶点数量  , cnt表示当前团的数量
{
	int i, j, k;
	int t[maxn];
	if( total == 0 )  // 当此团中最后一个点 没有 比起序号大 的顶点相连时
	{
		if( best < cnt )   // 问题1：best为最大团中顶点的数量
		{
			// for( i = 0; i < cnt; i++) path[i] = x[i];
			best = cnt;
			return true;
		}
		return false;
	}
	for( i = 0; i < total; i++)  // 枚举每一个与 u 相连的顶点 adj[i]
	{
		if( cnt+(total-i) <= best ) return false; // 剪枝1， 若当前 顶点数量cnt 加上还能够增加的最大数量 仍小于 best则 退出并返回false
		if( cnt+num[adj[i]] <= best ) return false; // 剪枝2， 若当前 顶点数量cnt 加上 包含adj[i]的最大团顶点数 仍小于 best则 退出并返回false
		// x[cnt] = adj[i];
		for( k = 0, j = i+1; j < total; j++ ) // 扫描 与u相连的顶点  中与 adj[u]相连的顶点 并存储到 数组 t[]中，数量为k
			if( g[ adj[i] ][ adj[j] ] )
				t[ k++ ] = adj[j];
		if( dfs( t, k, cnt+1 ) ) return true;
	}
	return false;
}

int MaximumClique()
{
	int i, j, k;
	int adj[maxn];
	if( n <= 0 ) return 0;
	best = 0;
	for( i = n-1; i >= 0; i-- )
	{
		// x[0] = i;
		for( k = 0, j = i+1; j < n; j++)    // 遍历 [i+1, n] 间顶点，
			if( g[i][j] ) adj[k++] = j;
		dfs( adj, k, 1 ); // *adj, total, cnt
		num[i] = best;   // 得出顶点 i, 出发构成最大团 中顶点数量
	}
	return best;
}