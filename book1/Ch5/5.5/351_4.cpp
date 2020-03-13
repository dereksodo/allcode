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
const int maxn = 2005;
int n,m,ap,bp,as,bs,w;
int dp[maxn][maxn],q[maxn],h,t;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&m,&w);
	memset(dp,128,sizeof(dp));
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d%d%d",&ap,&bp,&as,&bs);
		for(int j = 0;j <= as; ++j)
		{
			dp[i][j] = -j * ap;
		}
		for(int j = 0;j <= m; ++j)
		{
			dp[i][j] = max(dp[i][j],dp[i - 1][j]);
		}
		if(i <= w)
		{
			continue;
		}
		h = 1,t = 0;
		for(int j = 0;j <= m; ++j)
		{
			while(h <= t && q[h] < j - as)
			{
				++h;
			}
			while(h <= t && dp[i - w - 1][q[t]] + q[t] * ap <= dp[i - w - 1][j] + j * ap)
			{
				--t;
			}
			q[++t] = j;
			if(h <= t)
			{
				dp[i][j] = max(dp[i][j],dp[i - w - 1][q[h]] + q[h] * ap - j * ap);
			}
		}
		h = 1,t = 0;
		for(int j = m;j >= 0; --j)
		{
			while(h <= t && q[h] > j + bs)
			{
				++h;
			}
			while(h <= t && dp[i - w - 1][q[t]] + q[t] * bp <= dp[i - w - 1][j] + j * bp)
			{
				--t;
			}
			q[++t] = j;
			if(h <= t)
			{
				dp[i][j] = max(dp[i][j],dp[i - w - 1][q[h]] + q[h] * bp - j * bp);
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= m; ++i)
	{
		ans = max(ans,dp[n][i]);
	}
	printf("%d\n",ans);
	return 0;
}