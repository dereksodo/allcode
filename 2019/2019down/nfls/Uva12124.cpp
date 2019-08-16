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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const ll maxn = 1005;
ll n,k,cnt;
vector< pair<ll,ll> > pp[maxn];
map<string,ll> mp;
vector<ll> p[maxn],q[maxn];
ll check(ll mid)
{
	ll res = 0;
	for(ll i = 1;i <= cnt; ++i)
	{
		ll ret = k + 1;
		for(int j = 0;j < pp[i].size(); ++j)
		{
			if(pp[i][j].second >= mid)
			{
				ret = min(pp[i][j].first,ret);
			}
		}
		if(ret != k + 1)
		{
			res += ret;
		}
		else
		{
			return 0;
		}
	}
	return res <= k;
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		mp.clear();
		cnt = 0;
		for(ll i = 1;i <= n; ++i)
		{
			string s1,s2;
			ll p1,q1;
			cin>>s1>>s2>>p1>>q1;
			if(mp[s1])
			{
				pp[mp[s1]].push_back(make_pair(p1,q1));
			}
			else
			{
				mp[s1] = ++cnt;
				pp[mp[s1]].clear();
				pp[mp[s1]].push_back(make_pair(p1,q1));
			}
		}
		for(ll i = 1;i <= cnt; ++i)
		{
			sort(pp[i].begin(),pp[i].end());
			p[i].clear();
			q[i].clear();
			for(ll j = 0;j < pp[i].size(); ++j)
			{
				// printf("%lld %lld\n",pp[i][j].first,pp[i][j].second);
				p[i].push_back(pp[i][j].first);
				q[i].push_back(pp[i][j].second);
			}
		}
		ll l = 0,r = 1e18,ans = 0;
		while(l <= r)
		{
			ll mid = l + r >> 1;
			if(check(mid))
			{
				ans = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
			// printf("l = %lld,r = %lld\n",l,r);
		}
		printf("%lld\n",ans);
	}
	return 0;
}