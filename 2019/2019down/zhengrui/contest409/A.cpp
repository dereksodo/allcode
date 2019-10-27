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
ll a[maxn];
map<ll,ll> mp;
ll n,p;
ll mypow(ll x,ll y)
{
	if(y == 0)
	{
		return 1ll;
	}
	if(y == 1)
	{
		return x;
	}
	ll ret = mypow(x,y / 2);
	return ret * ret % p * mypow(x,y % 2) % p;
}
ll getpow(ll x)
{
	return mypow(x,p - 2);
}
int main(int argc, char const *argv[])
{
	cin>>n>>p;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
		a[i] %= p;
		if(a[i] == 0)
		{
			continue;
		}
		mp[getpow(a[i])]++;
	}
	ll ans = 0;
	for(ll i = 1;i <= n; ++i)
	{
		ll now = 4 * a[i] % p * a[i] % p;
		if(now == 0)
		{
			continue;
		}
		ans += mp[now];
		if(now == getpow(a[i]))
		{
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}