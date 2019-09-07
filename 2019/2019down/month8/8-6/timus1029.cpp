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
ll a[105][505];
ll dp[105][505];
pair<ll,ll> pre[105][505];
ll m,n;
int main(int argc, char const *argv[])
{
	cin>>m>>n;
	for(ll i = 1;i <= m; ++i)
	{
		for(ll j = 1;j <= n; ++j)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	memset(dp,127,sizeof(dp));
	for(ll j = 1;j <= n; ++j)
	{
		dp[0][j] = 0;
	}
	for(ll i = 1;i <= m; ++i)
	{
		for(ll j = 1;j <= n; ++j)
		{
			dp[i][j] = dp[i - 1][j] + a[i][j];
			pre[i][j] = make_pair(i - 1,j);
		}
		for(ll j = 1;j <= n; ++j)
		{
			if(dp[i][j] > dp[i][j - 1] + a[i][j])
			{
				dp[i][j] = dp[i][j - 1] + a[i][j];
				pre[i][j] = make_pair(i,j - 1);
			}
		}
		for(ll j = n;j >= 1; --j)
		{
			if(dp[i][j] > dp[i][j + 1] + a[i][j])
			{
				dp[i][j] = dp[i][j + 1] + a[i][j];
				pre[i][j] = make_pair(i,j + 1);
			}
		}
	}
	ll ans = 2e18;
	ll pos = 0;
	for(ll i = 1;i <= n; ++i)
	{
		if(ans > dp[m][i])
		{
			ans = dp[m][i];
			pos = i;
		}
	}
	stack<ll> output;
	while(!output.empty())
	{
		output.pop();
	}
	for(ll i = m,j = pos,ni,nj;i && j;ni = pre[i][j].first,nj = pre[i][j].second,i = ni,j = nj)
	{
		output.push(j);
	}
	while(!output.empty())
	{
		printf("%lld ",output.top());
		output.pop();
	}
	printf("\n");
	return 0;
}