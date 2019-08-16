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
ll a[20];
ll ans,n,m;
ll gcd(ll c,ll b)
{
	return b == 0 ? c : gcd(b,c % b);
}
ll lcm(ll c,ll b)
{
	return c / gcd(c,b) * b; 
}
void solve(ll pos,ll cnt,ll now)
{
	if(cnt & 1)
	{
		ans += n / now;
	}
	else
	{
		ans -= n / now;
	}
	for(int i = pos;i <= m; ++i)
	{
		solve(i + 1,cnt + 1,lcm(a[i],now));
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	ans = 0;
	for(int i = 1;i <= m; ++i)
	{
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= m; ++i)
	{
		solve(i + 1,1,a[i]);
	}
	printf("%lld\n",n - ans);
	return 0;
}