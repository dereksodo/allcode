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
	#define debug prllf
#else
	#define debug(...)
#endif
const ll maxn = 1e6 + 5;
const ll mod = 1e9 + 7;
ll a[maxn],prime[maxn],plen;
void init()
{
	for(ll i = 2;i < maxn; ++i)
	{
		if(!a[i])
		{
			prime[plen++] = i;
		}
		for(ll j = 0;j < plen && i * prime[j] < maxn; ++j)
		{
			a[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
void solve(ll x)
{
	ll ans = 1;
	for(ll i = 0;i < plen; ++i)
	{
		ll now = 0;
		for(ll j = prime[i];j <= x;j *= prime[i])
		{
			now = (now + (x / j) % mod) % mod;
		}
		ans = ans * ((now << 1 | 1) % mod) % mod;
	}
	printf("%lld\n",ans);
}
int main(int argc, char const *argv[])
{
	init();
	ll n;
	scanf("%lld",&n);
	solve(n);
	return 0;
}