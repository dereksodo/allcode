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
const ll mod = 1e9 + 7;
ll mypow(ll s,ll t)
{
	if(t == 0)
	{
		return 1ll;
	}
	if(t == 1)
	{
		return s;
	}
	ll ret = mypow(s,t / 2);
	return ret * ret % mod * mypow(s,t % 2) % mod;
}
ll ni(ll s)
{
	return mypow(s,mod - 2);
}
ll jie(ll s)
{
	if(s == 0)
	{
		return 1ll;
	}
	return s * jie(s - 1) % mod;
}
int main(int argc, char const *argv[])
{
	ll n,k;
	cin>>n>>k;
	ll ans = 0;
	for(int i = 0;i <= n; ++i)
	{
		ll retnow = mypow((mypow(k,n - i) * mypow(k - 1,i) % mod - mypow(k - 1,n) + mod) % mod,n);
		ll p = jie(n) * ni(jie(n - i)) % mod * ni(jie(i)) % mod;
		ll ss = mypow(-1,i);
		ans += (retnow * p % mod * ss + mod) % mod;
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}