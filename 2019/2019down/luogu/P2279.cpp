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
int G[1005][1005];
int dp[1005][1005];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 2;i <= n; ++i)
	{
		int x;
		scanf("%d",&x);
		G[x][i] = 1;
	}
	memset(dp,0,sizeof(dp));
	for(int i = n;i >= 1; --i)
	{
		dp[i][0] = 1;
		int minv1 = 0x3f3f3f3f,minv2 = 0x3f3f3f3f;
		for(int j = 1;j <= n; ++j)
		{
			if(G[i][j])
			{
				dp[i][3] += dp[j][2];
				dp[i][0] += dp[j][4];
				dp[i][4] += dp[j][3];
				minv1 = min(minv1,dp[j][0] - dp[j][3]);
				minv2 = min(minv2,dp[j][1] - dp[j][2]);
			}
		}
		dp[i][1] = dp[i][4] + minv1;
		dp[i][2] = min(min(dp[i][1],dp[i][0]),dp[i][3] + minv2);
		dp[i][3] = min(dp[i][3],dp[i][2]);
		dp[i][4] = min(dp[i][3],dp[i][4]);
	}
	printf("%d\n",dp[1][2]);
	return 0;
}