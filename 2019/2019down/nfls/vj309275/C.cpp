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
	#define debug prllf
#else
	#define debug(...)
#endif
const ll maxn = 2005;
const ll inf = 1e9 + 7;
ll A[maxn][maxn];
ll t,n;
ll dis[maxn],vis[maxn],enter_cnt[maxn];
ll dijkstra(ll index,ll des)
{
	memset(dis,inf,sizeof(dis));
	memset(vis,0x00,sizeof(dis));
	for(ll i = 1;i <= n; ++i)
	{
		dis[i] = A[index][i];
	}
	vis[index] = 1;
	ll pos = 0;
	for(ll i = 1;i <= n; ++i)
	{
		ll minx = inf;
		for(ll j = 1;j <= n; ++j)
		{
			if(!vis[j] && minx > dis[j])
			{
				minx = dis[j];
				pos = j;
			}
		}
		vis[pos] = 1;
		for(ll j = 1;j <= n; ++j)
		{
			if(!vis[j] && dis[j] > minx + A[pos][j])
			{
				dis[j] = minx + A[pos][j];
			}
		}
	}
	return dis[des];
}
int main(int argc, char const *argv[])
{
	cin>>t>>n;
	memset(A,inf,sizeof(A));
	for(ll i = 0;i < t; ++i)
	{
		ll x,y,d;
		scanf("%lld%lld%lld",&x,&y,&d);
		A[x][y] = min(A[x][y],d);//可能有多条路
		A[y][x] = min(A[y][x],d);
	}
	cout<<dijkstra(n,1)<<endl;
	return 0;
}