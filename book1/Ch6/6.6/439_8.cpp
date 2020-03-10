//can't solve this problem
//other's code
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
ll w[7];
void exgcd(ll a,ll b,ll &x,ll &y)
{
	b ? (exgcd(b,a % b,y,x),y -= a / b * x) : (x = 1,y = 0);
}
ll inv(ll a,ll p)
{
	ll x,y;
	exgcd(a,p,x,y);
	return (x + p) % p;
}
ll mypow(ll a,ll b,ll p)
{
	ll ret = 1;
	for(;b;b >>= 1,a = a * a % p)
	{
		if(b & 1)
		{
			ret = ret * a % p;
		}
	}
	return ret;
}
ll f(ll a,ll p,ll k)
{
	if(!a)
	{
		return 1;
	}
	ll i,u = 1,v = 1;
	for(i = 1;i < k; ++i)
	{
		if(i % p)
		{
			u = i * u % k;
		}
	}
	for(i = a / k * k;i <= a; ++i)
	{
		if(i % p)
		{
			v = i % k * v % k;
		}
	}
	return f(a / p,p,k) * mypow(u,a / k,k) % k * v % k;
}
ll g(ll a,ll p)
{
	return a < p ? 0 : g(a / p,p) + a / p;
}
ll h(ll a,ll b,ll p,ll k)
{
	return f(a,p,k) * inv(f(b,p,k),k) % k * inv(f(a - b,p,k),k) % k * mypow(p,g(a,p) - g(b,p) - g(a - b,p),k) % k;
}
ll exlucas(ll a,ll b,ll p)
{
	ll i,j,k,l,s = 0;
	for(i = 2,j = p;i * i <= j; ++i)
	{
		if(j % i)
		{
			continue;
		}
		for(k = i,j /= i;!(j % i);k *= i)
		{
			j /= i;
		}
		l = p / k,s = (s + l * h(a,b,i,k) % p * inv(l,k)) % p;
	}
	if(j > 1)
	{
		l = p / j,s = (s + l * h(a,b,j,j) % p * inv(l,j)) % p;
	}
	return s;
}
int main(int argc, char const *argv[])
{
	ll p,n,m,i,s = 0;
	scanf("%lld%lld%lld",&p,&n,&m);
	for(i = 0;i < m; ++i)
	{
		scanf("%lld",w + i);
		s += w[i];
	}
	if(s > n)
	{
		printf("Impossible\n");
		return 0;
	}
	for(i = 0,s = 1;i < m; ++i)
	{
		s = s * exlucas(n,w[i],p) % p;
		n -= w[i];
	}
	printf("%lld\n",s);
	return 0;
}