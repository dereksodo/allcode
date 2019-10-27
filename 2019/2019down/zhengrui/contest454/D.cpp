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
typedef ll ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll maxn = 3005;
const ll inf = 1e18;
ll n,m;
ll dis[maxn],vis[maxn];
vector< pair<ll,ll> > G[maxn];
struct nodt{
	ll ind;
	ll dist;
	nodt(ll a,ll b):ind(a),dist(b){};
	bool operator <(const nodt &b)const
	{
		return dist > b.dist;
	}
	void print()
	{
		printf("index = %lld,dist = %lld\n",ind,dist);
	}
};
ll Base;
ll dfast(ll index,ll des)
{
	priority_queue<nodt> q;
	for(ll i = 0;i < maxn; ++i)
	{
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[index] = 0;
	q.push(nodt(index,0));
	while(!q.empty())
	{
		nodt u = q.top();
		q.pop();

		ll mi = u.ind;
		if(vis[mi])
		{
			continue;
		}
		vis[mi] = 1;

		for(ll i = 0;i < G[mi].size(); ++i)
		{
			ll v = G[mi][i].first;
			ll value = max(G[mi][i].second - Base,0ll);
			if(!vis[v] && dis[v] > dis[mi] + value)
			{
				dis[v] = dis[mi] + value;
				q.push(nodt(v,dis[v]));
			}
		}
	}
	return dis[des];
}
ll cost[maxn];
int main(int argc, char const *argv[])
{
	ll n,m,k;
	cin>>n>>m>>k;
	for(ll i = 1;i <= m; ++i)
	{
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		cost[i] = z;
		G[x].push_back(make_pair(y,z));
		G[y].push_back(make_pair(x,z));
	}
	Base = 0;
	ll ans = dfast(1,n);
	for(ll i = 1;i <= m; ++i)
	{
		Base = cost[i];
		ans = min(ans,dfast(1,n) + Base * k);
	}
	cout<<ans<<endl;
	return 0;
}