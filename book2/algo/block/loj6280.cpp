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
const int maxn = 50010;
ll n,blocksz;
ll pos[maxn];
ll v[maxn],block[maxn],tag[maxn];
ll sum[maxn],mod;
void add(ll l,ll r,ll c)
{
	for(int i = l;i <= min(pos[l] * blocksz,r); ++i)
	{
		v[i] += c;
		sum[pos[i]] += c;
	}
	if(pos[l] != pos[r])
	{
		ll t = pos[r];
		for(int i = (pos[r] - 1) * blocksz + 1;i <= r; ++i)
		{
			v[i] += c;
			sum[t] += c;
		}
	}
	for(int i = pos[l] + 1;i <= pos[r] - 1; ++i)
	{
		tag[i] += c;
		sum[i] += c * blocksz;
	}
}
ll query(ll l,ll r)
{
	ll h = pos[l];
	ll ans = 0;
	for(int i = l;i <= min(pos[l] * blocksz,r); ++i)
	{
		ans += v[i] + tag[h];
		ans %= mod;
	}
	if(pos[l] != pos[r])
	{
		int t = pos[r];
		for(int i = (pos[r] - 1) * blocksz + 1;i <= r; ++i)
		{
			ans += v[i] + tag[t];
			ans %= mod;
		}
	}
	for(int i = pos[l] + 1;i <= pos[r] - 1; ++i)
	{
		ans += sum[i];
		ans %= mod;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	blocksz = sqrt(n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&v[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		pos[i] = (i - 1) / blocksz + 1;
	}
	for(int i = 1;i <= n; ++i)
	{
		sum[pos[i]] += v[i];
	}
	for(ll i = 1,opt,l,r,c;i <= n; ++i)
	{
		scanf("%lld%lld%lld%lld",&opt,&l,&r,&c);
		if(opt == 0)
		{
			add(l,r,c);
		}
		else
		{
			mod = c + 1;
			printf("%lld\n",query(l,r));
		}
	}
	return 0;
}