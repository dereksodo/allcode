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
const int maxn = 105;
const int maxm = 10005;
const int inf = 0x3f3f3f3f;
bool vis[maxn][maxm];
int dp[maxm][maxn];
int main(int argc, char const *argv[])
{
	int n,t;
	while(~scanf("%d%d",&n,&t))
	{
		memset(vis,0x00,sizeof(vis));
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 0;j < t; ++j)
			{
				scanf("%d",&vis[i][j]);
				dp[j][i] = -inf;
			}
		}
		dp[0][1] = vis[1][0];
		for(int i = 1;i < t; ++i)
		{
			for(int j = 1;j <= min(n,i + 1); ++j)
			{
				dp[i][j] = vis[j][i];
				int ret = dp[i - 1][j];
				if(j > 1)
				{
					ret = max(ret,dp[i - 1][j - 1]);
				}
				if(j < n)
				{
					ret = max(ret,dp[i - 1][j + 1]);
				}
				dp[i][j] += ret;
			}
		}
		printf("%d\n",*max_element(dp[t - 1] + 1,dp[t - 1] + 1 + n));
	}
	return 0;
}