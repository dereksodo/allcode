//Modular GCD
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
ll a,b,n;
ll mod = 1e9 + 7;
ll powme(ll a,ll n)
{
	if(n == 0)
	{
		return 1;
	}
	if(n % 2 == 0)
	{
		ll x = powme(a,n / 2);
		return static_cast<ll>(__int128(x) * __int128(x) % mod);
	}
	else
	{
		return static_cast<ll>(__int128(a) * __int128(powme(a,n - 1)) % mod);
	}
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		mod = static_cast<ll>(1e9 + 7);
		mod = a == b ? mod : a - b;
		printf("%lld\n",__gcd((a - b),(powme(a,n) + powme(b,n)) % mod));
	}
	return 0;
}