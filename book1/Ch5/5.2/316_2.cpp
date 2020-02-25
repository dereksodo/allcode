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
const int maxn = 2e5 + 5;
int d1[maxn],d2[maxn],ans,res;
int head[maxn],nxt[maxn << 1],to[maxn << 1],tot;
int vis[maxn];
set<int> s;
void addedge(int u,int v)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}
void dfs(int u,int fa)
{
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa)
		{
			continue;
		}
		dfs(v,u);
		if(d1[v] >= d1[u])
		{
			d2[u] = d1[u];
			d1[u] = d1[v] + 1;
		}
		else if(d1[v] >= d2[u])
		{
			d2[u] = d1[v] + 1;
		}
	}
}
void dfs2(int u,int fa)
{
	s.insert(u);
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(u == fa)
		{
			if((d1[v] == d1[u] - 1) || (d1[v] == d2[u] - 1))
			{
				dfs2(v,fa);
			}
		}
		else
		{
			if(d1[v] == d1[u] - 1)
			{
				dfs2(v,fa);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1,u,v;i < n; ++i)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		vis[v] = 1;
	}
	int rt = 0;
	while(vis[rt])
	{
		++rt;
	}
	dfs(rt,-1);
	int ans = 0;
	vector<int> v;
	for(int i = 0;i < n; ++i)
	{
		if(d1[i] + d2[i] > ans)
		{
			v.clear();
			v.push_back(i);
			ans = d1[i] + d2[i];
		}
		else if(d1[i] + d2[i] == ans)
		{
			v.push_back(i);
		}
	}
	for(int i = 0;i < v.size(); ++i)
	{
		dfs2(v[i],v[i]);
	}
	for(set<int>::iterator it = s.begin();it != s.end(); ++it)
	{
		printf("%d\n",*it);
	}
	return 0;
}