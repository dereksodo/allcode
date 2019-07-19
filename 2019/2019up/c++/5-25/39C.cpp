#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 2005;
map<ll,ll> mp;
pair<ll,ll> p[maxn];
vector<ll> v[maxn];
ll vis[maxn][maxn] = {-1};
ll dp[maxn][maxn] = {-1};
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
	if(a.second == b.second)
	{
		return a.first > b.first;
	}
	return a.second < b.second;
}
int dfs(int index,int path)
{
	if()
}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	for(ll i = 0;i < n; ++i)
	{
		ll centre,r;
		cin>>centre>>r;
		p[i].first = centre - r;
		p[i].second = centre + r;
	}
	sort(p,p + n);
	for(int i = 0;i < n; ++i)
	{
		v[p[i].second].push_back(i);
	}
	for(int i = 0;i < n; ++i)
	{
		vis[p[i].first][p[i].second] = i;
	}
	ll ans = dfs(0,)
	return 0;
}