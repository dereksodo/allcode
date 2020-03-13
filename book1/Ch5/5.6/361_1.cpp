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
const int maxn = 50005;
ll c[maxn],q[maxn],h,t;
ll s[maxn],dp[maxn],C;
double slope(int j,int k)
{
	return (dp[k] - dp[j] + (s[k] + C) * (s[k] + C) - (s[j] + C) * (s[j] + C)) / (2.0 * (s[k] - s[j]));
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d%lld",&n,&C);
	++C;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&c[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		s[i] = s[i - 1] + c[i] + 1;
	}
	h = 1,t = 0;
	q[++t] = 0;
	for(int i = 1;i <= n; ++i)
	{
		while(h < t && slope(q[h],q[h + 1]) <= s[i])
		{
			++h;
		}
		int tmp = q[h];
		dp[i] = dp[tmp] + (s[i] - s[tmp] - C) * (s[i] - s[tmp] - C);
		while(h < t && slope(q[t],i) < slope(q[t - 1],q[t]))
		{
			--t;
		}
		q[++t] = i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}