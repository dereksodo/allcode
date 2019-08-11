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
typedef __int128 ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 85;
int num[maxn];
ll ans,dp[maxn][maxn],p[maxn];
int n,m;
ll solve(int l,int r)
{
	if(dp[l][r] != -1)
	{
		return dp[l][r];
	}
	ll cnt = m - (r - l);
	if(r - l >= 1)
	{
		return dp[l][r] = max(num[l] * p[cnt] + solve(l + 1,r),solve(l,r - 1) + num[r] * p[cnt]);
	}
	else
	{
		return dp[l][r] = num[l] * p[cnt];
	}
}
void print(ll n)
{
	if(!n)
	{
		return;
	}
	if(n)
	{
		print(n / 10);
	}
	putchar(n % 10 + '0');
}
int main(int argc, char const *argv[])
{
	p[0] = 1;
	cin>>n>>m;
	for(int i = 1;i <= m; ++i)
	{
		p[i] = p[i - 1] * 2;
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&num[j]);
		}
		memset(dp,-1,sizeof(dp));
		ans += solve(1,m);
	}
	if(ans == 0)
	{
		printf("0\n");
	}
	else
	{
		print(ans);
		printf("\n");
	}
	return 0;
}