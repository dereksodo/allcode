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
const int maxn = 100005;
ll st[maxn],c[maxn];
int main(int argc, char const *argv[])
{
	for(int i = 0;i < maxn; ++i)
	{
		c[i] = 1;
	}
	ll n,mod;
	scanf("%lld%lld",&n,&mod);
	for(int i = 2;i <= n; ++i)
	{
		for(int j = 0;j <= n;j += i)
		{
			for(int k = 0;j + k <= n; ++k)
			{
				(st[k + j] += c[k]) %= mod;
			}
		}
		for(int j = 0;j <= n; ++j)
		{
			c[j] = st[j];
			st[j] = 0;
		}
	}
	printf("%lld\n",c[n]);
	return 0;
}