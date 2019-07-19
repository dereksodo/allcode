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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 3e5 + 5;
ll a[maxn];
map<ll,ll> mp;
int main(int argc, char const *argv[])
{
	ll n,p,k;
	cin>>n>>p>>k;
	for(int i = 0;i < n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	ll ans = 0;
	for(int i = 0;i < n; ++i)
	{
		ll x = a[i];
		x %= p;
		ll value = x * (((x * x) % p * x) % p - k) % p;
		if(value < 0)
		{
			value += p;
		}
		ans += mp[value];
		mp[value]++;
	}
	printf("%lld\n",ans);
	return 0;
}