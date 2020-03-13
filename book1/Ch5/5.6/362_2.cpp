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
const int maxn = 1e6 + 5;
int n,x[maxn],p[maxn],c[maxn],q[maxn],h,t;
ll dp[maxn],a[maxn],b[maxn];
double slope(int j,int k)
{
	return 1.0 * (dp[j] + b[j] - dp[k] - b[k]) / (a[j] - a[k]);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d%d",&x[i],&p[i],&c[i]);
		a[i] = a[i - 1] + p[i];
		b[i] = b[i - 1] + 1ll * p[i] * x[i];
	}
	int h = 1,t = 1;
	for(int i = 1;i <= n; ++i)
	{
		while(h < t && slope(q[h + 1],q[h]) < x[i])
		{
			++h;
		}
		dp[i] = dp[q[h]] + 1ll * x[i] * (a[i] - a[q[h]]) - (b[i] - b[q[h]]) + c[i];
		while(h < t && slope(q[t],q[t - 1]) > slope(i,q[t]))
		{
			--t;
		}
		q[++t] = i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}