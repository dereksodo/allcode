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
	#define debug prllf
#else
	#define debug(...)
#endif
const ll maxn = 1e5 + 5;
const ll maxm = 2e9 + 5;
ll a[maxn],prime[maxn],plen;
void init()
{
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
int isprime(ll s)
{
	if(s == 1)
	{
		return 0;
	}
	if(s < maxn)
	{
		return !a[s];
	}
	for(int i = 0;prime[i] * prime[i] <= s; ++i)
	{
		if(s % prime[i] == 0)
		{
			return 0;
		}
	}
	return 1;
}
ll n;
ll ans[maxn];
void dfs(ll pre,ll pos,ll now)
{
	if(now == 1)
	{
		ans[++ans[0]] = pre;
	}
	else
	{
		if(now - 1 > prime[pos] && isprime(now - 1))
		{
			ans[++ans[0]] = pre * (now - 1);
		}
		for(int j = pos + 1;prime[j] * prime[j] <= now; ++j)
		{
			for(ll t = prime[j],s = t + 1;s <= now;t *= prime[j],s += t)
			{
				if(now % s == 0)
				{
					dfs(pre * t,j,now / s);
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	// scanf("%lld",&n);
	init();
	// printf("hi\n");
	while(~scanf("%lld",&n))
	{
		ans[0] = 0;
		dfs(1,-1,n);
		sort(ans + 1,ans + ans[0] + 1);
		printf("%lld\n",ans[0]);
		for(int i = 1;i <= ans[0]; ++i)
		{
			printf("%lld ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}