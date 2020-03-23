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
const int maxn = 5005;
ll x[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
ll cal(ll i,ll j)
{
	if(i < j)
	{
		return -x[i] + x[j] + d[i] + a[j];
	}
	else
	{
		return x[i] - x[j] + c[i] + b[j];
	}
}
int main(int argc, char const *argv[])
{
	ll n,s,e;
	scanf("%lld%lld%lld",&n,&s,&e);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&x[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&b[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&c[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&d[i]);
	}
	ll ans = 0;
	if(min(s,e) == 1)
	{
		ans += cal(s,e);
	}
	else
	{
		ans += cal(s,1) + cal(1,e);
	}
	priority_queue< ll,vector<ll>,greater<ll> > hp;
	ll A,B,C,D;
	for(int i = 2;i <= n; ++i)
	{
		A = x[i] + a[i];
		B =-x[i] + b[i];
		C = x[i] + c[i];
		D =-x[i] + d[i];
		if(i == s)
		{
			hp.push(D - C);
		}
		else if(i == e)
		{
			hp.push(B - A);
		}
		else
		{
			ans += A + C;
			if(i < s)
			{
				hp.push(B - A);
			}
			if(i < e)
			{
				hp.push(D - C);
			}
			ans += hp.top();
			hp.pop();
			if(i > s)
			{
				hp.push(B - A);
			}
			if(i > e)
			{
				hp.push(D - C);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}