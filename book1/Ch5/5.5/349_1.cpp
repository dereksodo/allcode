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
const int maxn = 200005;
const int inf = 0x3f3f3f3f;
int a[maxn],dp[maxn],q[maxn];
int h = 1,t = 0,n,m;
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",a + i);
	}
	memset(dp,inf,sizeof(dp));
	dp[0] = 0;
	q[++t] = 0;
	for(int i = 1;i <= n; ++i)
	{
		while(t >= h && dp[q[t]] >= dp[i - 1])
		{
			--t;
		}
		q[++t] = i - 1;
		while(t >= h && q[h] < i - m)
		{
			++h;
		}
		dp[i] = dp[q[h]] + a[i];
	}
	int ans = inf;
	for(int i = n;i > n - m; --i)
	{
		ans = min(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}