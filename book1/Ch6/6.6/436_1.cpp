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
const ll mod = 5000011;
ll n,k;
ll mypow(ll a,ll b)
{
	ll res = 1;
	for(;b;b >>= 1,a = a * a % mod)
	{
		if(b & 1)
		{
			(res *= a) %= mod;
		}
	}
	return res;
}
ll C(ll n,ll m)
{
	if(m > n - m)
	{
		m = n - m;
	}
	ll s1 = 1,s2 = 1;
	for(int i = 1;i <= m; ++i)
	{
		(s1 *= (n - i + 1)) %= mod;
	}
	for(int i = 1;i <= m; ++i)
	{
		(s2 *= i) %= mod;
	}
	return s1 * mypow(s2,mod - 2) % mod;
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld",&n,&k);
	ll ans = 1;
	for(int i = 1;i <= n; ++i)
	{
		int t = n - (i - 1) * k;
		if(t < i)
		{
			break;
		}
		ans = (ans + C(t,i)) % mod;
	}
	printf("%lld\n",ans);
	return 0;
}