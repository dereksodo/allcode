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
const int maxn = 2e5 + 5;
ll a[maxn];
ll mp[maxn];
ll c(ll n)
{
	return (n * (n - 1)) >> 1;
}
int main(int argc, char const *argv[])
{
	ll n;
	scanf("%lld",&n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
		mp[a[i]]++;
	}
	ll ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		ans += c(mp[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		printf("%lld\n",ans - c(mp[a[i]]) + c(mp[a[i]] - 1));
	}
	return 0;
}