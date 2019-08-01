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
const ll maxn = 1e5 + 5;
const ll maxm = 105;
ll dp[maxn][maxm];
ll weight[maxm],value[maxm];
int main(int argc, char const *argv[])
{
	ll n,w;
	cin>>n>>w;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld %lld",weight + i,value + i);
	}
	for(ll i = 0;i <= w; ++i)
	{
		for(ll j = 1;j <= n; ++j)
		{
			if(i >= weight[j])
			{
				dp[i][j] = max(dp[i - weight[j]][j - 1] + value[j],dp[i][j - 1]);
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	printf("%lld\n",dp[w][n]);
	return 0;
}