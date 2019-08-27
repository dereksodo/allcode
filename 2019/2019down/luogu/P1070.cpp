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
const int maxn = 1005;
int n,m,p;
int f[maxn][maxn],cost[maxn];
int l[maxn],r[maxn],dp[maxn];
int q[maxn][maxn],loc[maxn][maxn];
int add[maxn];
int gn(int i,int j)
{
	return ((j - i) % n + n) % n;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&f[j][i]);
			f[j][i] += f[j - 1][i - 1];
		}
	}
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",&cost[i]);
		q[i][++r[i]] = -cost[i],l[i]++;
	}
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	dp[0] = 0;
	for(int i = 1;i <= m; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			int id = gn(i,j);
			while(l[id] <= r[id] && loc[id][l[id]] + p < i)
			{
				l[id]++;
			}
			if(!j)
			{
				add[id] += f[i][n];
			}
			if(l[id] <= r[id])
			{
				dp[i] = max(dp[i],q[id][l[id]] + add[id] + f[i][j]);
			}
		}
		for(int j = 0;j < n; ++j)
		{
			int id = gn(i,j);
			int tmp = dp[i] - add[id] - f[i][j] - cost[j];
			while(l[id] <= r[id] && q[id][r[id]] <= tmp)
			{
				r[id]--;
			}
			loc[id][++r[id]] = i;
			q[id][r[id]] = tmp;
		}
	}
	printf("%d\n",dp[m]);
	return 0;
}