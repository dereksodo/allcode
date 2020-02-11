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
namespace sol1{
	ll n,k,m;
	bool check(ll x)
	{
		ll g = 0;
		ll day = 0;
		while((n - g) / x > m)
		{
			day++;
			ll now = (n - g) / x;
			g += now;
			// printf("%lld\n",now);
			// printf("**%lld\n",(n - g) / x);
			// printf("***%lld\n",m);
			if(day == k)
			{
				return g >= n;
			}
		}
		g += m * max(0ll,(k - day));
		return g >= n;
	}
	ll main(ll a,ll b,ll c)
	{
		n = a,k = b,m = c;
		ll lhs = 1,rhs = 1e13;
		ll ans = 0;
		while(lhs <= rhs)
		{
			ll mid = lhs + rhs >> 1;
			if(check(mid))
			{
				ans = mid;
				lhs = mid + 1;
			}
			else
			{
				rhs = mid - 1;
			}
		}
		return ans;
	}
};
namespace sol2{
	ll n,k,m;
	ll main(ll a,ll b,ll c)
	{
		n = a,k = b,m = c;
		for(ll x = 1;; ++x)
		{
			ll g = 0;
			ll day = 0;
			ll flag = 1;
			while((n - g) / x > m)
			{
				day++;
				ll now = (n - g) / x;
				g += now;
				if(day == k)
				{
					if(g < n)
					{
						flag = 0;
					}
					break;
				}
			}
			g += m * max(0ll,(k - day));
			if(g < n)
			{
				flag = 0;
			}
			if(flag == 0)
			{
				return x - 1;
			}
		}
	}
};
int main(int argc, char const *argv[])
{
	int test = 0;
	srand(time(NULL));
	while(1)
	{
		test++;
		if(test % 100 == 0)
		{
			printf("test %d ok!\n",test);
		}
		ll nn,kk,mm;

		kk = rand() % 1000;
		mm = rand() % 1000;
		nn = kk * mm + rand() % 1000 + rand() % 5 + 1;

		ll ret1 = sol1::main(nn,kk,mm);
		ll ret2 = sol2::main(nn,kk,mm);
		if(ret1 != ret2)
		{
			printf("ERROR!\n%d %d %d\n",nn,kk,mm);
			printf("ret1 = %lld,ret2 = %lld\n",ret1,ret2);
			return 0;
		}
	}
	return 0;
}