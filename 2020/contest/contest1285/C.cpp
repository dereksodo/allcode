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
	ll x,ans = 0;
	cin>>x;
	for(ll i = 1;i * i <= x; ++i)
	{
		if(x % i == 0 && lcm(i,x / i) == x)
		{
			ans = i;
		}
	}
	printf("%lld %lld\n",ans,x / ans);
	return 0;
}