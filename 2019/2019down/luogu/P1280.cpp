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
const ll maxn = 10005;
struct nod{
	ll bt,et;
	nod(ll a = 0,ll b = 0)
	{
		bt = a,et = b;
	}
	bool operator <(const nod &b)const
	{
		return bt > b.bt;
	}
};
nod node[maxn];
map<ll,ll> mp;
ll dp[maxn];
int main(int argc, char const *argv[])
{
	ll n,k;
	cin>>n>>k;
	for(ll i = 1;i <= k; ++i)
	{
		scanf("%lld%lld",&node[i].bt,&node[i].et);
		mp[node[i].bt]++;
	}
	sort(node + 1,node + k + 1);
	ll now = 1;
	for(ll i = n;i >= 1; --i)
	{
		if(!mp[i])
		{
			dp[i] = dp[i + 1] + 1;
		}
		else
		{
			for(ll j = 1;j <= mp[i]; ++j)
			{
				if(dp[i + node[now].et] > dp[i])
				{
					dp[i] = dp[i + node[now].et];
				}
				++now;
			}
		}
	}
	printf("%lld\n",dp[1]);
	return 0;
}