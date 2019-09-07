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
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1e4 + 5;
int n,m,k,pp;
vector< pair<int,int> > G[maxn];
int vis[maxn];
int ans;
void dfs(int p,int dep,int val)
{
	if(dep == k)
	{
		ans = max(ans,val);
		return;
	}
	if(val + (k - dep) * pp <= ans)
	{
		return;
	}
	vis[p] = 1;
	for(int i = 0;i < G[p].size(); ++i)
	{
		int u = G[p][i].first;
		if(!vis[u])
		{
			dfs(u,dep + 1,val + G[p][i].second);
		}
	}
	vis[p] = 0;
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		pp = 0;
		ans = -1;
		cin>>n>>m>>k;
		for(int i = 1;i <= n; ++i)
		{
			G[i].clear();
		}
		for(int i = 1;i <= m; ++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			G[x].push_back(make_pair(y,z));
			G[y].push_back(make_pair(x,z));
			pp = max(pp,z);
		}
		for(int i = 1;i <= n; ++i)
		{
			dfs(i,1,0);
		}
		if(ans == -1)
		{
			printf("impossible\n");
		}
		else
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}