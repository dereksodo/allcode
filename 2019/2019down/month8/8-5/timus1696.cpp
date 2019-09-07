//250627XW
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
ll mod,n,k;
const int maxn = 205;
ll pre1[maxn][maxn],pre2[maxn][maxn],dp[2][maxn][maxn];
void calc(int pos)
{
	for(int i = 0;i <= k; ++i)
	{
		pre1[i][0] = dp[pos][i][0];
		for(int j = 1;j <= k; ++j)
		{
			pre1[i][j] = pre1[i][j - 1] + dp[pos][i][j];
			if(pre1[i][j] > mod)
			{
				pre1[i][j] -= mod;
			}
		}
	}
	for(int i = 0;i <= k; ++i)
	{
		pre2[i][0] = dp[pos][0][i];
		for(int j = 1;j <= k; ++j)
		{
			pre2[i][j] = pre2[i][j - 1] + dp[pos][j][i];
			if(pre2[i][j] > mod)
			{
				pre2[i][j] -= mod;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld%lld",&n,&k,&mod);
	dp[0][1][0] = 1;
	calc(0);
	ll ans = 0;
	for(int ii = 1;ii <= n; ++ii)
	{
		int i = ii & 1;
		for(int j = 1;j <= k; ++j)
		{
			for(int l = 0;l < j; ++l)
			{
				dp[i][j][l] = pre2[l][j] - pre2[l][l];
				if(l)
				{
					dp[i][j][l] += pre1[j][l];
				}
				if(dp[i][j][l] > mod)
				{
					dp[i][j][l] -= mod;
				}
				if(ii == n)
				{
					ans += dp[i][j][l];
					ans %= mod;
				}
			}
		}
		calc(i);
	}
	printf("%lld\n",ans + 1);
	return 0;
}