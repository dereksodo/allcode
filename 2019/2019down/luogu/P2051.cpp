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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll mod = 9999973;
ll dp[105][105][105];
ll C(ll x)
{
	return ((x * (x - 1)) / 2) % mod;
}
int main(int argc, char const *argv[])
{
	ll n,m;
	cin>>n>>m;
	dp[0][0][0] = 1;
	for(ll i = 1;i <= n; ++i)
	{
		for(ll j = 0;j <= m; ++j)
		{
			for(ll k = 0;k <= m - j; ++k)
			{
				dp[i][j][k] = dp[i - 1][j][k];
				if(k >= 1)
				{
					dp[i][j][k] += dp[i - 1][j + 1][k - 1] * (j + 1);
				}
				if(j >= 1)
				{
					dp[i][j][k] += dp[i - 1][j - 1][k] * (m - j - k + 1);
				}
				if(k >= 2)
				{
					dp[i][j][k] += dp[i - 1][j + 2][k - 2] * ((j + 2) * (j + 1)) / 2;
				}
				if(k >= 1)
				{
					dp[i][j][k] += dp[i - 1][j][k - 1] * j * (m - j - k + 1);
				}
				if(j >= 2)
				{
					dp[i][j][k] += dp[i - 1][j - 2][k] * C(m - j - k + 2);
				}
				dp[i][j][k] %= mod;
			}
		}
	}
	ll ans = 0;
	for(ll i = 0;i <= m; ++i)
	{
		for(ll j = 0;j <= m; ++j)
		{
			ans += dp[n][i][j];
			ans %= mod;
		}
	}
	printf("%lld\n",(ans + mod) % mod);
	return 0;
}