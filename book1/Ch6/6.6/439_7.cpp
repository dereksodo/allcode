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
const int mod = 2333;
const int maxn = 2350;
int c[maxn][maxn];
int f(ll n,ll k)
{
	if(n < mod)
	{
		return c[n][min(n,k)];
	}
	if(!k)
	{
		return 1;
	}
	int ret = 0,x = k % mod,y = n % mod;
	ret = c[y][min(y,x)] * f(n / mod,k / mod);
	if(k - x)
	{
		ret = (ret + (c[y][y] - c[y][min(y,x)] + mod) * (f(n / mod,(k - x - 1) / mod))) % mod;
	}
	return ret;
}
ll n,k;
int main(int argc, char const *argv[])
{
	for(int i = 0;i < maxn; ++i)
	{
		c[i][0] = 1;
	}
	for(int i = 1;i < maxn; ++i)
	{
		for(int j = 1;j <= i; ++j)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
	for(int i = 0;i < maxn; ++i)
	{
		for(int j = 1;j <= i; ++j)
		{
			c[i][j] = (c[i][j] + c[i][j - 1]) % mod;
		}
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		printf("%d\n",f(n,k));
	}
	return 0;
}