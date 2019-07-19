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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
map<ll,ll> mp,mp2;
set<ll> v;
int main(int argc, char const *argv[])
{
	ll q;
	cin>>q;
	while(q--)
	{
		ll n;
		cin>>n;
		ll x;
		mp.clear();
		v.clear();
		mp2.clear();
		priority_queue< pair<ll,ll> > p;
		ll maxp = 0;
		for(ll i = 0;i < n; ++i)
		{
			scanf("%lld",&x);
			v.insert(x);
			mp[x]++;
			maxp = max(maxp,mp[x]);
		}
		for(auto iter = mp.begin();iter != mp.end(); ++iter)
		{
			debug("%lld %lld\n",iter->first,iter->second);
			p.push({iter->second,iter->first});
		}
		ll ans = 0ll;
		ll now = maxp;
		while(!p.empty() && now)
		{
			pair<ll,ll> cur = p.top();
			p.pop();
			ans += min(cur.first,now);
			now--;
			now = min(now,cur.first - 1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}