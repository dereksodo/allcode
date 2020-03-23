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
const int maxn = 50005;
const int maxblcsz = 1000;
ll n,m,opt,l,r,c;
ll v[maxn],tag[maxn],pos[maxn];
ll vec[maxblcsz][maxblcsz];
ll sz[maxblcsz];
void reset(ll x)
{
	sz[pos[x]] = 0;
	for(ll i = (x - 1) * m + 1;i <= x * m; ++i)
	{
		vec[x][sz[pos[x]]++] = v[i];
	}
	sort(vec[x],vec[x] + sz[pos[x]]);
}
void modify(ll l,ll r,ll c)
{
	if(pos[l] == pos[r])
	{
		for(ll i = l;i <= r; ++i)
		{
			v[i] += c;
		}
		reset(pos[l]);
		return;
	}
	for(ll i = l;i <= pos[l] * m; ++i)
	{
		v[i] += c;
	}
	reset(pos[l]);
	for(ll i = pos[l] + 1;i <= pos[r] - 1; ++i)
	{
		tag[i] += c;
	}
	for(ll i = (pos[r] - 1) * m + 1;i <= r; ++i)
	{
		v[i] += c;
	}
	reset(pos[r]);
}
ll query(ll l,ll r,ll f)
{
	ll ret = 0;
	if(pos[l] == pos[r])
	{
		for(ll i = l;i <= r; ++i)
		{
			if(v[i] + tag[pos[i]] < f)
			{
				++ret;
			}
		}
		return ret;
	}
	for(ll i = l;i <= pos[l] * m; ++i)
	{
		if(v[i] + tag[pos[i]] < f)
		{
			++ret;
		}
	}
	for(ll i = pos[l] + 1;i <= pos[r] - 1; ++i)
	{
		ll t = f - tag[i];
		ret += lower_bound(vec[i],vec[i] + sz[i],t) - vec[i];
	}
	for(ll i = (pos[r] - 1) * m + 1;i <= r; ++i)
	{
		if(v[i] + tag[pos[i]] < f)
		{
			++ret;
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	scanf("%lld",&n);
	m = sqrt(n);
	for(ll i = 1;i <= n; ++i)
	{
		pos[i] = (i - 1) / m + 1;
	}
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&v[i]);
		vec[pos[i]][sz[pos[i]]++] = v[i];
	}
	for(ll i = 1;i <= pos[n]; ++i)
	{
		sort(vec[i],vec[i] + sz[i]);
	}
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld%lld%lld%lld",&opt,&l,&r,&c);
		if(opt == 0)
		{
			modify(l,r,c);
		}
		else
		{
			printf("%lld\n",query(l,r,c * c));
		}
	}
	return 0;
}