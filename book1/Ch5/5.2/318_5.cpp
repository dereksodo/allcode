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
ll to[maxn],nxt[maxn],head[maxn],tot;
ll vis[maxn],root,v[maxn],f[maxn];
ll dp[maxn][2];
ll n,ans;
void add(ll u,ll v)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}
void dfs(ll x)
{
	vis[x] = 1;
	dp[x][0] = 0;
	dp[x][1] = v[x];
	for(ll i = head[x];i;i = nxt[i])
	{
		ll v = to[i];
		if(v == root)
		{
			continue;
		}
		dfs(v);
		dp[x][0] += max(dp[v][0],dp[v][1]);
		dp[x][1] += dp[v][0];
	}
}
void findd(ll x)
{
	vis[x] = 1;
	root = x;
	ll res = 0;
	while(!vis[f[root]])
	{
		root = f[root];
		vis[root] = 1;
	}
	dfs(root);
	res = dp[root][0];
	root = f[root];
	dfs(root);
	ans += max(res,dp[root][0]);
}
int main(int argc, char const *argv[])
{
	scanf("%lld",&n);
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld%lld",&v[i],&f[i]);
		add(f[i],i);
	}
	for(ll i = 1;i <= n; ++i)
	{
		if(!vis[i])
		{
			findd(i);
		}
	}
	cout<<ans<<endl;
	return 0;
}