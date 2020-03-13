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
const int maxn = 2e5 + 1;
ll n,q[maxn],l,r,s[maxn],w[maxn],d[maxn],dp[maxn];
ll sum,h,t;
double calc(int j,int k)
{
	return 1.0 * (d[j] * s[j] - d[k] * s[k]) / (s[j] - s[k]);
}
ll calc2(int i,int j)
{
	return sum - d[j] * s[j] - d[i] * (s[i] - s[j]);
}
int main(int argc, char const *argv[])
{
	scanf("%lld",&n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld%lld",&w[i],&d[i]);
		s[i] = s[i - 1] + w[i];
	}
	for(int i = n;i >= 1; --i)
	{
		d[i] += d[i + 1];
		sum += d[i] * w[i];
	}
	for(int i = 1;i <= n; ++i)
	{
		while(h < t && calc(q[h],q[h + 1]) > d[i])
		{
			++h;
		}
		dp[i] = calc2(i,q[h]);
		while(h < t && calc(q[t - 1],q[t]) < calc(q[t],i))
		{
			--t;
		}
		q[++t] = i;
	}
	ll ans = 1e18;
	for(int i = 1;i <= n; ++i)
	{
		ans = min(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}