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
const ll maxn = 2e5 + 5;
ll n,m;
ll a[maxn],cnt[maxn];
ll s1[maxn << 2],c[maxn << 2];
ll getsum(int x)
{
	ll sum = 0;
	for(;x;x -= x & (-x))
	{
		sum += c[x];
	}
	return sum;
}
void add(int x)
{
	for(;x <= n; x += x & (-x))
	{
		c[x]++;
	}
}
void cal(ll *a,ll *ans)
{
	memset(c,0x00,sizeof(c));
	for(int i = 1;i <= n; ++i)
	{
		ans[i] = (i - 1) - getsum(a[i]);
		add(a[i]);
	}
}
int main(int argc, char const *argv[])
{
	freopen("bubble.in","r",stdin);
	freopen("bubble.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	int fg = 0;
	while(m--)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(op == 1)
		{
			swap(a[x],a[x + 1]);
			fg = 1;
			continue;
		}
		else
		{
			if(fg)
			{
				cal(a,s1);
			}
			fg = 0;
			ll mx = 0,sum = 0;
			for(int i = 1;i <= n; ++i)
			{
				sum += max(0ll,s1[i] - x);
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}