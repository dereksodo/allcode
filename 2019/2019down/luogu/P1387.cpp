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
int a[105][105];
int dp[105][105];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int ans = 1;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(a[i][j] == 0)
			{
				continue;
			}
			dp[i][j] = min(min(dp[i][j - 1],dp[i - 1][j]),dp[i - 1][j - 1]) + 1;
			ans = max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}