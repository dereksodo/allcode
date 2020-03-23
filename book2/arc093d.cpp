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
const int maxn = (1 << 17) + 5;
const int maxm = maxn - 5;
const int mod = 1e9 + 7;
ll invf[maxn],f[maxn];
ll dp[20][maxn];
ll n,m,a[20];
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
ll c(ll n,ll k)
{
	if(n < k)
	{
		return 0;
	}
	return f[n] * invf[k] % mod * invf[n - k] % mod;
}
void init()
{
	f[0] = 1;
	for(int i = 1;i <= maxm; ++i)
	{
		f[i] = f[i - 1] * i % mod;
	}
	invf[maxm] = mypow(f[maxm],mod - 2);
	for(int i = maxm;i >= 1; --i)
	{
		invf[i - 1] = invf[i] * i % mod;
	}
	invf[0] = 1;
	dp[0][0] = 1;
}
ll getbit(ll state)
{
	ll res = 0;
	while(state)
	{
		res += state & 1;
		state >>= 1;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		scanf("%lld",&a[m - i + 1]);
	}
	init();
	int final = (1 << n);
	for(int i = 0;i < m; ++i)
	{
		for(int state = 0;state < final; ++state)
		{
			if(dp[i][state])
			{
				(dp[i + 1][state] += dp[i][state]) %= mod;
				for(int j = 0;j < n; ++j)
				{
					if(((1 << j) & state) == 0)
					{
						(dp[i + 1][state | (1 << j)] += 
							(dp[i][state] * f[(1 << j)] % mod * 
							c(final - state - a[i + 1],
							(1 << j) - 1)) % mod) %= mod;
					}
				}
			}
		}
	}
	ll ans = 0;
	for(int state = 0;state < final; ++state)
	{
		ll cnt = getbit(state);
		ll fg = (cnt & 1) ? -1 : 1;
		(ans += fg * dp[m][state] * f[final - state - 1] % mod) %= mod;
	}
	ans = (ans + mod) % mod;
	printf("%lld\n",(ans * final) % mod);
	return 0;
}