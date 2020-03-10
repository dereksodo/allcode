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
struct bint{
	int a[2100],len;
	bint(){memset(a,0x00,sizeof(a)),len = 0;}
};
bint operator *(bint a,ll x)
{
	bint ret;
	ret.len = a.len;
	for(int i = 1;i <= a.len; ++i)
	{
		ret.a[i] = a.a[i] * x;
	}
	for(int i = 1;i <= ret.len; ++i)
	{
		ret.a[i + 1] += ret.a[i] / 10;
		ret.a[i] %= 10;
	}
	int i = ret.len;
	while(ret.a[i + 1] > 0)
	{
		++i;
		ret.a[i + 1] += ret.a[i] / 10;
		ret.a[i] %= 10;
	}
	while(ret.a[i] == 0 && i > 1)
	{
		--i;
	}
	ret.len = i;
	return ret;
}
bint operator /(bint a,ll b)
{
	ll s = 0;
	bint ret;
	for(int i = a.len;i >= 1; --i)
	{
		s = s * 10 + a.a[i];
		ret.a[i] = s / b;
		s %= b;
	}
	int i = a.len;
	while(i > 1 && ret.a[i] == 0)
	{
		--i;
	}
	ret.len = i;
	return ret;
}
ll mypow(ll a,ll b,ll mod)
{
	ll ans = 1;
	for(;b;b >>= 1,a = a * a % mod)
	{
		if(b & 1)
		{
			(ans *= a) %= mod;
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	ll n,m,a,b;
	scanf("%lld%lld",&a,&b);
	n = mypow(b,b,1000) - 1;
	m = a - 1;
	bint ret;
	ret.a[1] = 1;
	ret.len = 1;
	for(ll i = n;i >= n - m + 1; --i)
	{
		ret = ret * i;
	}
	for(ll i = 2;i <= m; ++i)
	{
		ret = ret / i;
	}
	for(int i = ret.len;i >= 1; --i)
	{
		printf("%d",ret.a[i]);
	}
	printf("\n");
	return 0;
}