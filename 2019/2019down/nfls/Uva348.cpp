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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 15;
int n;
pair<int,int> mat[maxn];
pair<int,int> par[maxn];
int g[maxn][maxn];
int dp[maxn][maxn];
int solve(int l,int r)
{
	if(dp[l][r] != 0x3f3f3f3f)
	{
		return dp[l][r];
	}
	if(l >= r)
	{
		dp[l][r] = 0;
		return 0;
	}
	int pos = 0;
	for(int k = l;k < r; ++k)
	{
		int tmp = solve(l,k) + solve(k + 1,r) + mat[l].first * mat[k].second * mat[r].second;
		if(tmp < dp[l][r])
		{
			pos = k;
			dp[l][r] = tmp;
		}
	}
	g[l][r] = pos;
	return dp[l][r];
}
void dfs(int l,int r)
{
	if(l == r)
	{
		return;
	}
	par[l].first++;
	par[r].second++;
	dfs(l,g[l][r]);
	dfs(g[l][r] + 1,r);
}
int cnt;
void out()
{
	printf("Case %d: ",++cnt);
	for(int i = 1;i <= n; ++i)
	{
		if(i != 1)
		{
			printf(" x ");
		}
		while(par[i].first)
		{
			printf("(");
			par[i].first--;
		}
		printf("A%d",i);
		while(par[i].second)
		{
			printf(")");
			par[i].second--;
		}
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	int kk = 0;
	while(cin>>n && n)
	{
		for(int i = 0;i < maxn; ++i)
		{
			mat[i].first = mat[i].second = par[i].first = par[i].second = 0;
		}
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d%d",&mat[i].first,&mat[i].second);
		}
		memset(dp,0x3f3f3f3f,sizeof(dp));
		solve(1,n);
		dfs(1,n);
		out();
	}
	return 0;
}