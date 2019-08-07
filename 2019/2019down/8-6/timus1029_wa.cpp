#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
struct node{
	int first,second;
	node(){};
	node(int a = 0,int b = 0)
	{
		first = a,second = b;
	}
};
int v[505][105];
int n,m;
int dp[505][105],pre[505][105],prex[505][105];
int dfs(int col,int row)
{
	if(dp[col][row] != -1)
	{
		return dp[col][row];
	}
	if(row < 1 || row > m)
	{
		return dp[col][row] = 0x3f3f3f3f;
	}
	if(col == n)
	{
		return dp[col][row] = 0;
	}
	dp[col][row] = dfs(col + 1,row) + v[col + 1][row];
	pre[col][row] = row;
	prex[col][row] = col + 1;
	if(dfs(col,row - 1) + v[col][row - 1] < dp[col][row])
	{
		dp[col][row] = dfs(col,row - 1) + v[col][row - 1];
		pre[col][row] = row - 1;
		prex[col][row] = col;
	}
	if(dfs(col,row + 1) + v[col][row + 1] < dp[col][row])
	{
		dp[col][row] = dfs(col,row + 1) + v[col][row + 1];
		pre[col][row] = row + 1;
		prex[col][row] = col;
	}
	return dp[col][row];
}
int ans,ansj;
void print(int x,int y)
{
	if(x > 1)
	{
		print(prex[x][y],pre[x][y]);
	}
	printf("%d ",y);
}
int main(int argc, char const *argv[])
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&v[i][j]);
		}
	}
	ans = 0x3f3f3f3f;
	ansj = 0;
	for(int i = 1;i <= m; ++i)
	{
		int ret = dfs(1,i);
		if(ret < ans)
		{
			ansj = i;
			ans = ret;
		}
	}
	print(n,ansj);
	printf("\n");
	return 0;
}