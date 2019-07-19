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
const ll maxn = 1e5 + 500;
ll a[maxn],dp[maxn];
int main(int argc, char const *argv[])
{
	memset(dp,0x3f3f3f3f,sizeof(dp));
	ll n,k;
	cin>>n>>k;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	dp[1] = 0;
	for(ll i = 1;i <= n; ++i)
	{
		for(ll j = 1;j <= k; ++j)
		{
			dp[i + j] = min(dp[i + j],dp[i] + abs(a[i + j] - a[i]));
		}
	}
	// for(ll i = 1;i <= n; ++i)
	// {
	// 	debug("dp[%d] = %d\n",i,dp[i]);
	// }
	printf("%lld\n",dp[n]);
	return 0;
}