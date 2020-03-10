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
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 50005;
int n,m;
int dp[maxn][40];
int num[maxn][40];
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		int a,b,c,t,like = 0,fear = 0;
		scanf("%d%d%d",&a,&b,&c);
		for(int j = 1;j <= b; ++j)
		{
			scanf("%d",&t);
			t = (t - a + n) % n;
			fear |= (1 << t);
		}
		for(int j = 1;j <= c; ++j)
		{
			scanf("%d",&t);
			t = (t - a + n) % n;
			like |= (1 << t);
		}
		for(int j = 0;j < (1 << 5); ++j)
		{
			if((j & fear) || (~j & like))
			{
				++num[a][j];
			}
		}
	}
	int ans = 0;
	for(int i = 0;i < (1 << 5); ++i)
	{
		memset(dp[0],128,sizeof(dp[0]));
		dp[0][i] = 0;
		for(int j = 1;j <= n; ++j)
		{
			for(int s = 0;s < (1 << 5); ++s)
			{
				dp[j][s] = max(dp[j - 1][(s & 15) << 1],dp[j - 1][(s & 15) << 1 | 1]) + num[j][s];
			}
		}
		if(ans < dp[n][i])
		{
			ans = dp[n][i];
		}
	}
	printf("%d\n",ans);
	return 0;
}