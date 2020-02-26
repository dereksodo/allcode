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
const int mod = 1e9 + 7;
struct node{
	ll num,s,w;
}dp[20][10][10];
ll dig[20],f[20];
node dfs(ll pos,ll m,ll s,ll fg)
{
	if(!pos)
	{
		return (node){m && s,0,0};
	}
	if(!fg && dp[pos][m][s].s)
	{
		return dp[pos][m][s];
	}
	node sum = (node){0,0,0},tmp;
	ll mx = fg ? dig[pos] : 9;
	for(int i = 0;i <= mx; ++i)
	{
		if(i != 7)
		{
			tmp = dfs(pos - 1,(m * 10 + i) % 7,(s + i) % 7,fg && i == mx);
			sum.num = (sum.num + tmp.num) % mod;
			sum.s = (sum.s + tmp.s + f[pos] * i % mod * tmp.num % mod) % mod;
			sum.w = (sum.w + tmp.w + 2 * f[pos] * i % mod * tmp.s % mod) % mod;
			sum.w = (sum.w + f[pos] * f[pos] % mod * i * i % mod * tmp.num % mod) % mod;
		}
	}
	if(!fg)
	{
		dp[pos][m][s] = sum;
	}
	return sum;
}
ll solve(ll x)
{
	ll l = 0;
	while(x)
	{
		dig[++l] = x % 10;
		x /= 10;
	}
	return dfs(l,0,0,1).w;
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	f[1] = 1;
	for(int i = 2;i < 20; ++i)
	{
		f[i] = f[i - 1] * 10 % mod;
	}
	while(T--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",(solve(r) - solve(l - 1) + mod) % mod);
	}
	return 0;
}