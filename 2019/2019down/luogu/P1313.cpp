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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll mod = 10007;
ll mypow(ll a,ll b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a;
	}
	ll ret = mypow(a,b / 2);
	return ret * ret % mod * mypow(a,b % 2) % mod;
}
ll ni(ll x)
{
	return mypow(x,mod - 2);
}
ll p(ll x)
{
	if(x == 0 || x == 1)
	{
		return 1ll;
	}
	return x * p(x - 1) % mod;
}
int main(int argc, char const *argv[])
{
	ll a,b,k,n,m;
	cin>>a>>b>>k>>n>>m;
	//ans = C(k,n) * (b ^ m) * (a ^ n);
	ll ans = p(k) * ni(p(n)) % mod * ni(p(k - n)) % mod * mypow(b,m) % mod * mypow(a,n) % mod;
	cout<<ans<<endl;
	return 0;
}