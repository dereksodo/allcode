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
const ll maxn = 2e5 + 5;
map<ll,int> edpt;
ll vis[maxn],cnt;
ll n,m;
ll findmx_pos(ll a)
{
	return lower_bound(vis,vis + cnt,a) - vis;
}
ll check(ll mid)
{
	// printf("mid = %lld\n",mid);
	ll last = vis[findmx_pos(-1)],surplus = n - 1;
	while(surplus--)
	{
		ll pos = findmx_pos(last + mid);
		// printf("pos = %lld\n",pos);
		if(pos == cnt)
		{
			return 0;
		}
		ll nxt = vis[pos];
		if(edpt[nxt] == -1)
		{
			last = nxt;
		}
		else
		{
			last += mid;
		}
		if(last > vis[cnt - 1])
		{
			return 0;
		}
		// printf("last = %lld\n",last);
	}
	// printf("surplus = %lld\n",surplus);
	return 1;
}
int main(int argc, char const *argv[])
{
	freopen("socdist.in","r",stdin);
	freopen("socdist.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 0,x,y;i < m; ++i)
	{
		scanf("%lld%lld",&x,&y);
		edpt[x] = -1,edpt[y] = 1;
		vis[cnt++] = x;
		vis[cnt++] = y;
	}
	sort(vis,vis + cnt);
	ll l = 0,r = 1e18;
	// printf("r = %lld\n",r);
	while(l < r)
	{
		ll mid = l + ((r - l + 1) >> 1);
		// printf("mid = %lld\n",mid);
		if(check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
		// printf("l = %lld,r = %lld\n",l,r);
		// printf("\n");
	}
	printf("%lld\n",l);
	return 0;
}