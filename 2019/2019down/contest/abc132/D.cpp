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
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll maxn = 2005;
const ll mod = 1e9 + 7;
ll c[maxn][maxn];
ll pre()
{
	for(int i = 0;i < maxn; ++i)
	{
		c[0][i] = 0;
		c[i][0] = 1;
	}
	for(int i = 1;i < maxn; ++i)
	{
		for(int j = 1;j < maxn; ++j)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}
int main(int argc, char const *argv[])
{
	pre();
	ll n,k;
	cin>>n>>k;
	ll r = n - k,b = k;
	for(ll i = 1;i <= k; ++i)
	{
		printf("%lld\n",c[r + 1][i] * c[b - 1][i - 1] % mod);
	}
	return 0;
}