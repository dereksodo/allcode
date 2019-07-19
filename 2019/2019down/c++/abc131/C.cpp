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
ll getnum(ll a,ll c)
{
	ll ret = a / c;
	if(ret * c == a)
	{
		return ret;
	}
	return ret + 1;
}
ll getnum2(ll a,ll c)
{
	ll ret = a / c;
	return ret;
}
ll gcd(ll a,ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b,a % b);
}
ll lcm(ll a,ll b)
{
	return a / gcd(a,b) * b;
}
int main(int argc, char const *argv[])
{
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll af = getnum(a,c);
	ll as = getnum(a,d);
	ll bf = getnum2(b,c);
	ll bs = getnum2(b,d);
	debug("af = %lld,as = %lld,bf = %lld,bs = %lld\n",af,as,bf,bs);
	ll ans1 = bf - af + 1 + bs - as + 1;
	ll p = lcm(c,d);
	debug("p = %lld\n",p);
	ll pf = getnum(a,p);
	ll ps = getnum2(b,p);
	ll ans2 = ps - pf + 1;
	debug("pf = %lld,ps = %lld,ans2 = %lld\n",pf,ps,ans2);
	ans1 -= ans2;
	printf("%lld\n",b - a + 1 - ans1);
	return 0;
}