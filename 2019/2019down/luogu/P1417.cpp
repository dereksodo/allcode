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
const int maxn = 100005;
struct nod{
	ll a,b,c;
	bool operator <(const nod &d)const
	{
		return c * d.b < d.c * b;
	}
}node[maxn];
ll dp[maxn];
int main(int argc, char const *argv[])
{
	ll n,T;
	cin>>T>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&node[i].a);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&node[i].b);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&node[i].c);
	}
	sort(node + 1,node + n + 1);
	ll ans = 0;
	for(ll i = 1;i <= n; ++i)
	{
		for(ll j = T;j >= node[i].c; --j)
		{
			dp[j] = max(dp[j],dp[j - node[i].c] + node[i].a - j * node[i].b);
			ans = max(ans,dp[j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}