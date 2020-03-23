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
const ll maxn = 1000010;
const ll maxm = maxn >> 1;
namespace set1{
	ll f[maxn],mx[maxn];
	void init(ll sz)
	{
		for(ll i = 1;i <= sz; ++i)
		{
			f[i] = i;
		}
	}
	ll ff(ll x)
	{
		if(f[x] == x)
		{
			return x;
		}
		ll p = ff(f[x]);
		if(p != f[x])
		{
			mx[x] = max(mx[x],mx[f[x]]);
			f[x] = p;
		}
		return p;
	}
	void join(ll x,ll y)
	{
		x = ff(x),y = ff(y);
		if(x != y)
		{
			f[x] = y;
		}
	}
	ll query(ll x)
	{
		if(f[x] == x)
		{
			return mx[x];
		}
		else
		{
			ll p = ff(x);
			return max(mx[x],mx[p]);
		}
	}
};
namespace set2{
	ll f[maxn];
	ll sumv[maxn];
	void init(ll sz)
	{
		for(ll i = 1;i <= sz; ++i)
		{
			f[i] = i;
		}
	}
	ll ff(ll x)
	{
		if(f[x] == x)
		{
			return x;
		}
		ll p = ff(f[x]);
		if(p != f[x])
		{
			sumv[x] += sumv[f[x]];
			f[x] = p;
		}
		return p;
	}
	void join(ll x,ll y)
	{
		x = ff(x),y = ff(y);
		if(x != y)
		{
			f[x] = y;
		}
	}
	ll query(ll x)
	{
		if(f[x] == x)
		{
			return sumv[x];
		}
		else
		{
			ll p = ff(x);
			return sumv[x] + sumv[p];
		}
	}
};
struct Query{
	ll x,v,id;
	Query(ll a = 0,ll b = 0,ll c = 0):x(a),v(b),id(c){};
};
vector<Query> vt[maxm];
ll ans[maxm];
pair<ll,ll> a[maxm];
ll sz[maxm];
int main(int argc, char const *argv[])
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	set1::init(n + m);
	ll nowsz = 0;
	char buf[5];
	for(ll i = 1;i <= m; ++i)
	{
		scanf("%s",buf);
		char c = buf[0];
		if(c == 'U')
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			a[i] = make_pair(x,y);
		}
		else if(c == 'M')
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			set1::join(x,n + i);
			set1::join(y,n + i);
		}
		else if(c == 'A')
		{
			ll x;
			scanf("%lld",&x);
			a[i] = make_pair(x,0);
		}
		else if(c == 'Z')
		{
			ll x;
			scanf("%lld",&x);
			set1::mx[set1::ff(x)] = i;
		}
		else
		{
			ll x;
			scanf("%lld",&x);
			++nowsz;
			ll t = set1::query(x);
			if(t)
			{
				vt[t].push_back(Query(x,-1,nowsz));
			}
			vt[i].push_back(Query(x,1,nowsz));
		}
	}
	for(ll i = 1;i <= n; ++i)
	{
		sz[i] = 1;
	}
	set2::init(n + m);
	for(ll i = 1;i <= m; ++i)
	{
		if(a[i].first && a[i].second)
		{
			ll x = a[i].first,y = a[i].second;
			set2::join(x,n + i);
			set2::join(y,n + i);
			sz[x] += sz[y];
		}
		else if(a[i].first)
		{
			ll x = a[i].first;
			set2::sumv[set2::ff(x)] += sz[x];
		}
		for(ll j = 0;j < vt[i].size(); ++j)
		{
			Query t = vt[i][j];
			ans[t.id] += set2::query(t.x) * t.v;
		}
	}
	for(ll i = 1;i <= nowsz; ++i)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}