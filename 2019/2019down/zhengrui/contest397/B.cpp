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
const ll maxn = 100005;
ll sum[maxn];
ll vis[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	sum[0] = 0;
	ll x;
	ll ans = 0;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&x);
		sum[i] = sum[i - 1] + (i - vis[x]);
		vis[x] = i;
		ans += sum[i];
	}
	printf("%lld\n",ans);
	return 0;
}