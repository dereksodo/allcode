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
const int maxn = 2e5 + 5;
ll a[maxn];
ll dp[maxn][2];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	a[0] = -1;
	for(int i = 1;i <= n; ++i)
	{
		ll x;
		scanf("%lld",&x);
		if(x > 0)
		{
			a[i] = 1;
		}
		else
		{
			a[i] = 0;
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		if(a[i] == 1)
		{
			dp[i][0] = dp[i - 1][0] + 1;//1
			dp[i][1] = dp[i - 1][1];//-1
		}
		else
		{
			dp[i][0] = dp[i - 1][1];//1
			dp[i][1] = dp[i - 1][0] + 1;//-1
		}
		// printf("%lld %lld\n",dp[i][0],dp[i][1]);
	}
	ll ans1 = 0,ans2 = 0;
	for(int i = 1;i <= n; ++i)
	{
		ans1 += dp[i][0];
		ans2 += dp[i][1];
	}
	printf("%lld %lld\n",ans2,ans1);
	return 0;
}