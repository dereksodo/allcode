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
using namespace std;
typedef long long ll;
static const ll maxn = 1e5 + 5;
ll n,p;
ll a[maxn];
namespace st1{
	map<ll,ll> mp1,mp2;
	ll mypow(ll x,ll y)
	{
		if(y == 0)
		{
			return 1ll;
		}
		if(y == 1)
		{
			return x;
		}
		ll ret = mypow(x,y / 2);
		return ret * ret % p * mypow(x,y % 2) % p;
	}
	ll getpow(ll x)
	{
		return mypow(x,p - 2);
	}
	ll main()
	{
		// cin>>n>>p;
		// for(ll i = 1;i <= n; ++i)
		// {
		// 	scanf("%d",&a[i]);
		// }
		mp1.clear(),mp2.clear();
		for(ll i = 1;i <= n; ++i)
		{
			mp1[(a[i] * a[i]) % p * 2 % p]++;
		}
		for(ll i = 1;i <= n; ++i)
		{
			mp2[getpow(2 * a[i])]++;
		}
		// printf("*************\n");
		// for(map<ll,ll>::iterator iter = mp1.begin();iter != mp1.end(); ++iter)
		// {
		// 	printf("%lld %lld\n",iter->first,iter->second);
		// }
		// printf("*************\n");
		// for(map<ll,ll>::iterator iter = mp2.begin();iter != mp2.end(); ++iter)
		// {
		// 	printf("%lld %lld\n",iter->first,iter->second);
		// }
		ll ans = 0;
		for(map<ll,ll>::iterator iter = mp1.begin();iter != mp1.end(); ++iter)
		{
			if(iter->first == 0)
			{
				continue;
			}
			ans += mp2[iter->first] * (iter->second);
		}
		return ans;
	}
};
namespace st2{
	ll main()
	{
		ll ans = 0;
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= n; ++j)
			{
				ll now = (a[i] * a[i] % p) + a[j];
				now %= p;
				now = now * now % p;
				ll now2 = (a[i] * a[i] % p) - a[j];
				while(now2 < 0)
				{
					now2 += 100 * p;
				}
				now2 %= p;
				now2 = (now2 * now2 + 1) % p;
				if(now == now2)
				{
					ans++;
				}
			}
		}
		return ans;
	}
};
bool is_prime(ll a)//O(sqrt(n) / 6)
{
	if(a < 2)
	{
		return 0;
	}
	if(a == 2 || a == 3)
	{
		return 1;
	}
	if(a % 6 != 1 && a % 6 != 5)
	{
		return 0;
	}
	for(int i = 5;i * i <= a; i += 6)
	{
		if(a % i == 0 || a % (i + 2) == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	// cin>>n>>p;
	// for(ll i = 1;i <= n; ++i)
	// {
	// 	scanf("%lld",&a[i]);
	// }
	int cnt = 0;
	while(1)
	{
		map<ll,int> mp;
		cnt++;
		n = 500;
		p = rand() * 12321ll % 100000;
		while(!is_prime(p))
		{
			++p;
		}
		for(int i = 1;i <= n; ++i)
		{
			a[i] = rand() * 12364ll % ll(1e8);
			a[i] %= p;
		}
		ll ans1 = st1::main();
		ll ans2 = st2::main();
		if(ans1 != ans2)
		{
			printf("NO\n");
			if(is_prime(p))
			{
				printf("Yes\n");
			}
			printf("ans1 = %lld,ans2 = %lld\n",ans1,ans2);
			printf("%lld %lld\n",n,p);
			for(int i = 1;i <= n; ++i)
			{
				printf("%lld ",a[i]);
			}
			printf("\n");
			return 0;
		}
		if(cnt % 100 == 0)
		{
			printf("pre tests %d are all ok!\n",cnt);
		}
	}
	return 0;
}