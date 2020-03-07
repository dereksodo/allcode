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
ll a,b,p,d;
ll mypow(ll a,ll b,ll mod)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a % mod;
	}
	ll res = mypow(a,b / 2,mod);
	return res * res % mod * (b & 1 ? a : 1) % mod;
}
ll solve1()
{
	return mypow(a,b,p);
}
ll gcd(ll a,ll b)
{
	return b == 0 ? a : gcd(b,a % b);
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		d = a,x = 1,y = 0;
		return;
	}
	exgcd(b,a % b,x,y);
	ll t = x;
	x = y;
	y = t - a / b * y;
}
void solve2()
{
	ll x,y;
	exgcd(a,p,x,y);
	if(b % d != 0)
	{
		printf("Orz, I cannot find x!\n");
		return;
	}
	printf("%lld\n",(x * (b / d) % (p / d) + (p / d)) % (p / d));
}
map<ll,ll> mp;
void solve3()
{
	ll tmp,t = 0,cnt = 0,x,y;
	mp.clear();
	while(1)
	{
		tmp = gcd(a,p);
		if(tmp == 1)
		{
			break;
		}
		if(b % tmp != 0)
		{
			printf("Orz, I cannot find x!\n");
			return;
		}
		t = t + a / tmp;
		b /= tmp;
		p /= tmp;
		++cnt;
	}
	if(cnt)
	{
		exgcd(t,p,x,y);
		if(d != 1)
		{
			printf("Orz, I cannot find x!\n");
			return;
		}
		x = (x * (p / d) + (p / d)) % (p / d);
		b = b * x % p;
	}
	ll m = ceil(sqrt(p));
	tmp = 1;
	mp[1] = m + 1;
	for(int j = 1;j <= m; ++j)
	{
		tmp = tmp * a % p;
		if(!mp[tmp])
		{
			mp[tmp] = j;
		}
	}
	t = 1;
	for(ll i = 0,j;i <= m; ++i)
	{
		exgcd(t,p,x,y);
		t = t * tmp % p;
		if(b % d != 0)
		{
			continue;
		}
		j = mp[(x * (b / d) % (p / d) + (p / d)) % (p / d)];
		if(j)
		{
			cnt += (i * m + j);
			if(j == m + 1)
			{
				cnt -= j;
			}
			printf("%lld\n",cnt);
			return;
		}
	}
	printf("Orz, I cannot find x!\n");
}
int main(int argc, char const *argv[])
{
	int t,k;
	scanf("%d%d",&t,&k);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&p);
		ll ans;
		if(k == 1)
		{
			printf("%lld\n",solve1());
		}
		else if(k == 2)
		{
			solve2();
		}
		else
		{
			solve3();
		}
	}
	return 0;
}