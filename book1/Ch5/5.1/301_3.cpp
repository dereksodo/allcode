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
#include <sstream>
using namespace std;
typedef __int128 ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 85;
ll dp[maxn][maxn],f[maxn],ans,g[maxn];
int m;
void init()
{
	g[0] = 1;
	for(int i = 1;i < maxn; ++i)
	{
		g[i] = g[i - 1] << 1;
	}
}
void solve()
{
	for(int i = 1;i <= m; ++i)
	{
		dp[i][i] = f[i] * g[m];
	}
	for(int len = 2;len <= m; ++len)
	{
		for(int i = 1;i + len - 1 <= m; ++i)
		{
			int j = i + len - 1;
			dp[i][j] = max(dp[i + 1][j] + f[i] * g[m - len + 1],dp[i][j - 1] + f[j] * g[m - len + 1]);
		}
	}
	ans += dp[1][m];
}
void write(ll s)
{
	if(s >= 10)
	{
		write(s / 10);
	}
	printf("%c",s % 10 + '0');
}
int main(int argc, char const *argv[])
{
	init();
	int n;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%lld",&f[j]);
		}
		solve();
	}
	write(ans);
	printf("\n");
	return 0;
}