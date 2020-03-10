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
const int mod = 1e6 + 3;
ll fact[mod + 5];
ll inv[mod + 5];
ll mypow(ll a,ll b)
{
	ll res = 1;
	for(;b;b >>= 1,a = a * a % mod)
	{
		if(b & 1)
		{
			res = res * a % mod;
		}
	}
	return res;
}
void init()
{
	fact[0] = 1;
	for(int i = 1;i < mod; ++i)
	{
		fact[i] = fact[i - 1] * i % mod;
	}
	inv[mod - 1] = mypow(fact[mod - 1],mod - 2);
	for(int i = mod - 2;i >= 0; --i)
	{
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
}
ll c(ll n,ll m)
{
	if(n < m)
	{
		return 0;
	}
	return fact[n] * inv[m] % mod * inv[n - m] % mod;
}
ll lucas(ll n,ll m)
{
	if(n == 0)
	{
		return 1;
	}
	if(n < m)
	{
		return 0;
	}
	return lucas(n / mod,m / mod) * c(n % mod,m % mod) % mod;
}
int main(int argc, char const *argv[])
{
	init();
	int s;
	scanf("%d",&s);
	while(s--)
	{
		ll n,l,r;
		scanf("%lld%lld%lld",&n,&l,&r);
		ll len = r - l + 1;
		printf("%lld\n",(lucas(len + n,n) - 1 + mod) % mod);
	}
	return 0;
}