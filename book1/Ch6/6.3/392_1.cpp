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
const int maxn = (1 << 15);
int a[maxn],prime[maxn],plen;
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
ll n;
vector<ll> v;
void doit()
{
	for(int i = 0;prime[i] <= n && prime[i] != 0; ++i)
	{
		if(n % prime[i] == 0)
		{
			int x = 0;
			while(n % prime[i] == 0)
			{
				x++;
				n /= prime[i];
			}
			v.push_back(x);
		}
	}
	if(n != 1)
	{
		v.push_back(1);
	}
}
ll mul(ll a)
{
	if(a < 2)
	{
		return 1;
	}
	return a * mul(a - 1);
}
int main(int argc, char const *argv[])
{
	init();
	while(~scanf("%lld",&n))
	{
		v.clear();
		doit();
		ll sum = 0;
		for(int i = 0;i < v.size(); ++i)
		{
			sum += v[i];
		}
		printf("%lld ",sum);
		ll ans = mul(sum);
		for(int i = 0;i < v.size(); ++i)
		{
			ans /= mul(v[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}