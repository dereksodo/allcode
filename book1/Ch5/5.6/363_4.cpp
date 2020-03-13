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
const int maxn = 5e5 + 5;
ll s[maxn],q[maxn],dp[maxn];
int n,m,h,t;
ll calc1(int k,int j)
{
	return dp[k] + s[k] * s[k] - dp[j] - s[j] * s[j];
}
ll calc2(int k,int j)
{
	return s[k] - s[j];
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d%d",&n,&m))
	{
		s[0] = dp[0] = q[1] = 0;
		h = t = 1;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%lld",&s[i]);
			s[i] += s[i - 1];
		}
		for(int i = 1;i <= n; ++i)
		{
			while(h < t && calc1(q[h + 1],q[h]) <= 2 * s[i] * calc2(q[h + 1],q[h]))
			{
				++h;
			}
			dp[i] = dp[q[h]] + (s[i] - s[q[h]]) * (s[i] - s[q[h]]) + m;
			while(h < t && calc1(q[t],q[t - 1]) * calc2(i,q[t]) >= calc1(i,q[t]) * calc2(q[t],q[t - 1]))
			{
				--t;
			}
			q[++t] = i;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}