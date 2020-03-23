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
const int maxn = 5e5 + 5;
const int maxm = maxn - 5;
const int mod = 998244353;
ll f[maxn],invf[maxn];
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
ll n,m,ans;
void init()
{
	f[0] = 1;
	for(int i = 1;i <= n; ++i)
	{
		f[i] = f[i - 1] * i % mod;
	}
	invf[n] = mypow(f[n],mod - 2);
	for(int i = n - 1;i >= 0; --i)
	{
		invf[i] = invf[i + 1] * (i + 1) % mod;
	}
}
ll comb(ll n,ll k)
{
	if(n < 0 || k < 0 || n < k)
	{
		return 0;
	}
	return f[n] * invf[k] % mod * invf[n - k] % mod;
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld",&n,&m);
	if(n < m)
	{
		swap(n,m);
	}
	init();
	for(int k = 0;k <= m; ++k)
	{
		ll fg = k & 1 ? -1 : 1;
		ans += fg * comb(n,k) % mod * comb(m,k) % mod * f[k] % mod
				* mypow(m + 1,n - k) % mod * mypow(n + 1,m - k) % mod;
		ans %= mod;
		ans = (ans + mod) % mod;
	}
	printf("%lld\n",ans);
	return 0;
}