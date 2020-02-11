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
ll n,k,m;
bool check(ll x)
{
	ll g = 0;
	ll day = 0;
	while((n - g) / x > m)
	{
		day++;
		ll now = (n - g) / x;
		g += now;
		// printf("%lld\n",now);
		// printf("**%lld\n",(n - g) / x);
		// printf("***%lld\n",m);
		if(day == k)
		{
			return g >= n;
		}
	}
	g += m * (k - day);
	return g >= n;
}
int main(int argc, char const *argv[])
{
	freopen("loan.in","r",stdin);
	freopen("loan.out","w",stdout);
	cin>>n>>k>>m;
	ll lhs = 1,rhs = 1e13;
	ll ans = 0;
	while(lhs <= rhs)
	{
		ll mid = lhs + rhs >> 1;
		// printf("mid = %lld\n",mid);
		if(check(mid))
		{
			ans = mid;
			lhs = mid + 1;
		}
		else
		{
			rhs = mid - 1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}