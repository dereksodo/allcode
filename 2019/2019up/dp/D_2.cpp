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
const ll maxn = 1e5 + 5;
const ll maxm = 105;
ll dp[maxn][maxm];
ll weight[maxm],value[maxm],vis[maxm];
ll doit(ll p,ll k)
{
	ll ret = 0;
	for(ll i = 1;i <= k; ++i)
	{
		if(weight[i] <= p && !vis[i])
		{
			vis[i] = 1;
			ret = max(ret,doit(p - weight[i],k) + value[i]);
			vis[i] = 0;
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	ll n,w;
	cin>>n>>w;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld %lld",weight + i,value + i);
	}
	printf("%lld\n",doit(w,n));
	return 0;
}