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
const int maxn = (1 << 17);
int prime[maxn],plen;
int a[maxn];
void init()//O(n)
{
	for(int i = 2;i < maxn; ++i)
	{
		if(!a[i])
		{
			prime[plen++] = i;
		}
		for(int j = 0;j < plen && i * prime[j] <= maxn; ++j)
		{
			a[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
map<ll,ll> mp;
void go(ll p)
{
	if(p < 2)
	{
		return;
	}
	for(int i = 0;i < plen; ++i)
	{
		while(p % prime[i] == 0)
		{
			mp[prime[i]]++;
			p /= prime[i];
		}
	}
	if(p != 1)
	{
		mp[p]++;
	}
}
bool go(ll p,ll s,ll cnt)
{
	ll ret = 0;
	while(p >= s)
	{
		ret += p / s;
		p /= s;
	}
	return ret >= cnt;
}
int main(int argc, char const *argv[])
{
	ll n,m;
	init();
	while(~scanf("%lld%lld",&n,&m))
	{
		mp.clear();
		go(m);
		bool flag = 1;
		for(map<ll,ll>::iterator iter = mp.begin();iter != mp.end(); ++iter)
		{
			ll first = iter->first;
			ll second = iter->second;
			if(!go(n,first,second))
			{
				flag = 0;
				break;
			}
		}
		printf("%lld ",m);
		if(flag)
		{
			printf("divides");
		}
		else
		{
			printf("does not divide");
		}
		printf(" %lld!\n",n);
	}
	return 0;
}