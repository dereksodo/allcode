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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll maxn = 1005;
ll a[maxn],b[maxn];
ll gcd(ll x,ll y)
{
	return y == 0 ? x : gcd(y,x % y);
}
const int maxm = 1e6;
int vis[maxm],prime[maxm],plen;
void init()
{
	for(int i = 2;i < maxm; ++i)
	{
		if(!vis[i])
		{
			prime[++plen] = i;
		}
		for(int j = 1;j <= plen && i * prime[j] < maxm; ++j)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
vector<ll> po;
void getx(ll x)
{
	for(int i = 1;i <= plen; ++i)
	{
		if(x % prime[i] == 0)
		{
			po.push_back(prime[i]);
			while(x % prime[i] == 0)
			{
				x /= prime[i];
			}
		}
	}
	if(x != 1)
	{
		po.push_back(x);
	}
}
const int base = 16;
typedef vector<int> lnum;
lnum zh(ll x)
{
	lnum ret;
	ret.clear();
	while(x)
	{
		ret.push_back(x % base);
		x /= base;
	}
	return ret;
}
lnum operator *(const lnum &a,const lnum &b)
{
	lnum c;
	c.assign(a.size() + b.size(),0);
	for(int i = 0;i < a.size(); ++i)
	{
		int carry = 0;
		for(int j = 0;j < b.size() || carry; ++j)
		{
			int bj = (j >= b.size() ? 0 : b[j]);
			c[i + j] += a[i] * bj + carry;
			carry = c[i + j] / base;
			c[i + j] %= base;
		}
	}
	while(c.back() == 0 && !c.empty())
	{
		c.pop_back();
	}
	return c;
}
void print(lnum x)
{
	for(int i = x.size() - 1;i >= 0; --i)
	{
		printf("%X",x[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	init();
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		b[i] /= gcd(a[i],b[i]);
		getx(b[i]);
	}

	sort(po.begin(),po.end());
	// for(int i = 0;i < po.size(); ++i)
	// {
	// 	debug("%d ",po[i]);
	// }
	// debug("\n");

	lnum ans = zh(1ll);
	for(int i = 0;i < po.size(); ++i)
	{
		if((i == 0) || (po[i] != po[i - 1]))
		{
			ans = ans * zh(po[i]);
		}
	}
	print(ans);
	return 0;
}