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
const ll maxn = 405;
char in[maxn][maxn];
int vis[maxn][maxn];
ll n,m;
const ll dx[] = {0,1};
const ll dy[] = {1,0};
bool ok(ll nx,ll ny)
{
	return nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny];
}
ll dfs(ll x,ll y,ll wc,ll bc)
{
	printf("wc = %lld,bc = %lld\n",wc,bc);
	if(vis[x][y])
	{
		return 0;
	}
	ll ret = 0;
	vis[x][y] = 1;
	for(ll i = 0;i < 2; ++i)
	{
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		if(!ok(nx,ny))
		{
			continue;
		}
		if(in[nx][ny] != in[x][y])
		{
			if(in[nx][ny] == '.')
			{
				wc++;
				ret += bc;
			}
			else
			{
				bc++;
				ret += wc;
			}
			ret += dfs(nx,ny,wc,bc);
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(ll i = 0;i < n; ++i)
	{
		scanf("%s",&in[i]);
	}
	ll ans = 0;
	for(ll i = 0;i < n; ++i)
	{
		for(ll j = 0;j < m; ++j)
		{
			if(vis[i][j])
			{
				continue;
			}
			ans += dfs(i,j,in[i][j] == '.',in[i][j] == '#');
			printf("\n");
		}
	}
	printf("%lld\n",ans);
	return 0;
}