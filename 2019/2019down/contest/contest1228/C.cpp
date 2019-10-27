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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 5;
ll prime[maxn],plen;
bool a[maxn];
void init()//O(n)
{
	for(ll i = 2;i < maxn; ++i)
	{
		if(!a[i])
		{
			prime[plen++] = i;
		}
		for(ll j = 0;j < plen && i * prime[j] <= maxn; ++j)
		{
			a[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
vector<ll> ans;
void go(ll p)
{
	ans.clear();
	if(p < 2)
	{
		return;
	}
	for(ll i = 0;i < plen; ++i)
	{
		if(p % prime[i] == 0)
		{
			ans.push_back(prime[i]);
			debug("%lld ",prime[i]);
			while(p % prime[i] == 0)
			{
				p /= prime[i];
			}
		}
	}
	if(p != 1)
	{
		ans.push_back(p);
		debug("%lld ",p);
	}
	debug("\n");
}
ll mypow(ll s,ll t)
{
	if(t == 0)
	{
		return 1ll;
	}
	if(t == 1)
	{
		return s;
	}
	ll ret = mypow(s,t / 2);
	return ret * ret % mod * mypow(s,t % 2) % mod;
}
ll x,n;
ll count_num(ll p)
{
	ll ret = 0;
	ll n2 = n;
	while(n2 >= p)
	{
		ret += n2 / p;
		n2 /= p;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	init();
	cin>>x>>n;
	go(x);
	ll ret = 1;
	for(int i = 0;i < ans.size(); ++i)
	{
		ret = ret * (mypow(ans[i],count_num(ans[i]))) % mod;
	}
	cout<<ret<<endl;
	return 0;
}