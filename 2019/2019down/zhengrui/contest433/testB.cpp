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
namespace s1{
	static const ll mod = 1e9 + 7;
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
	ll sol(ll n,ll m)
	{
		ll ret1 = sp(n);
		ll ret2 = sp(m);
		return ret1 * ret2 % mod;
	}
};
namespace s2{
	static const ll mod = 1e9 + 7;
	ll sol(ll n,ll m)
	{
		ll tmp = 0;
		ll i,j,k,l,x,y;
		for (i = 1; i <= n; ++i)
        	for (j = 1; j <= m; ++j)
           	 	for (k = i; k <= n; ++k)
                	for (l = j; l <= m; ++l)
                   	 	for (x = i; x <= k; ++x)
                        	for (y = j; y <= l; ++y) 
                        	{
                        		tmp++;
                        		tmp %= mod;
                        	}
                    
        return tmp;
	}
};
int main(int argc, char const *argv[])
{
	for(ll i = 1;i <= 100; ++i)
	{
		for(ll j = 1;j <= 100; ++j)
		{
			ll ret1 = s1::sol(i,j);
			ll ret2 = s2::sol(i,j);
			if(ret1 != ret2)
			{
				printf("ERROR!     %lld %lld\nret1 = %lld,ret2 = %lld\n",i,j,ret1,ret2);
			}
		}
	}
	return 0;
}