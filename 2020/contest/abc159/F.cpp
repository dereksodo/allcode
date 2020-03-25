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
const int mod = 998244353;
const int maxn = 3005;
ll dp[maxn][maxn][3],a[maxn];
int main(int argc, char const *argv[])
{
	ll n,S;
	cin>>n>>S;
	for(int i = 0;i < n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	dp[0][0][0] = 1;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j <= S; ++j)
		{
			(dp[i + 1][j][0] += dp[i][j][0]) %= mod;
			(dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
			(dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
			if(j + a[i] <= S)
			{
				(dp[i + 1][j + a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
				(dp[i + 1][j + a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
			}
		}
	}
	printf("%lld\n",dp[n][S][2]);
	return 0;
}