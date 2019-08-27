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
const int maxn = 1000005;
const int maxm = 1005;
ll a[maxn];
ll dp[maxn];
ll maxp[maxn];
int main(int argc, char const *argv[])
{
	ll n,m;
	while(~scanf("%lld%lld",&m,&n))
	{
		for(int i = 1;i <= n; ++i)
		{
			scanf("%lld",&a[i]);
		}
		memset(dp,0x00,sizeof(dp));
		memset(maxp,0x00,sizeof(maxp));
		ll mmax;
		for(int i = 1;i <= m; ++i)
		{
			mmax = -0x7fffffff;
			for(int j = i;j <= n; ++j)
			{
				dp[j] = max(dp[j - 1],maxp[j - 1]) + a[j];
				maxp[j - 1] = mmax;
				mmax = max(mmax,dp[j]);
			}
		}
		printf("%lld\n",mmax);
	}
	return 0;
}