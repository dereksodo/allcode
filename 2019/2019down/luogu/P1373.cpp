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
const int maxn = 803;
int dp[maxn][maxn][18][2];
int n,m,k;
int a[maxn][maxn];
const int mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&m,&k);
	++k;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&a[i][j]);
			a[i][j] %= k;
			dp[i][j][a[i][j]][1] = 1;
		}
	}
	int ans = 0;
	for(int i = n;i >= 1; --i)
	{
		for(int j = m;j >= 1; --j)
		{
			for(int l = 0;l < k; ++l)
			{
				int cur = (l - a[i][j] + k) % k;
				dp[i][j][l][1] += (dp[i + 1][j][cur][0]);
				dp[i][j][l][1] %= mod;
				dp[i][j][l][1] += (dp[i][j + 1][cur][0]);
				dp[i][j][l][1] %= mod;
				cur = (l + a[i][j]) % k;
				dp[i][j][l][0] += (dp[i + 1][j][cur][1]);
				dp[i][j][l][0] %= mod;
				dp[i][j][l][0] += (dp[i][j + 1][cur][1]);
				dp[i][j][l][0] %= mod;
			}
			ans += dp[i][j][0][0];
			ans %= mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}