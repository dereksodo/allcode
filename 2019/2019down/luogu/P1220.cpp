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
const int maxn = 60;
int a[maxn],p[maxn];
int dp[maxn][maxn][2];
int sum[maxn];
int main(int argc, char const *argv[])
{
	int n,d;
	cin>>n>>d;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&a[i],&p[i]);
		sum[i] = sum[i - 1] + p[i];
	}
	memset(dp,127,sizeof(dp));
	dp[d][d][0] = dp[d][d][1] = 0;
	for(int len = 2;len <= n; ++len)
	{
		for(int i = 1;i + len - 1 <= n; ++i)
		{
			int j = i + len - 1;
			dp[i][j][1] = min(dp[i][j - 1][0] + (a[j] - a[i]) * (sum[i - 1] + sum[n] - sum[j - 1])
								,dp[i][j - 1][1] + (a[j] - a[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]));
			dp[i][j][0] = min(dp[i + 1][j][0] + (a[i + 1] - a[i]) * (sum[i] + sum[n] - sum[j])
								,dp[i + 1][j][1] + (a[j] - a[i]) * (sum[i] + sum[n] - sum[j]));
		}
	}
	printf("%d\n",min(dp[1][n][1],dp[1][n][0]));
	return 0;
}