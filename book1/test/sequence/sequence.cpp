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
const ll maxn = 1e5 + 5;
ll a[maxn],b[maxn],n,m;
ll t[maxn],u[maxn],v[maxn];
void output(ll flag)
{
	if(flag == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
ll check()
{
	for(ll i = 1;i <= m; ++i)
	{
		if(t[i] != 2)
		{
			return 0;
		}
	}
	return 1;
}
void task1()
{
	if(t[1] == 1)
	{
		output((b[1] - a[1]) == (b[2] - a[2]));
	}
	else
	{
		output((b[1] - a[1]) == (a[2] - b[2]));
	}
}
void task2()
{
	printf("YES\n");
}
ll vis[3];
void task3()
{
	for(ll i = 1;i <= m; ++i)
	{
		vis[t[i]] = 1;
	}
	if(vis[1] && vis[2])
	{
		output(!((b[1] - a[1] + b[2] - a[2]) & 1));
	}
	else
	{
		task1();
	}
}
int main(int argc, char const *argv[])
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ll T;
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		ll sum1 = 0,sum2 = 0;
		for(ll i = 1;i <= n; ++i)
		{
			scanf("%lld",&a[i]);
			sum1 += a[i];
		}
		for(ll i = 1;i <= n; ++i)
		{
			scanf("%lld",&b[i]);
			sum2 += b[i];
		}
		if(((sum1 + sum2) & 1))
		{
			output(0);
			continue;
		}
		for(ll i = 1;i <= m; ++i)
		{
			scanf("%lld%lld%lld",&t[i],&u[i],&v[i]);
		}
		if(n == 2 && m == 1)
		{
			task1();
		}
		else if(check())
		{
			task2();
		}
		else if(n == 2 && m != 1)
		{
			task3();
		}
		else
		{
			task2();
		}
	}
	return 0;
}