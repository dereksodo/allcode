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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 205;
int a[maxn];
int dp[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		a[i + n] = a[i];
	}
	for(int i = 2;i < 2 * n; ++i)
	{
		for(int j = i - 1;j >= 1 && (i - j) < n; --j)
		{
			for(int k = j;k < i; ++k)
			{
				dp[j][i] = max(dp[j][i],dp[j][k] + a[i + 1] * a[j] * a[k + 1] + dp[k + 1][i]);
				debug("dp[%d][%d] = ",j,i);
				debug("max(dp[%d][%d],dp[%d][%d] + ",j,i,j,k);
				debug("a[%d] * a[%d] * a[%d] + ",i + 1,j,k + 1);
				debug("dp[%d][%d]) = %d\n",k + 1,i,dp[j][i]);
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		debug("dp[%d][%d] = %d\n",i,i + n,dp[i][i + n]);
		ans = max(ans,dp[i][i + n - 1]);
	}
	printf("%d\n",ans);
	return 0;
}