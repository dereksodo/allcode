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
#include <numeric>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 3005;
int dp[maxn][maxn];
int value[maxn];
vector< pair<int,int> > G[maxn];
int n,m;
int dfs(int u)//return number of leaves
{
	if(u > n - m)
	{
		dp[u][1] = value[u];
		dp[u][0] = 0;
		return 1;
	}
	dp[u][0] = 0;
	int ret = 0;
	for(int i = 0;i < G[u].size(); ++i)
	{
		int to = G[u][i].first;
		int v = G[u][i].second;
		int now = dfs(to);
		ret += now;
		for(int j = ret;j; --j)
		{
			for(int k = 0,kk = min(j,now);k <= kk; ++k)
			{
				dp[u][j] = max(dp[u][j],dp[u][j - k] + dp[to][k] - v);
			}
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 1;i <= n - m; ++i)
	{
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int a,c;
			scanf("%d%d",&a,&c);
			G[i].push_back(make_pair(a,c));
		}
	}
	for(int i = n - m + 1;i <= n; ++i)
	{
		scanf("%d",&value[i]);
	}
	memset(dp,0x8f,sizeof(dp));
	memset(dp[0],0x00,sizeof(dp[0]));
	dfs(1);
	for(int i = m;i >= 0; --i)
	{
		if(dp[1][i] >= 0)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}