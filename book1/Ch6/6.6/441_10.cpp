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
const ll maxn = 2000005;
ll a[maxn],prime[maxn],plen;
ll cnt[maxn],ans = 1,mod,n;
ll mypow(ll x,ll y)
{
	ll res = 1;
	while(y)
	{
		if(y & 1)
		{
			res = res * x % mod;
		}
		y >>= 1;
		x = x * x % mod;
	}
	return res;
}
void add(ll num)
{
	while(num ^ 1)
	{
		++cnt[a[num]];
		num /= a[num];
	}
}
void del(ll num)
{
	while(num ^ 1)
	{
		--cnt[a[num]];
		num /= a[num];
	}
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld",&n,&mod);
	for(ll i = 2;i <= 2 * n; ++i)
	{
		if(!a[i])
		{
			a[i] = prime[++plen] = i;
		}
		for(ll j = 1;j <= plen; ++j)
		{
			if(i * prime[j] > 2 * n || prime[j] > a[i])
			{
				break;
			}
			a[i * prime[j]] = prime[j];
		}
	}
	for(ll i = 1;i <= n; ++i)
	{
		del(i);
	}
	for(ll i = n + 2;i <= n * 2; ++i)
	{
		add(i);
	}
	for(ll i = 2;i <= 2 * n; ++i)
	{
		if(a[i] == i)
		{
			ans = ans * mypow(i,cnt[i]) % mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}