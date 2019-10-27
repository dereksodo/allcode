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
ll mypow(ll a,ll b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a % mod;
	}
	ll ret = mypow(a,b / 2);
	return ret * ret % mod * mypow(a,b % 2) % mod;
}
ll sp(ll a)
{
	a %= mod;
	return (a * (a + 1) % mod * (a + 2) % mod) * mypow(6,mod - 2) % mod;
}
int main(int argc, char const *argv[])
{
	ll n,m;
	cin>>n>>m;
	ll ret1 = sp(n);
	ll ret2 = sp(m);
	printf("%lld\n",ret1 * ret2 % mod);
	return 0;
}