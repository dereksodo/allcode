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
int a[maxn];
int dp[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",&a[i + 1]);
	}
	int maxc = -1;
	for(int i = 1;i <= n; ++i)
	{
		maxc = max(maxc,a[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		if(a[i] == a[i - 1] && a[i] == maxc)
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = 1;
		}
		debug("dp[%d] = %d\n",i,dp[i]);
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}