#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> sm[105];
vector<int> cycle,cur;
bool inc[105],vis[105];
int n,m;
#define coutx printf("NO\n"); exit(0)
int dfsc(int v)
{
	if(vis[v])
	{
		return 0;
	}
	vis[v] = 1;
	int ans = 1;
	for(int i = 0;i < sm[v].size(); ++i)
	{
		ans += dfsc(sm[v][i]);
	}
	return ans;
}
bool dfs(int v,int pr)
{
	cur.push_back(v);
	vis[v] = -1;
	for(int i = 0;i < sm[v].size(); ++i)
	{
		if(sm[v][i]== pr)
		{
			continue;
		}
		if(vis[sm[v][i]])
		{
			while(cur.back() != sm[v][i])
			{
				cycle.push_back(cur.back());
				cur.pop_back();
			}
			cycle.push_back(cur.back());
			return 1;
		}
		if(dfs(sm[v][i],v))
		{
			return 1;
		}
	}
	cur.pop_back();
	return 0;
}
bool dfs2(int v,int pr)
{
	if(vis[v])
	{
		return 1;
	}
	vis[v] = 1;
	for(int i = 0;i < sm[v].size(); ++i)
	{
		int x = sm[v][i];
		if(x == pr)
		{
			continue;
		}
		if(!inc[v] && inc[x])
		{
			return 0;
		}
		if(inc[x])
		{
			continue;
		}
		if(vis[x])
		{
			return 0;
		}
		if(!dfs2(x,v))
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	cin>>n>>m;
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		sm[x].push_back(y);
		sm[y].push_back(x);
	}
	if(n != m)
	{
		coutx;
	}
	if(dfsc(0) != n)
	{
		coutx;
	}
	memset(vis,0x00,sizeof(vis));
	if(!dfs(0,-1))
	{
		coutx;
	}
	memset(vis,0x00,sizeof(vis));
	for(int i = 0;i < cycle.size(); ++i)
	{
		inc[cycle[i]] = 1;
	}
	for(int i = 0;i < cycle.size(); ++i)
	{
		if(!dfs2(cycle[i],-1))
		{
			coutx;
		}
	}
	printf("FHTAGN!\n");
	return 0;
}