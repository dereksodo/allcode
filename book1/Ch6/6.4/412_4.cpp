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
ll d;
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		d = a,x = 1,y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}
int main(int argc, char const *argv[])
{
	ll a,b,c,k,x,y;
	while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&k))
	{
		if(a == 0 && b == 0 && c == 0 && k == 0)
		{
			break;
		}
		ll len = b - a;
		//1 ll << k, not 1 << k
		exgcd(c,(1ll << k),x,y);
		if((len % d))
		{
			printf("FOREVER\n");
		}
		else
		{
			ll mod = (1ll << k) / d;
			x = (x * len / d % mod + mod) % mod;
			printf("%lld\n",x);
		}
	}
	return 0;
}