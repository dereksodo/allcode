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
const ll maxn = 1e6 + 6;
const ll mod = 1e9 + 7;
ll a[maxn],n,m,c[maxn];
ll mypow(ll x,ll y)
{
	if(y == 0)
	{
		return 1;
	}
	else if(y == 1)
	{
		return x;
	}
	ll res = mypow(x,y / 2);
	return res * res % mod * mypow(x,y % 2) % mod;
}
void init(ll k)
{
	for(int i = 0;i < k; ++i)
	{
		c[i] = 0;
	}
	c[k] = 1;
	for(int i = k + 1;i <= n; ++i)
	{
		c[i] = c[i - 1] * i % mod * mypow(i - k,mod - 2) % mod;
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	ll k = n / m;
	init(k - 1);
	for(int i = 1;i <= m; ++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + m + 1);
	reverse(a + 1,a + m + 1);
	ll ans = 1;
	for(int i = 1;i <= m; ++i)
	{
		ans *= c[n - a[i] - k * (i - 1)];
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}