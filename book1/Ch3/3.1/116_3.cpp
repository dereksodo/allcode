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
const ll maxn = 100005;
const ll maxm = 100005;
ll vis[maxn];
ll ans,sum,value[maxn],w[maxn << 1];
ll n,e,tot,f[maxn],dep[maxn],head[maxn];
ll son[maxn << 1],nxt[maxn << 1];
struct Edge{
	ll x,y,z;
	Edge(){};
	Edge(ll aa,ll bb,ll cc):x(aa),y(bb),z(cc){};
	bool operator <(const Edge &b)const
	{
		return z < b.z;
	}
}a[maxn];
ll ff(ll x)
{
	return f[x] == x ? x : (f[x] = ff(f[x]));
}
void add(ll x,ll y,ll z)
{
	nxt[++tot] = head[x];
	son[tot] = y;
	w[tot] = z;
	head[x] = tot;
}
void dfs(ll x,ll fa)
{
	dep[x] = dep[fa] + 1;
	f[x] = fa;
	for(ll j = head[x];j;j = nxt[j])
	{
		if(son[j] != fa)
		{
			value[son[j]] = w[j];
			dfs(son[j],x);
		}
	}
}
ll work(ll x,ll y,ll w)
{
	ll ret = 0;
	while(x != y)
	{
		if(dep[x] < dep[y])
		{
			swap(x,y);
		}
		if(value[x] != w)
		{
			ret = max(ret,value[x]);
		}
		x = f[x];
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld",&n,&e);
	for(ll i = 1;i <= n; ++i)
	{
		f[i] = i;
	}
	for(ll i = 1;i <= e; ++i)
	{
		ll aa,bb,cc;
		scanf("%lld%lld%lld",&aa,&bb,&cc);
		a[i] = Edge(aa,bb,cc);
	}
	sort(a + 1,a + e + 1);
	for(ll i = 1;i <= e; ++i)
	{
		ll f1 = ff(a[i].x);
		ll f2 = ff(a[i].y);
		if(f1 == f2)
		{
			continue;
		}
		vis[i] = 1;
		f[f1] = f2;
		sum += a[i].z;
		add(a[i].x,a[i].y,a[i].z);
		add(a[i].y,a[i].x,a[i].z);
	}
	dfs(1,0);
	ans = 1ll << 60;
	for(ll i = 1;i <= e; ++i)
	{
		if(!vis[i])
		{
			ans = min(ans,sum - work(a[i].x,a[i].y,a[i].z) + a[i].z);
		}
	}
	cout<<ans<<endl;
	return 0;
}