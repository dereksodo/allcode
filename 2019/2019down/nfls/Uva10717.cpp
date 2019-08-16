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
	#define debug prllf
#else
	#define debug(...)
#endif
ll n,t;
ll a[55];
ll T;
ll maxans,minans;
ll gcd(ll c,ll b)
{
	return b == 0ll ? c : gcd(b,c % b);
}
ll lcm(ll c,ll b)
{
	return c / gcd(c,b) * b;
}
int main(int argc, char const *argv[])
{
	while(scanf("%lld%lld",&n,&t) && n && t)
	{
		memset(a,0x00,sizeof(a));
		T = 0;
		for(ll i = 1;i <= n; ++i)
		{
			scanf("%lld",&a[i]);
		}
		for(ll i = 1;i <= t; ++i)
		{
			maxans = 0,minans = 1e18;
			scanf("%lld",&T);
			for(int i = 1;i <= n; ++i)
			{
				for(int j = i + 1;j <= n; ++j)
				{
					for(int k = j + 1;k <= n; ++k)
					{
						for(int l = k + 1;l <= n; ++l)
						{
							ll g = lcm(a[i],lcm(a[j],lcm(a[k],a[l])));
							if(g < T && T - T % g > maxans)
							{
					            maxans = T - T % g;
							}
					        if((g - T % g) % g + T < minans)
					        {
					            minans = (g - T % g) % g + T;
					        }
						}
					}
				}
			}
			printf("%lld %lld\n",maxans,minans);
		}
	}
	return 0;
}