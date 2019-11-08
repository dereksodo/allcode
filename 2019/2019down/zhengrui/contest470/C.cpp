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
const ll maxn = 1e5 + 5;
const ll mod = 998244353;
vector<ll> G[maxn];
ll a[maxn];
ll ans;
ll f0[maxn],f1[maxn],f2[maxn];
void dfs(ll u,ll f)
{
	f0[u] = 1;
	f1[u] = a[u];
	f2[u] = a[u] * a[u] % mod;
	for(int i = 0;i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if(v != f)
		{
			dfs(v,u);
			f2[u] = (f2[u] + f0[u] * f2[v] + 2 * f1[u] * f1[v] + f2[u] * f0[v]) % mod;
			f1[u] = (f1[u] + f0[u] * f1[v] + f1[u] * f0[v]) % mod;
			f0[u] = (f0[u] + f0[u] * f0[v]) % mod;
		}
	}
	ans += f2[u];
	ans %= mod;
}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	for(ll i = 1;i < n; ++i)
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}