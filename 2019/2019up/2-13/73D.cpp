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
ll n,m,k;
const ll maxn = 1e6 + 6;
vector<ll> G[maxn];
bool vis[maxn];
ll d[maxn];
ll dfs(ll u)
{
	ll res = 1;
	vis[u] = 1;
	for(int j : G[u])
	{
		if(!vis[j])
		{
			res += dfs(j);
		}
	}
	return res;
}
multiset<ll> s;
int main(int argc, char const *argv[])
{
	cin>>n>>m>>k;
	for(int i = 0;i < m; ++i)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		x--,y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	ll dCount = 0;
	for(ll i = 0;i < n; ++i)
	{
		if(!vis[i])
		{
			d[dCount++] = dfs(i);
		}
	}
	sort(d,d + dCount);
	reverse(d,d + dCount);
	ll total = 0;
	for(int i = 0;i < dCount; ++i)
	{
		if(d[i] > k)
		{
			d[i] = k;
		}
		total += d[i];
		s.insert(d[i]);
	}
	for(int i = 0;; ++i)
	{
		if(total >= 2 * (s.size() - 1))
		{
			cout<<i<<endl;
			return 0;
		}
		ll a = *s.begin();
		s.erase(s.begin());
		ll b = *s.begin();
		s.erase(s.begin());
		total = total - a - b + min(a + b,k);
		s.insert(min(a + b,k));
	}
	return 0;
}