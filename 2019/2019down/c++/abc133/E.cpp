#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
vector<ll> G[maxn];
ll ans = 1;
const ll mod = 1e9 + 7;
ll n,k;
void dfs(ll cur,ll pre,ll col)
{
	ans = ans * col % mod;
	col = k - 1;
	if(pre != -1)
	{
		col--;
	}
	for(int i = 0;i < G[cur].size(); ++i)
	{
		int u = G[cur][i];
		if(u != pre)
		{
			dfs(u,cur,col);
			col--;
		}
	}
}
int main()
{
	cin>>n>>k;
	for(ll i = 0;i < n - 1; ++i)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		x--,y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(0,-1,k);
	cout<<ans<<endl;
	return 0;
}
