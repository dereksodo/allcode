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
using namespace std;
typedef long long ll;
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll maxn = 2e5 + 5;
ll a[maxn],b[maxn];
ll n;
void ask(ll pos)
{
	set<ll> x;
	x.clear();
	for(int i = 0;i < n; ++i)
	{
		if(i != pos)
		{
			x.insert(a[i]);
		}
	}
	ll c = 0;
	ll d = 0;
	if(pos == 0)
	{
		c = a[1];
		d = a[2] - a[1];
	}
	else
	{
		if(pos == 1)
		{
			c = a[0];
			d = a[2] - a[0];
		}
		else
		{
			c = a[0];
			d = a[1] - a[0];
		}
	}
	debug("c = %d,d = %d\n",c,d);
	ll cnt = 0;
	for(auto iter = x.begin();iter != x.end(); ++iter,++cnt)
	{
		if(*iter != c + d * cnt)
		{
			return;
		}
	}
	ll ad = a[pos];
	for(int i = 0;i < n; ++i)
	{
		if(b[i] == ad)
		{
			printf("%d\n",i + 1);
			exit(0);
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	ll sum = 0;
	for(int i = 0;i < n; ++i)
	{
		scanf("%lld",&a[i]);
		b[i] = a[i];
		sum += a[i];
	}
	sort(a,a + n);
	ll sumnow = (a[0] + a[n - 1]) * (n - 1) / 2;
	ll p = sum - sumnow;
	ll ind = lower_bound(a,a + n,p) - a;
	if(a[ind] == p)
	{
		ask(ind);
	}
	sumnow = (a[1] + a[n - 1]) * (n - 1) / 2;
	p = sum - sumnow;
	debug("p = %d\n",p);
	ind = lower_bound(a,a + n,p) - a;
	debug("ind = %d\n",ind);
	if(a[ind] == p)
	{
		ask(ind);
	}
	sumnow = (a[0] + a[n - 2]) * (n - 1) / 2;
	p = sum - sumnow;
	ind = lower_bound(a,a + n,p) - a;
	if(a[ind] == p)
	{
		ask(ind);
	}
	printf("-1\n");
	return 0;
}