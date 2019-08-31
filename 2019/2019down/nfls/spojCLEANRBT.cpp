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
const int maxn = 25;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
struct node{
	int x,y,dis;
	node(int xx = 0,int yy = 0,int diss = 0)
	{
		x = xx,y = yy,dis = diss;
	}
};
int Cnt;
char mp[maxn][maxn];
int hash_[(maxn + 5) * (maxn + 5)];
int dis[maxn][maxn];
int vis[maxn][maxn];
int n,m;
int h(node ap)
{
	return ap.x * 21 + ap.y;
}
int check(int x,int y)
{
	return x > 0 && x <= n && y > 0 && y <= m && mp[x][y] != 'x' && !vis[x][y];
}
int ans,p_min;
void bfs(node p)
{
	memset(vis,0x00,sizeof(vis));
	queue<node> q;
	q.push(p);
	vis[p.x][p.y] = 1;
	while(!q.empty())
	{
		node a = q.front();
		q.pop();
		if(mp[a.x][a.y] == '*' || mp[a.x][a.y] == 'o')
		{
			dis[hash_[h(p)]][hash_[h(a)]] = a.dis;
			p_min = min(p_min,a.dis);
		}
		for(int i = 0;i < 4; ++i)
		{
			int nx = a.x + dx[i];
			int ny = a.y + dy[i];
			if(check(nx,ny))
			{
				vis[nx][ny] = 1;
				q.push(node(nx,ny,a.dis + 1));
			}
		}
	}
}
void dfs(int x,int p,int ok,vector<int> path)
{
	if(ok == Cnt)
	{
		ans = min(ans,p);
		return;
	}
	if((Cnt - ok) * p_min + p >= ans)
	{
		return;
	}
	for(int i = 0;i < Cnt; ++i)
	{
		if(!vis[i][0] && dis[i][x] != -1)
		{
			vis[i][0] = 1;
			path.push_back(i);
			dfs(i,p + dis[i][x],ok + 1,path);
			path.pop_back();
			vis[i][0] = 0;
		}
	}
}
int main(int argc, char const *argv[])
{
	while(cin>>n>>m && n)
	{
		swap(n,m);
		Cnt = 0;
		memset(hash_,0x00,sizeof(hash_));
		int beg;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%s",mp[i] + 1);
			for(int j = 1;j <= m; ++j)
			{
				if(mp[i][j] == '*' || mp[i][j] == 'o')
				{
					if(mp[i][j] == 'o')
					{
						beg = Cnt;
					}
					hash_[h(node(i,j,0))] = Cnt++;
				}
			}
		}
		memset(dis,-1,sizeof(dis));
		ans = 0x3f3f3f3f;
		p_min = 0x3f3f3f3f;
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= m; ++j)
			{
				if(mp[i][j] == 'o' || mp[i][j] == '*')
				{
					bfs(node(i,j,0));
				}
			}
		}
		// for(int i = 0;i < Cnt; ++i)
		// {
		// 	for(int j = 0;j < Cnt; ++j)
		// 	{
		// 		debug("%d ",dis[i][j]);
		// 	}
		// 	debug("\n");
		// }
		memset(vis,0x00,sizeof(vis));
		vector<int> ala;
		ala.clear();
		ala.push_back(beg);
		vis[beg][0] = 1;
		// debug("beg = %d\n",beg);
		dfs(beg,0,1,ala);
		if(ans == 0x3f3f3f3f)
		{
			ans = -1;
		}
		printf("%d\n",ans);
	}
	return 0;
}