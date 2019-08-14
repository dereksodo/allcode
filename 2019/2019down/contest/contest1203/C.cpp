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
const ll maxn = 1e6 + 5;
ll a[maxn],prime[maxn],plen,s[maxn];
void init()//O(n)
{
	plen = 0;
	for(ll i = 2;i < maxn; ++i)
	{
		if(!a[i])
		{
			prime[plen++] = i;
		}
		for(ll j = 0;j < plen && i * prime[j] < maxn; ++j)
		{
			a[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
ll go(ll p)
{
	ll ans = 1;
	for(ll i = 0;i < plen; ++i)
	{
		if(p % prime[i] == 0)
		{
			// printf("prime = %d\n",prime[i]);
			ll cnt = 0;
			while(p % prime[i] == 0)
			{
				p /= prime[i];
				cnt++;
			}
			ans *= (cnt + 1);
		}
	}
	if(p != 1)
	{
		ans *= 2;
	}
	return ans;
}
ll gcd(ll a,ll b)
{
	return b == 0 ? a : gcd(b,a % b);
}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	init();
	ll g = 0;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&s[i]);
		g = gcd(g,s[i]);
	}
	cout<<go(g)<<endl;
	return 0;
}