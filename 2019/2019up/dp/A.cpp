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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1e5 + 5;
int a[maxn],dp[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	dp[1] = 0;
	dp[2] = abs(a[1] - a[2]);
	for(int i = 3;i <= n; ++i)
	{
		dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]),dp[i - 2] + abs(a[i] - a[i - 2]));
		debug("dp[%d] = %d\n",i,dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}