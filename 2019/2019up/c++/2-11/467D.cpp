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
string str[maxn];
bool vis[maxn];
ll cnt[maxn],r[maxn];
ll n,m;
string check(string s)
{
	for(ll i = 0;i < s.size(); ++i)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}
ll check2(string s)
{
	ll now = 0;
	for(char i : s)
	{
		now += (i == 'r');
	}
	return now;
}
map<string,ll> mp;
map<ll,string> rev;
struct ii{
	ll index;
	ll size;
	ll rCount;
	bool operator <(const ii &a)const
	{
		if(a.rCount == rCount)
		{
			return a.size > size;
		}
		return a.rCount > rCount;
	}
	void prll()
	{
		debug("index = %lld,size = %lld,rCount = %lld,s = %s\n",index,size,rCount,rev[index].c_str());
	}
};
vector<ll> G[maxn];
void dfs(ll now,ll sz,ll R)
{
	if(r[now] >= R)
	{
		vis[now] = 1;
		r[now] = R;
		cnt[now] = sz;
		debug("vis[%lld] = 1,cnt[%lld] = %lld,r[%lld] = %lld\n",now,now,cnt[now],now,r[now]);
		for(ll i : G[now])
		{
			if(!vis[i])
			{
				dfs(i,sz,R);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	// freopen("test.txt","r",stdin);
	cin>>m;
	cin.get();
	ll now = 1;
	for(ll i = 1;i <= m; ++i)
	{
		cin>>str[i];
		str[i] = check(str[i]);
		if(mp[str[i]] == 0)
		{
			mp[str[i]] = now;
			rev[now++] = str[i];
		}
		r[mp[str[i]]] = check2(str[i]);
		cnt[mp[str[i]]] = ll(str[i].size());
		debug("mp[%s] = %d\n",str[i].c_str(),mp[str[i]]);
		debug("r[%lld] = %lld,cnt[%lld] = %lld\n",i,r[i],i,cnt[i]);
	}
	cin>>n;
	cin.get();
	priority_queue<ii> pq;
	ll now2 = now;
	for(ll i = 0;i < n; ++i)
	{
		string a,b;
		cin>>a>>b;
		string na = check(a);
		string nb = check(b);
		ll as = check2(nb);
		debug("check2(%s) = %lld\n",nb.c_str(),as);
		debug("na = %s\n",na.c_str());
		if(mp[na] != 0)
		{
			if(mp[nb] == 0)
			{
				mp[nb] = now2;
				rev[now2++] = nb;
			}
			G[mp[nb]].push_back(mp[na]);
			// debug("*******\n");
			// cout<<nb<<endl;
			// cout<<nb.size()<<endl;
			// debug("*******\n");
			ii temp;
			temp.index = mp[nb];
			temp.size = ll(nb.size());
			temp.rCount = as;
			pq.push(temp);
		}
	}
	// for(ll i = 1;i <= now; ++i)
	// {
	// 	debug("mp[%s] = %lld\n",rev[i].c_str(),i);
	// }
	while(!pq.empty())
	{
		auto la = pq.top();
		pq.pop();
		if(vis[la.index])
		{
			continue;
		}
		la.prll();
		dfs(la.index,la.size,la.rCount);
	}
	ll ansr = 0,ans = 0;
	debug("now = %lld\n",now);
	for(ll i = 1;i < now; ++i)
	{
		ansr += r[i];
		ans += cnt[i];
	}
	printf("%lld %lld\n",ansr,ans);
	return 0;
}